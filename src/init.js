// Read the components before starting the server.

const fs = require('fs');
const path = require('path');

module.exports = function () {
  const readFilePromise = function (filename) {
    return new Promise(function (resolve, reject) {
      fs.readFile(filename, 'utf8', function (err, data) {
        if (err) {
          return reject(err);
        }
        return resolve(data);
      });
    });
  };

  const readFileAllPromise = function (filenames) {
    let promises = [];
    for (let i = 0; i < filenames.length; i++) {
      promises.push(readFilePromise(path.join(__dirname, '..', filenames[i])));
    }
    return Promise.all(promises);
  };

  const init = function () {
    // First read the filename to page url file to build a table.
    return readFileAllPromise(["file_headers.json", "page_path.json"])
      .then(function (static_data) {
        let file_infos = JSON.parse(static_data[0]);
        let page_infos = JSON.parse(static_data[1]);
        return {file_infos, page_infos};
      }).catch(function(err) {
        console.log(err);
      });
  };

  return {
    init
  }
};