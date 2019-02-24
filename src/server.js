const zmq = require('zmq');
const uuidv4 = require('uuid/v4');
const jsdom = require('jsdom');
const {JSDOM} = jsdom;

const facebook_strategy = require('passport-facebook').Strategy;
const google_strategy = require('passport-google-oauth2').Strategy;
const passport = require('passport');
const bcrypt = require('bcrypt');
const request = require('request-promise-native');
const {google} = require('googleapis');
const goog_key = require(process.env.GOOGLE_APPLICATION_CREDENTIALS);

const HASH_ROUNDS = parseInt(process.env.HASH_ROUNDS);

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

class PagePath {
  constructor(files, name) {
    this.files = new Set();
    this.name = name;

    for (let i = 0; i < files.length; i++) {
      this.files.add(files[i]);
    }

    this.directories = []
  }

  addDirectory(directory) {
    this.directories.push(directory);
  }

  findPage(page) {
    if (this.files.has(page)) {
      return [page];
    }
    for (let i = 0; i < this.directories.length; i++) {
      let result = this.directories[i].findPage(page);
      if (result.length != 0) {
        return [this.directories[i].name].concat(result);
      }
    }
    return [];
  }
};

class PathHierarchy {
  constructor(path_json) {
    this.root_path = new PagePath([], '');
    this.recursiveAddPath(this.root_path, path_json['']);
    this.cached_search_result = new Map();
  }

  recursiveAddPath(current_page_path, path_json) {
    for (let dir_name in path_json) {
      if (dir_name == 'files') {
        continue;
      }
      let child_page_path = new PagePath(path_json[dir_name].files, dir_name);
      this.recursiveAddPath(child_page_path, path_json[dir_name]);
      current_page_path.addDirectory(child_page_path);
    }
  }

  searchPagePath(page_id) {
    if (typeof page_id !== 'string') {
      page_id = page_id.toString();
    }
    if (!this.cached_search_result.get(page_id)) {
      let result = this.root_path.findPage(page_id);
      this.cached_search_result.set(page_id, result);
      return result;
    }
    return this.cached_search_result.get(page_id);
  }
}

function getDateTime() {
  let date = new Date();
  let hour = date.getHours();
  hour = (hour < 10 ? '0' : '') + hour;
  let min = date.getMinutes();
  min = (min < 10 ? '0' : '') + min;
  let sec = date.getSeconds();
  sec = (sec < 10 ? '0' : '') + sec;
  let year = date.getFullYear();
  let month = date.getMonth() + 1;
  month = (month < 10 ? '0' : '') + month;
  let day = date.getDate();
  day = (day < 10 ? '0' : '') + day;
  return year + ':' + month + ':' + day + ':' + hour + ':' + min + ':' + sec;
}

module.exports = class Server {
  constructor(app, static_data, client) {
    this.file_infos = static_data.file_infos;
    this.page_infos = static_data.page_infos;
    this.path_hierarchy = new PathHierarchy(this.page_infos);
    this.cached_category_html = new Map();

    // Set up the ZMQ for the remote code execution server.
    this.send_sock = zmq.socket('pub');
    this.recv_sock = zmq.socket('sub');
    this.zmq_manager = new ZmqManager(this.send_sock, this.recv_sock);

    this.app = app;
    this.client = client;

    this.app.use(passport.initialize());
    this.app.use(passport.session());

    passport.use(new facebook_strategy(
        {
          clientID: process.env.FB_APP_ID,
          clientSecret: process.env.FB_APP_SECRET,
          callbackURL: 'https://modoocode.com/auth/fb/callback',
          profileFields: ['id', 'displayName', 'photos', 'email']
        },
        async function(access_token, refresh_token, profile, cb) {
          let user = await this.findOrCreateUser(
              'fb', profile, profile.photos[0].value);
          cb(null, user);
        }.bind(this)));

    passport.use(new google_strategy(
        {
          clientID: process.env.GOOG_CLIENT_ID,
          clientSecret: process.env.GOOG_CLIENT_SEC,
          callbackURL: 'https://modoocode.com/auth/goog/callback',
        },
        async function(access_token, refresh_token, profile, cb) {
          console.log('Goog ', profile);
          let user = await this.findOrCreateUser(
              'goog', profile, profile.photos[0].value);
          cb(null, user);
        }.bind(this)));

    passport.serializeUser(function(user, done) {
      console.log('serial user : ', user);
      done(null, user.user_id);
    });

    passport.deserializeUser(function(user_id, done) {
      this.findUser(user_id).then(function(user) {
        return done(null, user);
      });
    }.bind(this));

    this.max_key = -1
    let entire_articles = [];

    Object.keys(this.file_infos).forEach(function(key) {
      if (parseInt(key) > this.max_key) {
        this.max_key = parseInt(key)
      }
      if (!this.file_infos[key].publish_date) {
        this.file_infos[key].publish_date = '2018-12-31';
      }
      entire_articles.push({
        key, date : this.file_infos[key].publish_date
      })
    }.bind(this));

    entire_articles.sort(function (a, b) {
      let a_t = new Date(a.date);
      let b_t = new Date(b.date);
      return b_t - a_t;
    })

    // Find top 5 Recent articles.
    this.recent_articles = entire_articles.slice(0, 5).map(function(s) {
      return {url : s.key, info : this.file_infos[s.key]};
    }.bind(this));

    this.jwt = new google.auth.JWT(
        goog_key.client_email, null, goog_key.private_key,
        'https://www.googleapis.com/auth/analytics.readonly');

    this.visitor_counts = [];
    if (process.env.IN_WINDOWS_FOR_DEBUG !== 'true') {
      this.GetVisitorData();
    }

    // Retrieve visitor data every 30 seconds.
    setInterval(function() {
      if (process.env.IN_WINDOWS_FOR_DEBUG !== 'true') {
        this.GetVisitorData();
      }
    }.bind(this), 30000);
  }

  GetVisitorData() {
    let that = this;
    this.jwt.authorize(function(err, response) {
      google.analytics('v3').data.ga.get(
          {
            auth: that.jwt,
            ids: 'ga:184092436',
            'start-date': '7daysAgo',
            'end-date': 'today',
            metrics: 'ga:1dayUsers',
            'dimensions': 'ga:date'
          },
          function(err, result) {
            if (err) {
              console.log('Google Analytics Error : ', err);
              return;
            }
            that.visitor_counts = result.data.rows;
          })
    });
  }

  async findOrCreateUser(auth_type, profile, image_url) {
    let id = profile.id;
    let result = await this.client.query(
        'SELECT * FROM users WHERE auth_type = $1::text AND auth_id = $2::text',
        [auth_type, id]);
    if (result.rows.length == 0) {
      // We need to create new profile.
      result = await this.client.query(
          'INSERT INTO users(auth_id, name, image, email, auth_type)' +
              ' VALUES ($1::text, $2::text, $3::text, $4::text, $5::text) RETURNING *',
          [
            profile.id, profile.displayName, image_url, profile.email, auth_type
          ]);
    } else if (result.rows[0].image != image_url) {
      result = await this.client.query(
          'UPDATE users SET image = $1::text WHERE auth_id = $2 RETURNING *',
          [image_url, id]);
    }
    return result.rows[0];
  }

  async findUser(auth_id) {
    let result = await this.client.query(
        'SELECT * FROM users WHERE user_id = $1', [auth_id]);
    return result.rows[0];
  }

  async addComment(parent_id, article_url, user, content, password) {
    let current_time = new Date();
    // (Note) Fixing comment_comment_id_seq sync error;
    // SELECT setval('comment_comment_id_seq', max(comment_id)) FROM comment;
    // (Note) Removing specific reply (5829 : reply comment)
    // update comment set reply_ids = array_remove(reply_ids, 5829) where
    // comment_id = 4108;
    let result = await this.client.query(
        'INSERT INTO comment(article_url, reply_ids, vote_up, vote_down,' +
            'comment_date, modified_date, author_name, author_email, image_link,' +
            'content, password, author_id, is_md) VALUES ($1, $2, $3, $4, $5, $6, $7,' +
            ' $8, $9, $10, $11, $12, $13) RETURNING *',
        [
          article_url, [], 0, 0, current_time, current_time, user.name,
          user.email, user.image, content, password, user.user_id, true
        ]);
    let new_comment = result.rows[0];
    let new_comment_id = new_comment.comment_id;

    if (parent_id !== -1) {
      await this.client.query(
          'UPDATE comment SET reply_ids = array_append(reply_ids, $1) WHERE' +
              ' comment_id = $2',
          [new_comment_id, parent_id]);
    }
  }

  async deleteComment(comment_id, user, password) {
    let comment = await this.client.query(
        'SELECT comment_id, author_id, password' +
            ' FROM comment WHERE comment_id = $1',
        [comment_id]);
    if (comment.rows.length == 0) {
      return {status: false, msg: 'Fatal error'};
    }
    comment = comment.rows[0];
    if (comment.author_id != user.user_id) {
      // Then check whether email and the password matches.
      const match = await bcrypt.compare(password, comment.password);
      if (!match) {
        return {status: false, msg: 'Password does not match'};
      }
    }

    await this.client.query(
        'UPDATE comment SET is_deleted = TRUE, ' +
            'content = \'삭제된 댓글입니다\' WHERE comment_id = $1',
        [comment_id]);
    return {status: true};
  }

  async getLatestComments(num_comment) {
    if (process.env.IN_WINDOWS_FOR_DEBUG === 'true') {
      return [];
    }

    let latest_comments = await this.client.query(
        'SELECT content, comment_date, article_url, author_name FROM ' +
            'comment WHERE is_deleted = FALSE ORDER BY comment_date DESC LIMIT $1',
        [num_comment]);
    for (let i = 0; i < latest_comments.rows.length; i++) {
      let d = new Date(latest_comments.rows[i].comment_date);
      let month = '' + (d.getMonth() + 1);
      let day = '' + d.getDate();
      if (month.length < 2) {
        month = '0' + month;
      }
      if (day.length < 2) {
        day = '0' + day;
      }
      latest_comments.rows[i].comment_date = month + '.' + day;
    }
    return latest_comments.rows;
  }

  buildCategoryListing(page_id) {
    if (this.cached_category_html.get(page_id)) {
      return this.cached_category_html.get(page_id);
    }

    let root = this.page_infos[''];
    let root_folders = Object.keys(root);
    let page_path = this.path_hierarchy.searchPagePath(page_id);
    let cat_html = '';

    for (let i = 0; i < root_folders.length; i++) {
      if (root_folders[i] !== 'files') {
        cat_html += '<a class="sidebar-nav-item dir" name="';
        cat_html += root_folders[i] + '">';
        if (root[root_folders[i]].files.length > 0 ||
            Object.keys(root[root_folders[i]]).length >= 2) {
          cat_html += '<i class="xi-plus-square"></i>&nbsp;&nbsp;';
        }
        cat_html += root_folders[i] + '</a>';
      }
    }
    let category = new JSDOM(cat_html);
    let {window} = category;
    let {document} = window;

    // Due to the bug in nwmatcher, we just manually find the element.
    let every_elements = document.querySelectorAll('a');
    for (let i = 0; i < every_elements.length; i++) {
      if (every_elements[i].getAttribute('name') === page_path[0]) {
        this.buildCategoryListingRecurse(
            every_elements[i], page_path, 1, document);
        break;
      }
    }

    let category_html = document.body.innerHTML;

    this.cached_category_html.set(page_id, category_html);
    return category_html;
  }

  GetFilesFromPath(path) {
    let current_dir = this.page_infos[''];
    for (let i = 0; i < path.length; i++) {
      current_dir = current_dir[path[i]];
    }
    return current_dir;
  }

  buildCategoryListingRecurse(current_dom, full_path, depth, document) {
    let path = full_path.slice(0, depth);
    if (full_path.length == depth) {
      let last_node =
          document.querySelector('a[href="/' + full_path[depth - 1] + '"]');
      last_node.style.backgroundColor = 'rgba(255, 255, 255, .33)';
      return;
    }

    if (current_dom.classList) {
      current_dom.classList.add('open-cat');
    } else {
      current_dom.className += ' open-cat';
    }

    let html = current_dom.innerHTML;
    html = html.replace(
        '<i class="xi-plus-square" style="font-size:0.75em;"></i>',
        '<i class=\'xi-caret-down-min\'></i>');
    html = html.replace(
        '<i class="xi-plus-square"></i>',
        '<i class=\'xi-caret-down-min\'></i>');
    current_dom.innerHTML = html;

    // Get the directory.
    const current_dir = this.GetFilesFromPath(path);
    // Add directories.
    const folders = Object.keys(current_dir);
    let div = document.createElement('div');
    div.className = `inner-menu${path.length}`;

    for (let i = 0; i < folders.length; i++) {
      if (folders[i] !== 'files') {
        const dir_folders = Object.keys(current_dir[folders[i]]);
        let folder_html = folders[i];
        if (dir_folders.length >= 2 ||
            current_dir[folders[i]].files.length > 0) {
          folder_html = `${
                        '<i class="xi-plus-square" ' +
              'style="font-size:0.75em;"></i>&nbsp;&nbsp;'}${folder_html}`;
        }
        const folder_link = document.createElement('a');
        folder_link.className = 'sidebar-nav-item dir';
        folder_link.setAttribute('name', folders[i]);
        folder_link.innerHTML = folder_html;
        div.appendChild(folder_link);
      }
    }
    // Add files.
    for (let i = 0; i < current_dir.files.length; i++) {
      const file_id = current_dir.files[i];
      let cat_title = this.file_infos[file_id].title;
      if (this.file_infos[file_id].cat_title) {
        cat_title = this.file_infos[file_id].cat_title;
      }

      const file_link = document.createElement('a');
      file_link.className = 'sidebar-nav-item file';
      file_link.setAttribute('href', '/' + file_id);
      file_link.setAttribute('name', cat_title);
      file_link.textContent = cat_title;
      div.appendChild(file_link);
    }

    function insertAfter(el, referenceNode) {
      referenceNode.parentNode.insertBefore(el, referenceNode.nextSibling);
    }
    insertAfter(div, current_dom);

    // div.insertAfter(current_dom);
    let children = current_dom.nextElementSibling.children;
    let found = null;
    for (let i = 0; i < children.length; i++) {
      if (children[i].getAttribute('name') == full_path[depth]) {
        found = children[i];
        break;
      }
    }
    this.buildCategoryListingRecurse(found, full_path, depth + 1, document);
  }

  setRoutes() {
    // Set up all the routes.
    this.app.get('/', function(req, res) {
      this.getLatestComments(10).then(function(comments) {
        res.render('./index.ejs', {
          comments,
          recent_articles: this.recent_articles,
          visitor_counts: this.visitor_counts
        });
      }.bind(this));
    }.bind(this));

    this.app.get('/profile', function(req, res) {
      if (req.user) {
        return res.send('name' + req.user.name);
      }
      res.send('name');
    });

    this.app.get('/:id', function(req, res) {
      let page_id = parseInt(req.params.id);
      let user = req.user;
      if (!page_id) {
        this.getLatestComments(10).then(function(comments) {
          res.render('./index.ejs', {
            comments,
            recent_articles: this.recent_articles,
            visitor_counts: this.visitor_counts
          });
        }.bind(this));
        return;
      }
      console.log('Page [', getDateTime(), '] ::', page_id);

      if (page_id <= 228) {
        if (page_id == 15) {
          return res.render('page.ejs', {
            content_url: './new/231.html',
            file_info: this.file_infos[231],
            page_infos: this.page_infos,
            file_infos: this.file_infos,
            category_html: this.buildCategoryListing(page_id),
            user
          });
        }
        res.render(
            'page.ejs', {
              content_url: './old/blog_' + page_id + '.html',
              file_info: this.file_infos[page_id],
              page_infos: this.page_infos,
              file_infos: this.file_infos,
              category_html: this.buildCategoryListing(page_id),
              user
            },
            function(err, html) {
              if (err) {
                this.getLatestComments(10).then(function(comments) {
                  res.render('./index.ejs', {
                    comments,
                    recent_articles: this.recent_articles,
                    visitor_counts: this.visitor_counts
                  });
                }.bind(this));
              } else {
                res.send(html);
              }
            }.bind(this));
      } else {
        res.render(
            'page.ejs', {
              content_url: './new/' + page_id + '.html',
              file_info: this.file_infos[page_id],
              page_infos: this.page_infos,
              file_infos: this.file_infos,
              category_html: this.buildCategoryListing(page_id),
              user
            },
            function(err, html) {
              if (err) {
                this.getLatestComments(10).then(function(comments) {
                  res.render('./index.ejs', {
                    comments,
                    recent_articles: this.recent_articles,
                    visitor_counts: this.visitor_counts
                  });
                }.bind(this));
                return;
              } else {
                res.send(html);
              }
            }.bind(this));
      }
    }.bind(this));

    this.app.get('/notice/:id', function(req, res) {
      let page_id = parseInt(req.params.id);
      let user = req.user;
      if (page_id == 15) {
        res.render('page.ejs', {
          content_url: './new/231.html',
          file_info: this.file_infos[231],
          page_infos: this.page_infos,
          file_infos: this.file_infos,
          category_html: this.buildCategoryListing('231'),
          user
        });
      }
    }.bind(this));

    this.app.post('/run', function(req, res) {
      function truncateString(str, length) {
        let dots = str.length > length ? '...' : '';
        return str.substring(0, length) + dots;
      };

      let code = req.body.code;
      let stdin = req.body.stdin;

      if (!stdin) {
        stdin = '';
      }
      this.zmq_manager.sendCodeToRun(code, stdin, function(result) {
        if (result.exec_result.length > 0) {
          console.log(
              'Executed Code : \n', truncateString(code, 1024),
              '\nExecution result : \n',
              truncateString(result.exec_result, 128));
        } else {
          console.log(
              'Executed Code : \n', truncateString(code, 128),
              'Compile error : \n', result.compile_error);
        }
        res.send(result);
      });
    }.bind(this));

    this.app.post('/get-comment', async function(req, res) {
      let id = req.body.id;
      const result = await this.client.query(
          'SELECT author_name, comment_date, modified_date, comment_id, content,' +
              'image_link, reply_ids, vote_up, vote_down, is_md, is_deleted FROM' +
              ' comment WHERE article_url = $1::text ORDER BY comment_id ASC',
          [id]);
      res.send(result.rows);
    }.bind(this));

    this.app.post('/delete-comment', async function(req, res) {
      let password = req.body.password;
      let comment_id = req.body.comment_id;
      let user = req.user;
      if (user) {
        password = '';
      } else {
        user = {user_id: -1};
      }
      console.log(user, comment_id, password);
      let result = await this.deleteComment(comment_id, user, password);
      return res.send(result);
    }.bind(this));

    this.app.post('/write-comment', async function(req, res) {
      const response = await request.post({
        url: 'https://www.google.com/recaptcha/api/siteverify',
        resolveWithFullResponse: true,
        form: {
          secret: '6LeE_nYUAAAAABelPPovV9f9DOAJSzqpTQTA4bt7',
          response: req.body.token
        }
      });
      if (!JSON.parse(response.body).success) {
        return res.send({status: 'Failed', reason: 'Failed CaptCha'});
      }

      let parent_id = parseInt(req.body.parent_id);
      let content = req.body.content;
      let password = req.body.password;
      let article_url = req.body.article_url;
      let name = req.body.name;
      let user = req.user;
      if (!user) {
        user = {name, image: '', email: '', user_id: -1};
        if (!name) {
          return res.send({status: 'Failed', reason: 'Missing name'});
        }
        if (!password) {
          return res.send({status: 'Failed', reason: 'Missing password'});
        } else {
          password = await bcrypt.hash(password, HASH_ROUNDS);
        }
      } else {
        // If the user is signed in, then make the password field empty.
        password = '';
      }
      console.log(parent_id, article_url, content, password, user);
      if (!parent_id || !content) {
        return res.send({status: 'Failed', reason: 'Missing params'});
      }
      await this.addComment(parent_id, article_url, user, content, password);
      return res.send({status: 'Success'});
    }.bind(this));

    // Install login modules.
    this.app.get('/auth/fb', passport.authenticate('facebook'));
    this.app.get(
        '/auth/goog',
        passport.authenticate('google', {scope: ['profile', 'email']}));
    this.app.get(
        '/auth/fb/callback',
        passport.authenticate('facebook', {failureRedirect: '/'}),
        function(req, res) {
          res.send(
              '<script>window.location.href=' +
              'JSON.parse(window.localStorage.getItem(\'redirect-info\'))' +
              '.current_url;</script>');
        });
    this.app.get(
        '/auth/goog/callback',
        passport.authenticate('google', {failureRedirect: '/'}),
        function(req, res) {
          res.send(
              '<script>window.location.href=' +
              'JSON.parse(window.localStorage.getItem(\'redirect-info\'))' +
              '.current_url;</script>');
        });
  }
};