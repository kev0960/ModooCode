#include <iostream>
#include <string>
#include <zmq.hpp>

#include "remote_execute.h"

const static std::string kResult = "result";

namespace {
std::string RetrieveIdFromInputCode(std::string* code) {
  auto delimiter = code->find(":");
  std::string id = code->substr(0, delimiter);
  code->erase(0, delimiter + 1);
  return id;
}
}  // namespace

int main() {
  zmq::context_t context(1);
  zmq::socket_t publisher(context, ZMQ_PUB);
  zmq::socket_t receiver(context, ZMQ_SUB);

  // Initialize the publisher.
  publisher.bind("tcp://127.0.0.1:3002");

  // Initialize the receiver.
  receiver.connect("tcp://127.0.0.1:3001");
  receiver.setsockopt(ZMQ_SUBSCRIBE, "", 0);

  // Build Remote Executer.
  remo_code::RemoteExecuter executor(&publisher);

  while (true) {
    zmq::message_t code_to_run;
    receiver.recv(&code_to_run);
    std::string code =
        std::string(static_cast<char*>(code_to_run.data()), code_to_run.size());
    auto id = RetrieveIdFromInputCode(&code);
    std::cout << "Received! " << id << std::endl;

    // Handle.
    executor.AddCodeToExecute(code, atoi(id.c_str()));

    /*
    std::string s = id + ":Compiled.. seems good";
    zmq::message_t msg(s.size());
    memcpy(msg.data(), s.c_str(), s.size());
    // zmq_send(&publisher, s.c_str(), s.size(), 0);
    publisher.send(msg);
    std::cout << "Sent!" << std::endl;
    ;*/
  }
}
