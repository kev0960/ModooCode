const zmq = require('zeromq');
const {ZmqManager} = require('./zmq_manager.js');
const {PathHierarchy} = require('./path_hierarchy.js');
const HeaderCategory = require('./header_category.js');
const util = require('./util.js');

const jsdom = require('jsdom');
const {JSDOM} = jsdom;

const MobileDetect = require('mobile-detect');

const facebook_strategy = require('passport-facebook').Strategy;
const google_strategy = require('passport-google-oauth2').Strategy;
const DISCOURSE_SSO = require('discourse-sso');

const passport = require('passport');
const bcrypt = require('bcrypt');
const request = require('request-promise-native');
const {google} = require('googleapis');
const goog_key = require(process.env.GOOGLE_APPLICATION_CREDENTIALS);

const HASH_ROUNDS = parseInt(process.env.HASH_ROUNDS);
const discourse_sso = new DISCOURSE_SSO(process.env.DISCOURSE_SSO_SECRET);
const IS_DEV = (process.env.SERVER_ENV == 'DEV');

function CheckMobile(req) {
  const md = new MobileDetect(req.headers['user-agent']);
  return md.mobile();
}

module.exports = class Server {
  constructor(app, static_data, client, comment_manager, pageview_manager) {
    this.file_infos = static_data.file_infos;
    this.page_infos = static_data.page_infos;
    this.path_hierarchy = new PathHierarchy(this.page_infos);
    this.header_category = new HeaderCategory(this.path_hierarchy.root_path);
    this.cached_category_html = new Map();

    // Set up the ZMQ for the remote code execution server.
    this.send_sock = zmq.socket('pub');
    this.recv_sock = zmq.socket('sub');
    this.zmq_manager = new ZmqManager(this.send_sock, this.recv_sock);

    this.app = app;
    this.client = client;
    this.comment_manager = comment_manager;
    this.pageview_manager = pageview_manager;

    // Flush Page View Cnt every minute.
    setInterval(function() {
      this.pageview_manager.flushPageViewCnt();
    }.bind(this), 1000 * 60);

    this.app.use(passport.initialize());
    this.app.use(passport.session());

    const fb_callback_url = IS_DEV ? 'http://localhost/auth/fb/callback' :
                                     'https://modoocode.com/auth/fb/callback';
    const goog_callback_url = IS_DEV ?
        'http://localhost/auth/goog/callback' :
        'https://modoocode.com/auth/goog/callback';
    passport.use(new facebook_strategy(
        {
          clientID: process.env.FB_APP_ID,
          clientSecret: process.env.FB_APP_SECRET,
          callbackURL: fb_callback_url,
          profileFields: ['id', 'displayName', 'photos', 'emails']
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
          callbackURL: goog_callback_url,
        },
        async function(access_token, refresh_token, profile, cb) {
          let user = await this.findOrCreateUser(
              'goog', profile, profile.photos[0].value);
          cb(null, user);
        }.bind(this)));

    passport.serializeUser(function(user, done) {
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
      if (this.file_infos[key].is_published === 'false') {
        return;
      }
      entire_articles.push({key, date: this.file_infos[key].publish_date})
    }.bind(this));

    entire_articles
        .sort(function(a, b) {
          let a_t = new Date(a.date);
          let b_t = new Date(b.date);
          return b_t - a_t;
        })

        // Find top 5 Recent articles.
        this.recent_articles = entire_articles.slice(0, 5).map(function(s) {
      return {url: s.key, info: this.file_infos[s.key]};
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
    let email = '';
    if (profile.emails && profile.emails.length >= 1) {
      email = profile.emails[0].value;
    }

    let id = profile.id;
    let result = await this.client.query(
        'SELECT * FROM users WHERE auth_type = $1::text AND auth_id = $2::text',
        [auth_type, id]);
    if (result.rows.length == 0) {
      // We need to create new profile.
      result = await this.client.query(
          'INSERT INTO users(auth_id, name, image, email, auth_type)' +
              ' VALUES ($1::text, $2::text, $3::text, $4::text, $5::text) RETURNING *',
          [profile.id, profile.displayName, image_url, email, auth_type]);
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
          cat_html +=
              '<i class="xi-plus-square" style="font-size:0.75em;"></i>&nbsp;&nbsp;';
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
    // Get the directory.
    const current_dir = this.GetFilesFromPath(path);

    if (current_dir.files.length <= 5) {
      if (current_dom.classList) {
        current_dom.classList.add('open-cat');
      } else {
        current_dom.className += ' open-cat';
      }

      let html = current_dom.innerHTML;
      html = html.replace(
          '<i class="xi-plus-square" style="font-size:0.75em;"></i>',
          '<i class="xi-caret-down-min" style="font-size:0.75em;"></i>');
      html = html.replace(
          '<i class="xi-plus-square" style="font-size:0.75em;"></i>',
          '<i class="xi-caret-down-min" style="font-size:0.75em;"></i>');
      current_dom.innerHTML = html;
    } else {
      current_dom.style.backgroundColor = 'rgba(255, 255, 255, .33)';
    }

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
    // Add files if there aren't that many.
    if (current_dir.files.length <= 5) {
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
  }

  generateInfoToPassEJS(content_url, page_id, category_id, user, is_mobile) {
    let canonical_url = 'https://modoocode.com/' + page_id;
    return {
      content_url,
      canonical_url,
      file_info: this.file_infos[page_id],
      page_infos: this.page_infos,
      file_infos: this.file_infos,
      category_html: this.buildCategoryListing(category_id),
      num_comment: this.comment_manager.getNumCommentAt(page_id),
      view_cnt: this.pageview_manager.getPageViewCnt(page_id),
      header_category: this.header_category.BuildPageHeader(),
      is_mobile,
      user
    };
  }

  setRoutes() {
    // Set up all the routes.
    this.app.get('/', function(req, res) {
      this.comment_manager.getLatestComments(10).then(function(comments) {
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

    this.app.get('/new-page/:id', function(req, res) {
      let page_id = parseInt(req.params.id);
      let user = req.user;

      let fallbackToIndexOnFailOrPass = function(err, html) {
        if (err) {
          console.log(err);
          this.comment_manager.getLatestComments(10).then(function(comments) {
            res.render('./index.ejs', {
              comments,
              recent_articles: this.recent_articles,
              visitor_counts: this.visitor_counts
            });
          }.bind(this));
        } else {
          res.send(html);
        }
      }.bind(this);
      if (page_id <= 228) {
        if (page_id == 15) {
          this.pageview_manager.addPageViewCnt('231');
          return res.render(
              'new_page.ejs',
              this.generateInfoToPassEJS(
                  './new/231.html', 231, page_id, user, CheckMobile(req)));
        }
        this.pageview_manager.addPageViewCnt(page_id);
        res.render(
            'new_page.ejs',
            this.generateInfoToPassEJS(
                './old/blog_' + page_id + '.html', page_id, page_id, user,
                CheckMobile(req)),
            fallbackToIndexOnFailOrPass);
      } else {
        this.pageview_manager.addPageViewCnt(page_id);
        res.render(
            'new_page.ejs',
            this.generateInfoToPassEJS(
                './new/' + page_id + '.html', page_id, page_id, user,
                CheckMobile(req)),
            fallbackToIndexOnFailOrPass);
      }
    }.bind(this));


    this.app.get('/comments', async function(req, res) {
      this.comment_manager.getLatestComments(150).then(function(comments) {
        res.render('./comments.ejs', {
          comments,
        });
      }.bind(this));
    }.bind(this));

    this.app.get('/:id', function(req, res) {
      let page_id = parseInt(req.params.id);
      let user = req.user;
      if (!page_id) {
        this.comment_manager.getLatestComments(10).then(function(comments) {
          res.render('./index.ejs', {
            comments,
            recent_articles: this.recent_articles,
            visitor_counts: this.visitor_counts
          });
        }.bind(this));
        return;
      }
      console.log('Page [', util.getDateTime(), '] ::', page_id);

      let fallbackToIndexOnFailOrPass = function(err, html) {
        if (err) {
          this.comment_manager.getLatestComments(10).then(function(comments) {
            res.render('./index.ejs', {
              comments,
              recent_articles: this.recent_articles,
              visitor_counts: this.visitor_counts
            });
          }.bind(this));
        } else {
          res.send(html);
        }
      }.bind(this);

      if (page_id <= 228) {
        if (page_id == 15) {
          this.pageview_manager.addPageViewCnt('231');
          return res.render(
              'page.ejs',
              this.generateInfoToPassEJS(
                  './new/231.html', 231, page_id, user, CheckMobile(req)));
        }
        this.pageview_manager.addPageViewCnt(page_id);
        res.render(
            'page.ejs',
            this.generateInfoToPassEJS(
                './old/blog_' + page_id + '.html', page_id, page_id, user,
                CheckMobile(req)),
            fallbackToIndexOnFailOrPass);
      } else {
        this.pageview_manager.addPageViewCnt(page_id);
        res.render(
            'page.ejs',
            this.generateInfoToPassEJS(
                './new/' + page_id + '.html', page_id, page_id, user,
                CheckMobile(req)),
            fallbackToIndexOnFailOrPass);
      }
    }.bind(this));

    this.app.get('/notice/:id', function(req, res) {
      let page_id = parseInt(req.params.id);
      let user = req.user;
      if (page_id == 15) {
        return res.redirect('/231');
      }
      return res.redirect('/');
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
              'Executed Code : \n', code, '\nExecution result : \n',
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
      let result =
          await this.comment_manager.deleteComment(comment_id, user, password);
      return res.send(result);
    }.bind(this));

    this.app.post('/write-comment', async function(req, res) {
      if (process.env.SERVER_ENV != 'DEV') {
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
      }

      let parent_id = parseInt(req.body.parent_id);
      let content = req.body.content;
      let password = req.body.password;
      let article_url = req.body.article_url;

      // Remove #.. and ?.. from URL.
      if (article_url.indexOf('#') !== -1) {
        article_url = article_url.substr(0, article_url.indexOf('#'));
      }
      if (article_url.indexOf('?') !== -1) {
        article_url = article_url.substr(0, article_url.indexOf('?'));
      }

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
      await this.comment_manager.addComment(
          parent_id, article_url, user, content, password);
      return res.send({status: 'Success'});
    }.bind(this));

    /*******************************

        Authentication Logics

    *******************************/
    this.app.get(
        '/auth/fb', passport.authenticate('facebook', {scope: ['email']}));
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

    /**************************************************************************
     *
     *                        Discourse SSO Overview
     *
     * 1) User logins to the Discourse Login.
     * 2) Discourse redirect to /auth/discourse?(payload, sig)
     * 3) Server checks payload and sig. Also, checks user info if exists.
     * 4) If user info does not exist, redirect user to the /auth/goog page.
     *    * Note that upon redirection, make sure we save the callback
     *      url to the localStorage (TODO: Use sessionStroage?)
     * 5) Google authenticates the user and redirect user to /auth/goog/callback
     * 6) At callback page, redirect user the correct callback url
     *    /auth/discourse-redir
     * 7) Finally redirect user to discourse/session/sso_login with user info
     *    query parameters.
     **************************************************************************/
    this.app.get('/auth/discourse', function(req, res) {
      let payload = req.query.sso;
      let sig = req.query.sig;

      // Both payload and sig must be specified and valid.
      if (!payload || !sig || !discourse_sso.validate(payload, sig)) {
        return res.redirect('/');
      }

      let user = req.user;
      if (!user) {
        // If the user is not defined, return back to Google authentication
        // (This is because FB does not provide email sometimes.)
        return res.send(
            '<script>' +
            'window.localStorage.setItem("redirect-info", JSON.stringify({' +
            'current_url : "/auth/discourse-redir?payload=' + payload +
            '"}));' +
            'window.location.href="/auth/goog";</script>');
      }

      let email = user.email;
      let external_id = user.user_id;
      let nonce = discourse_sso.getNonce(payload);
      let name = user.name;

      let q = discourse_sso.buildLoginString({nonce, external_id, email, name});

      if (IS_DEV) {
        return res.redirect('http://localhost:3000/session/sso_login?' + q);
      } else {
        return res.redirect(
            'https://forum.modoocode.com/session/sso_login?' + q);
      }
    });

    this.app.get('/auth/discourse-redir', function(req, res) {
      let user = req.user;
      let payload = req.query.payload;

      if (!user || !payload) {
        return res.redirect('/')
      }

      let email = user.email;
      let external_id = user.user_id;
      let nonce = discourse_sso.getNonce(payload);
      let name = user.name;

      let q = discourse_sso.buildLoginString({nonce, external_id, email, name});

      if (IS_DEV) {
        return res.redirect('http://localhost:3000/session/sso_login?' + q);
      } else {
        return res.redirect(
            'https://forum.modoocode.com/session/sso_login?' + q);
      }
    })
  }
};