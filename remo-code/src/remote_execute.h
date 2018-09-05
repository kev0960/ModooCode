#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <zmq.hpp>

using std::string;

namespace remo_code {

struct CodeInfo {
  string id;
  string std_input;
  string code;

  CodeInfo(const string& id, const string& std_input, const string& code)
      : id(id), std_input(std_input), code(code) {}
};

class RemoteExecuter {
 private:
  void CodeExecutionThread(int index);
  string SyncCompile(const string& code, int thread_index);
  string SyncExecute(const string& std_input, int thread_index);

  std::mutex code_q_lock_;
  std::condition_variable cond_code_q_;

  std::queue<CodeInfo> codes_;
  std::vector<std::thread> threads_;

  zmq::socket_t* publisher_;
  std::mutex zmq_sock_mutex_;

 public:
  RemoteExecuter(zmq::socket_t* publisher);
  void AddCodeToExecute(string* code, const string& id);
};

}  // namespace remo_code
