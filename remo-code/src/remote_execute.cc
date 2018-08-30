#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <utility>
#include <vector>

using std::string;
constexpr int kOneMb = 1024 * 1024;
static char kGppName[] = "g++";
static char kGppReadFromStdin[] = "-x";
static char kGppLanguage[] = "c++";
static char kDash[] = "-";
static char kGppOutputFlag[] = "-o";
static char kGppOutputFile[] = "./tmp/";

// Instructions
//
// 1) Mount tmp directory as tmpfs;
// sudo mount -t tmpfs -o size=16m tmpfs ./tmp
//
//
namespace remo_code {
class RemoteExecuter {
 private:
  string SyncExecute(const string& code);

  std::mutex code_q_lock;
  std::condition_variable cond_code_q;

  std::queue<std::pair<int, string>> codes;
  std::vector<std::thread> threads;

  std::mutex result_q_lock;
  std::condition_variable cond_result_q;
  std::queue<std::pair<int, string>> results;

 public:
  RemoteExecuter();
  void CodeExecutionThread();
};

string RemoteExecuter::SyncExecute(const string& code) {
  int pipe_p2c[2];
  if (pipe(pipe_p2c) != 0) {
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
    close(pipe_p2c[0]);

    // Restrict the amount of CPU time for the compilation.
    const struct rlimit cpu_limit = {10, 10};
    setrlimit(RLIMIT_CPU, &cpu_limit);

    // Restrict the virtual memory size.
    const struct rlimit mem_limit = {128 * kOneMb, 128 * kOneMb};
    setrlimit(RLIMIT_AS, &mem_limit);

    // Restrict the output file size.
    const struct rlimit fs_limit = {2 * kOneMb, 2 * kOneMb};
    setrlimit(RLIMIT_FSIZE, &fs_limit);

    // Since we are just running a compiler, those restrictions above are good
    // enough.
    char* gpp_argv[] = {kGppName, kGppReadFromStdin, kGppLanguage,
                        kDash,    kGppOutputFlag,    kGppOutputFile};
    char* env[] = {NULL};
    int ret = execve("/usr/bin/g++", gpp_argv, env);
    return std::to_string(ret);
  } else {
    // We are in the parent process.
    close(pipe_p2c[0]);
    // Send the code through the pipe.
    write(pipe_p2c[1], code.c_str(), code.size());
    close(pipe_p2c[1]);

    int status;
    waitpid(pid, &status, 0); // Wait for the compile to end.
    if (!WIFEXITED(status)) {
      return "Compilation went wrong.. :(";
    }
  }
}

void RemoteExecuter::CodeExecutionThread() {
  while (true) {
    // Wait for the codes.
    std::unique_lock<std::mutex> lock(code_q_lock);
    cond_code_q.wait(lock, [this]() { return codes.size() > 0; });

    // Fetch the first code to execute.
    auto index_and_code = codes.front();
    codes.pop();
    lock.unlock();

    // Notify other threads to wake up since there might be other coes in the
    // queue.
    cond_code_q.notify_all();

    // Execute the code and save it to the result queue.
    auto result = SyncExecute(index_and_code.second);
    result_q_lock.lock();
    results.push(std::make_pair(index_and_code.first, result));
    result_q_lock.unlock();

    // Notify Main thread that the result is added.
    cond_result_q.notify_one();
  }
}

RemoteExecuter::RemoteExecuter() {
  for (int i = 0; i < 3; i++) {
    threads.emplace_back(
        std::thread(&RemoteExecuter::CodeExecutionThread, this));
  }
}
}  // namespace remo_code
