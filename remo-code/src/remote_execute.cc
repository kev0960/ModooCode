#include "remote_execute.h"

#include <fcntl.h>
#include <linux/seccomp.h>
#include <seccomp.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <experimental/optional>
#include <iostream>

constexpr int kOneMb = 1024 * 1024;
static char kGppName[] = "/usr/bin/g++";
static char kGppReadFromStdin[] = "-x";
static char kGppLanguage[] = "c++";
static char kDash[] = "-";
static char kGppCpp17[] = "-std=c++17";
static char kGppWarningAll[] = "-Wall";
static char kGppWarningExtra[] = "-Wextra";
static char kGppFortify[] = "-D_FORTIFY_SOURCE=2";
static char kGppOutputFlag[] = "-o";
static char kGppOutputFile[] = "./tmp/";
static char kOutputFile[] = "/";
static char kPath[] = "PATH=/usr/bin";

// Max program output : 256 kb.
static const size_t kMaxProgramOutput = 256 * 1024;

// Instructions
//
// 1) Mount tmp directory as tmpfs;
// sudo mount -t tmpfs -o size=16m tmpfs ./tmp
//
// 2) Make sure to mark all the directories as rx permission.
//
// 3) Need to bring some libc/libstdc++ libraries to the tmp directory as the
// processes are run under chroot jail. We have to make sure that they can find
// required shared libraries from the chroot jail. We also have to set the those
// libraries with rx permission to prevent possible sabotage.
//
namespace remo_code {
namespace {

void WeakProcessLimit() {
  // Restrict the amount of CPU time for the compilation.
  const struct rlimit cpu_limit = {10, 10};
  setrlimit(RLIMIT_CPU, &cpu_limit);

  // Restrict the virtual memory size.
  const struct rlimit mem_limit = {128 * kOneMb, 128 * kOneMb};
  setrlimit(RLIMIT_AS, &mem_limit);

  // Restrict the output file size.
  const struct rlimit fs_limit = {2 * kOneMb, 2 * kOneMb};
  setrlimit(RLIMIT_FSIZE, &fs_limit);
}

void StrictProcessLimit() {
  // Restrict the amount of CPU time for the compilation.
  const struct rlimit cpu_limit = {5, 5};
  setrlimit(RLIMIT_CPU, &cpu_limit);

  // Restrict the virtual memory size.
  const struct rlimit mem_limit = {128 * kOneMb, 128 * kOneMb};
  setrlimit(RLIMIT_AS, &mem_limit);

  // Restrict the data segment size.
  const struct rlimit data_seg_limit = {64 * kOneMb, 64 * kOneMb};
  setrlimit(RLIMIT_AS, &data_seg_limit);

  // Restrict the output file size.
  const struct rlimit fs_limit = {0 * kOneMb, 0 * kOneMb};
  setrlimit(RLIMIT_FSIZE, &fs_limit);

  // Restrict the output file size.
  const struct rlimit fd_limit = {4, 4};
  setrlimit(RLIMIT_NOFILE, &fd_limit);
}

zmq::message_t str_to_zmq_msg(const string& s) {
  zmq::message_t msg(s.size());
  memcpy(msg.data(), s.c_str(), s.size());
  return msg;
}

std::experimental::optional<string> StdinFromCode(string* code,
                                                  const string& id) {
  size_t stdin_end = code->find(id);
  if (stdin_end == string::npos) {
    // Something is wrong.
    return std::experimental::nullopt;
  }
  string std_input = code->substr(0, stdin_end);
  code->erase(0, stdin_end + id.size());
  return std_input;
}

}  // namespace

string RemoteExecuter::SyncCompile(const string& code, int thread_index) {
  int pipe_p2c[2], pipe_c2p[2];
  if (pipe(pipe_p2c) != 0 || pipe(pipe_c2p) != 0) {
    return "Pipe is broken :(";
  }

  auto pid = fork();
  if (pid < 0) {
    // Fork error :(
    return "Something went wrong :(";
  } else if (pid == 0) {
    // We are in the child process.

    // Close write end and link STDIN through the pipe.
    close(pipe_p2c[1]);
    dup2(pipe_p2c[0], STDIN_FILENO);
    dup2(pipe_c2p[1], STDERR_FILENO);
    close(pipe_p2c[0]);

    // Build a output file name.
    char output_file_name[100];
    snprintf(output_file_name, 100, "%s%d", kGppOutputFile, thread_index);

    // Build argv and env for execve.
    char* gpp_argv[] = {kGppName,
                        kGppReadFromStdin,
                        kGppLanguage,
                        kDash,
                        kGppCpp17,
                        kGppWarningAll,
                        kGppWarningExtra,
                        kGppFortify,
                        kGppOutputFlag,
                        output_file_name,
                        NULL};
    char* env[] = {kPath, NULL};

    // Apply weak process limits.
    WeakProcessLimit();

    // Execute the g++.
    int ret = execve(gpp_argv[0], gpp_argv, env);
    return std::to_string(ret);  // Should not be reached if success.
  } else {
    // We are in the parent process.
    close(pipe_p2c[0]);
    close(pipe_c2p[1]);
    // Send the code through the pipe.
    write(pipe_p2c[1], code.c_str(), code.size());
    close(pipe_p2c[1]);

    char buf[1024];
    int read_cnt;
    string compiler_output;
    while ((read_cnt = read(pipe_c2p[0], buf, 1024)) > 0) {
      auto current_size = compiler_output.size();
      compiler_output.reserve(current_size + read_cnt + 1);
      for (int i = 0; i < read_cnt; i++) {
        compiler_output.push_back(buf[i]);
      }
    }
    close(pipe_c2p[0]);

    int status;
    waitpid(pid, &status, 0);  // Wait for the compile to end.
    if (!WIFEXITED(status)) {
      return "Compilation went wrong.. :(";
    }
    // Mark the output file as read only.
    char output_file_name[100];
    snprintf(output_file_name, 100, "%s%d", kGppOutputFile, thread_index);
    chmod(output_file_name, S_IRUSR | S_IXUSR | S_IRGRP | S_IXGRP);
    return compiler_output;
  }
  return "";
}

string RemoteExecuter::SyncExecute(const string& std_input, int thread_index) {
  // Now we have the compiled executable.
  int pipe_p2c[2], pipe_c2p[2];
  if (pipe(pipe_p2c) != 0 || pipe(pipe_c2p) != 0) {
    return "Pipe is broken (during Execution) :(";
  }
  auto pid = fork();

  if (pid < 0) {
    // Fork error :(
    return "Something went wrong :(";
  } else if (pid == 0) {
    // We are in the child process.

    // Build chroot jail. For this, our process must run with root privilige.
    chdir("./tmp");
    if (chroot(".") != 0) {
      std::cout << "Chroot is failed!" << std::endl;
      return "Something went wrong :(";
    }

    // Drop its privlieges.
    if (getuid() == 0) {
      if (setgid(1000) != 0) {
        return "Something went wrong :(";
      }
      if (setuid(1000) != 0) {
        return "Something went wrong :(";
      }
    }

    // Close write end and link STDIN through the pipe.
    close(pipe_p2c[1]);
    dup2(pipe_p2c[0], STDIN_FILENO);
    dup2(pipe_c2p[1], STDOUT_FILENO);
    close(pipe_p2c[0]);

    // Build a output file name.
    char file_to_exec[100];
    snprintf(file_to_exec, 100, "%s%d", kOutputFile, thread_index);

    // Build argv and env for execve.
    char* file_argv[] = {file_to_exec, NULL};

    // Apply strict process limits to prevent abnormal activities.
    StrictProcessLimit();

    // Restrict the possible syscalls (only allow read, write, exit).
    // Also we have to allow execve on itself for once.
    scmp_filter_ctx ctx;

    // Kill the process immediately upon violation.
    ctx = seccomp_init(SCMP_ACT_KILL);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(brk), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munmap), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigprocmask), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(arch_prctl), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(access), 0);

    // Somewhat dangerous syscalls; Only allowed in certain criteria.
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(openat), 1,
                     SCMP_CMP(2, SCMP_CMP_MASKED_EQ, O_RDONLY, O_RDONLY));
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execve), 1,
                     SCMP_A0(SCMP_CMP_EQ, (scmp_datum_t)(file_to_exec)));
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 1,
                     SCMP_CMP(1, SCMP_CMP_MASKED_EQ, O_RDONLY, O_RDONLY));
    seccomp_load(ctx);

    int ret = execvp(file_to_exec, file_argv);
    return std::to_string(ret);  // Should not be reached if success.
  } else {
    // We are in the parent process.
    close(pipe_p2c[0]);
    close(pipe_c2p[1]);

    // Send the input (stdin) through the pipe.
    write(pipe_p2c[1], std_input.c_str(), std_input.size());
    close(pipe_p2c[1]);

    char buf[1024];
    int read_cnt;
    string program_output;
    while ((read_cnt = read(pipe_c2p[0], buf, 1024)) > 0) {
      auto current_size = program_output.size();
      program_output.reserve(current_size + read_cnt + 1);
      for (int i = 0; i < read_cnt; i++) {
        program_output.push_back(buf[i]);
      }
      if (program_output.length() > kMaxProgramOutput) {
        // If the program output exceeds max size, then just kill the process.
        kill(pid, SIGKILL);

        program_output.append("... (too long; omitted) ...");
        break;
      }
    }
    close(pipe_c2p[0]);

    int status;
    waitpid(pid, &status, 0);  // Wait for the compile to end.
    if (!WIFEXITED(status)) {
      return program_output + " 프로그램이 비정상적으로 종료됨 :(";
    }
    return program_output;
  }
  return "";
}

void RemoteExecuter::CodeExecutionThread(int thread_index) {
  while (true) {
    // Wait for the codes.
    std::unique_lock<std::mutex> lock(code_q_lock_);
    cond_code_q_.wait(lock, [this]() { return codes_.size() > 0; });

    // Fetch the first code to execute.
    auto code_info = codes_.front();
    codes_.pop();
    lock.unlock();

    // Notify other threads to wake up since there might be other codes in the
    // queue.
    cond_code_q_.notify_all();

    // Execute the code and save it to the result queue.
    string compile_result = SyncCompile(code_info.code, thread_index);
    string result = code_info.id + ":" + compile_result;

    // If compilation is succeeded, then we execute the program.
    if (compile_result.empty()) {
      string program_output = SyncExecute(code_info.std_input, thread_index);
      result = result + ":" + program_output;
    }

    zmq_sock_mutex_.lock();
    publisher_->send(str_to_zmq_msg(result));
    zmq_sock_mutex_.unlock();
  }
}

void RemoteExecuter::AddCodeToExecute(string* code, const string& id) {
  // Get the stdin from the code.
  auto std_input_or_not = StdinFromCode(code, id);
  if (!std_input_or_not) {
    return;
  }
  std::unique_lock<std::mutex> lock(code_q_lock_);
  codes_.push(CodeInfo(id, std_input_or_not.value(), *code));
  lock.unlock();

  // Nofity one of the thread.
  cond_code_q_.notify_one();
}

RemoteExecuter::RemoteExecuter(zmq::socket_t* publisher)
    : publisher_(publisher) {
  // Build a thread pool.
  for (int i = 0; i < 3; i++) {
    threads_.emplace_back(
        std::thread(&RemoteExecuter::CodeExecutionThread, this, i + 1));
  }
}
}  // namespace remo_code
