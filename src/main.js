const express = require('express');
const body_parser = require('body-parser');
const fs = require('fs');
const zmq = require('zmq');

const send_sock = zmq.socket('pub');
const recv_sock = zmq.socket('sub');

const app = express();

// Set the default rendering engine.
app.set('view engine', 'ejs');

// Set the static directory.
app.use(express.static(__dirname + '/../views'));
app.set('views', __dirname + '/../views');

// Set body parser.
app.use(body_parser.urlencoded({
  extended: true
}));

app.listen(3000, () => console.log('The server has started.'));

app.get('/', (req, res) => res.send('Hello World!'));

fs.readFile('file_headers.json', 'utf8', function (err, data) {
  if (err) {
    console.log(err);
    return;
  }
  file_infos = JSON.parse(data);
  app.get("/:id", function (req, res) {
    let page_id = parseInt(req.params.id);
    if (page_id <= 228) {
      res.render("page.ejs", {content_url: "./old/blog_" + page_id + ".html", file_info: file_infos[page_id]});
    }
  });
});

send_sock.bindSync('tcp://127.0.0.1:3001');
recv_sock.connect('tcp://127.0.0.1:3002');
recv_sock.subscribe('');

class ZmqManager {
  constructor() {
    this.requested_codes = new Map();
    this.cnt = 0;

    recv_sock.on('message', function (message) {
      message = message.toString();
      let delimiter = message.indexOf(':');
      let id = parseInt(message.substr(0, delimiter));
      let msg = message.substr(delimiter + 1);

      console.log(id, msg);
      let cb = this.requested_codes.get(id);
      if (cb) {
        cb(msg);
      }
    }.bind(this));
  }

  updateCnt() {
    this.cnt = (this.cnt + 1) % 10000;
  }

  sendCodeToRun(code, cb) {
    this.updateCnt();
    this.requested_codes.set(this.cnt, cb);
    send_sock.send([this.cnt + ':' + code]);
  }
}

zmq_manager = new ZmqManager();
app.post('/run', function (req, res) {
  let code = req.body.code;
  zmq_manager.sendCodeToRun(code, function (result) {
    console.log("Execution result : ", result);
    res.send(result);
  });
});