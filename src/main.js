const express = require('express');
const body_parser = require('body-parser');
const fs = require('fs');

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