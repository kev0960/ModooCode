const express = require('express');
const body_parser = require('body-parser');
const compression = require('compression');
const init = require('./init.js')();

const app = express();

// Set the default rendering engine.
app.set('view engine', 'ejs');

// Compress the data.
app.use(compression());

// Set the static directory.
app.use(express.static(__dirname + '/../views'));
app.set('views', __dirname + '/../views');

// Set body parser.
app.use(body_parser.urlencoded({
                                 extended: true
                               }));


const Server = require('./server.js');
init.init().then(function(static_data) {
  const server = new Server(app, static_data);
  app.listen(80, function () {
    server.setRoutes();

    console.log('-------------------------');
    console.log('| ** SERVER IS READY **  |');
    console.log('|  Listening on port 80  |');
    console.log('-------------------------');
  });
});


