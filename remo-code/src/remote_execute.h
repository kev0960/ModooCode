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

class RemoteExecuter {
 private:
  void CodeExecutionThread(int index);
  string SyncCompile(const string& code, int index);
  string SyncExecute(const string& std_input, int index);

  std::mutex code_q_lock_;
  std::condition_variable cond_code_q_;

  std::queue<std::pair<int, string>> codes_;
  std::vector<std::thread> threads_;

  zmq::socket_t* publisher_;
  std::mutex zmq_sock_mutex_;

 public:
  RemoteExecuter(zmq::socket_t* publisher);
  void AddCodeToExecute(const string& code, int index);
};

}  // namespace remo_code
