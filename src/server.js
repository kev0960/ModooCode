const zmq = require('zmq');
const uuidv4 = require('uuid/v4');

const facebook_strategy = require('passport-facebook').Strategy;
const naver_strategy = require('passport-naver').Strategy;
const google_strategy = require('passport-google-oauth2').Strategy;
const passport = require('passport');

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

      console.log(id, message.substr(0, delimiter), {
        exec_result,
        compile_error,
      });
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

module.exports = class Server {
  constructor(app, static_data, client) {
    this.file_infos = static_data.file_infos;
    this.page_infos = static_data.page_infos;

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
          callbackURL: 'http://localhost/auth/fb/callback',
          profileFields: ['id', 'displayName', 'photos', 'email']
        },
        async function(access_token, refresh_token, profile, cb) {
          let user = await this.findOrCreateUser('fb', profile);
          cb(null, user);
        }.bind(this)));

    passport.use(new google_strategy(
        {
          clientID: process.env.GOOG_CLIENT_ID,
          clientSecret: process.env.GOOG_CLIENT_SEC,
          callbackURL: 'http://localhost/auth/goog/callback',
        },
        async function(access_token, refresh_token, profile, cb) {
          console.log('Goog ', profile);
          let user = await this.findOrCreateUser('goog', profile);
          cb(null, user);
        }.bind(this)));

    passport.serializeUser(function(user, done) {
      console.log(user);
      done(null, user.user_id);
    });

    passport.deserializeUser(function(user_id, done) {
      this.findUser(user_id).then(function(user) {
        return done(null, user);
      });
    }.bind(this));
  }

  async findOrCreateUser(auth_type, profile) {
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
            profile.id, profile.displayName, profile.photos[0].value,
            profile.email, auth_type
          ]);
      /*
  result = await this.client.query(
      'SELECT * FROM users WHERE auth_type = $1::text AND auth_id = $2::text',
      [auth_type, id]);*/
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
            'content, password, author_id) VALUES ($1, $2, $3, $4, $5, $6, $7,' +
            ' $8, $9, $10, $11, $12) RETURNING *',
        [
          article_url, [], 0, 0, current_time, current_time, user.name,
          user.email, user.image, content, password, user.user_id
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

  setRoutes() {
    // Set up all the routes.
    this.app.get('/', (req, res) => res.send('Hello World!'));
    this.app.get('/profile', function(req, res) {
      if (req.user) {
        return res.send('name' + req.user.name);
      }
      res.send('name');
    });

    this.app.get('/:id', function(req, res) {
      let page_id = parseInt(req.params.id);
      let user = req.user;
      if (page_id <= 228) {
        res.render('page.ejs', {
          content_url: './old/blog_' + page_id + '.html',
          file_info: this.file_infos[page_id],
          page_infos: this.page_infos,
          file_infos: this.file_infos,
          user
        });
      }
    }.bind(this));

    this.app.post('/run', function(req, res) {
      let code = req.body.code;
      let stdin = req.body.stdin;

      if (!stdin) {
        stdin = '';
      }
      this.zmq_manager.sendCodeToRun(code, stdin, function(result) {
        if (result.exec_result.length > 0) {
          console.log('Execution result : \n', result.exec_result);
        } else {
          console.log('Compile error : \n', result.compile_error);
        }
        res.send(result);
      });
    }.bind(this));

    this.app.post('/get-comment', async function(req, res) {
      let id = req.body.id;
      const result = await this.client.query(
          'SELECT author_name, comment_date, modified_date, comment_id, content,' +
              'image_link, reply_ids, vote_up, vote_down, is_md FROM' +
              ' comment WHERE article_url = $1::text ORDER BY comment_id ASC',
          [id]);
      res.send(result.rows);
    }.bind(this));

    this.app.post('/write-comment', async function(req, res) {
      let parent_id = parseInt(req.body.parent_id);
      let content = req.body.content;
      let password = req.body.password;
      let article_url = req.body.article_url;
      let name = req.body.name;
      let user = req.user;
      if (!user) {
        user = {name, image: '', email: '', user_id: -1};
        console.log(user);
        if (!name) {
          return res.send({status: 'Failed', reason: 'Missing name'});
        }
        if (!password) {
          return res.send({status: 'Failed', reason: 'Missing password'});
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