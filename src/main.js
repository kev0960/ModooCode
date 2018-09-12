const express = require('express');
const body_parser = require('body-parser');
const compression = require('compression');
const init = require('./init.js')();
require('dotenv').config();
const {Client} = require('pg');
const client = new Client();

const app = express();

// Set the default rendering engine.
app.set('view engine', 'ejs');

// Compress the data.
app.use(compression());

// Set the static directory.
app.use(express.static(__dirname + '/../views'));
app.set('views', __dirname + '/../views');

// Set body parser.
app.use(require('cookie-parser')());
app.use(body_parser.urlencoded({extended: true}));
app.use(require('express-session')(
    {secret: 'keyboard cat', resave: true, saveUninitialized: true}));


const Server = require('./server.js');
init.init().then(async function(static_data) {
  client.connect();
  const server = new Server(app, static_data, client);

  app.listen(80, function() {
    server.setRoutes();

    console.log('-------------------------');
    console.log('| ** SERVER IS READY **  |');
    console.log('|  Listening on port 80  |');
    console.log('-------------------------');
  });
});