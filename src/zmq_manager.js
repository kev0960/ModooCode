
const uuidv4 = require('uuid').v4;

class ZmqManager {
  constructor(send_sock, recv_sock) {
    this.requested_codes = new Map();
    this.send_sock = send_sock;
    this.recv_sock = recv_sock;

    this.send_sock.bindSync('tcp://127.0.0.1:3001');
    this.recv_sock.connect('tcp://127.0.0.1:3002');
    this.recv_sock.subscribe('');

    this.recv_sock.on('message', function(message) {
      message = message.toString();
      let delimiter = message.indexOf(':');
      let next_delimiter = message.indexOf(':', delimiter + 1);

      let compile_error = '', exec_result = '';
      // There was no compile error.
      if (next_delimiter === delimiter + 1) {
        exec_result = message.substr(next_delimiter + 1);
      } else {
        compile_error = message.substr(delimiter + 1);
      }

      let id = message.substr(0, delimiter);
      let cb = this.requested_codes.get(id);
      if (cb) {
        cb({exec_result, compile_error});
      }
    }.bind(this));
  }

  getNewId() {
    return uuidv4();
  }

  sendCodeToRun(code, stdin, cb) {
    let id = this.getNewId();
    this.requested_codes.set(id, cb);
    this.send_sock.send([id + ':' + stdin + id + code]);
  }
}

module.exports = {
  ZmqManager
};
