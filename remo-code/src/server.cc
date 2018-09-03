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

  std::cout << "---------------------------------" << std::endl;
  std::cout << "*       Server Has Started      *" << std::endl;
  std::cout << "*  Listening on localhost:3001  *" << std::endl;
  std::cout << "---------------------------------" << std::endl;

  while (true) {
    zmq::message_t code_to_run;
    receiver.recv(&code_to_run);
    std::string code =
        std::string(static_cast<char*>(code_to_run.data()), code_to_run.size());
    auto id = RetrieveIdFromInputCode(&code);
    std::cout << "Received! " << id << std::endl;

    // Handle.
    executor.AddCodeToExecute(code, atoi(id.c_str()));
  }
}
