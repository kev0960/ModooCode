#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <utility>
#include <vector>

using std::string;

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
