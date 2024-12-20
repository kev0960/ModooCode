const express = require('express');
const body_parser = require('body-parser');
const compression = require('compression');
const init = require('./init.js')();
const CommentManager = require('./comment.js');
const PageViewManager = require('./page_view.js');

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
    {secret: process.env.SESSION_SECRET, resave: true, saveUninitialized: true}));


const Server = require('./server.js');
init.init().then(async function(static_data) {
  if (process.env.IN_WINDOWS_FOR_DEBUG !== 'true') {
    client.connect();
  }
  const comment_manager = new CommentManager(client);
  await comment_manager.init();

  const pageview_manager = new PageViewManager(client);
  await pageview_manager.init();

  const server = new Server(app, static_data, client, comment_manager, pageview_manager);

  app.listen(8080, function() {
    server.setRoutes();

    console.log('-------------------------');
    console.log('| ** SERVER IS READY **  |');
    console.log('| Listening on port 8080 |');
    console.log('-------------------------');
  });
}).catch(function(error) {
  console.log(error);
});
