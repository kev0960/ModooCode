const editors = {};
const editor_deco = {};
let current_comment_index = 0;

let total_comment_list = null;
let parent_comment_list = [];
let current_added_comment_box = null;
let selected_comment_id = -1;
let already_added = false;


function countLine(code) {
  let cnt = 0;
  for (let i = 0; i < code.length; i++) {
    if (code[i] === '\n') {
      cnt += 1;
    }
  }
  return cnt;
}

function min(a, b) {
  return a > b ? b : a;
}

function isNumeric(value) {
  return /^-{0,1}\d+$/.test(value);
}

function FormatCompileError(msg, marked_lines) {
  let eol = 0;
  let formatted = '';
  while (eol !== -1) {
    const begin = (eol === 0 ? -1 : eol);
    let line = '';
    eol = msg.indexOf('\n', begin + 1);
    if (eol === -1) {
      line = msg.substr(begin + 1);
    } else {
      line = msg.substr(begin + 1, eol - begin - 1);
    }
    if (line.indexOf('<stdin>') === 0) {
      line = line.slice(7);
    }
    const line_number_end = line.indexOf(':', 1);
    const line_number = line.substr(1, line_number_end - 1);
    if (isNumeric(line_number)) {
      marked_lines.add(parseInt(line_number));
      line = line.slice(1);
      line = '줄 ' + line;
    } else if (line[0] == ':') {
      line = line.slice(1);
    }
    formatted += ('' + line + '\n');
  }
  return formatted;
}

let page_infos;
let file_infos;
let our_page_in_category;

function initCategory() {
  function GetPagePathFromNavId(elem) {
    const path = [elem.attr('name')];
    while (elem.parent().attr('class').indexOf('inner-menu') !== -1) {
      elem = elem.parent().prev();
      path.unshift(elem.attr('name'));
    }
    return path;
  }

  function GetFilesFromPath(path) {
    let current_dir = page_infos[''];
    for (let i = 1; i < path.length; i++) {
      current_dir = current_dir[path[i]];
    }
    return current_dir;
  }

  page_infos = JSON.parse($('#page-infos').html());
  file_infos = JSON.parse($('#file-infos').text());

  $(document).on('click', '.sidebar-nav-item.dir', function() {
    const path = GetPagePathFromNavId($(this));
    let html = '';
    if ($(this).hasClass('open-cat')) {
      // Clicked the opened category; Need to collapse.
      $(this).removeClass('open-cat');
      // Remove all the child categories.
      $(this).next().remove();

      html = $(this).html();
      html = html.replace(
          '<i class="xi-caret-down-min" style="font-size:0.75em;"></i>',
          '<i class="xi-plus-square" style="font-size:0.75em;"></i>');
      $(this).html(html);
    } else {
      // Clicked the collapsed category; Need to open it.
      $(this).addClass('open-cat');
      html = $(this).html();
      html = html.replace(
          '<i class="xi-plus-square" style="font-size:0.75em;"></i>',
          '<i class="xi-caret-down-min" style="font-size:0.75em;"></i>');
      html = html.replace(
          '<i class="xi-plus-square" style="font-size:0.75em;"></i>',
          '<i class="xi-caret-down-min" style="font-size:0.75em;"></i>');
      $(this).html(html);

      // Get the directory.
      const current_dir = GetFilesFromPath(path);

      // Add directories.
      const folders = Object.keys(current_dir);
      const div = $('<div>', {class: 'inner-menu' + path.length});
      if (path.length > 0 && path[0] == 'X86-64 명령어 레퍼런스') {
        folders.sort();
      }

      for (let i = 0; i < folders.length; i++) {
        if (folders[i] !== 'files') {
          const dir_folders = Object.keys(current_dir[folders[i]]);
          let folder_html = folders[i];
          if (dir_folders.length >= 2 ||
              current_dir[folders[i]].files.length > 0) {
            folder_html =
                '<i class="xi-plus-square" style="font-size:0.75em;"></i>' +
                '&nbsp;&nbsp;' + folder_html;
          }
          div.append($('<a>', {
            class: 'sidebar-nav-item dir',
            html: folder_html,
            name: folders[i],
          }));
        }
      }
      // Add files.
      for (let i = 0; i < current_dir.files.length; i++) {
        const file_id = current_dir.files[i];
        let cat_title = file_infos[file_id].title;
        if (file_infos[file_id].cat_title) {
          cat_title = file_infos[file_id].cat_title;
        }
        div.append($('<a>', {
          class: 'sidebar-nav-item file',
          text: cat_title,
          href: '/' + file_id,
          name: cat_title,
        }));
      }
      div.insertAfter($(this));

      const elem =
          $('.sidebar-nav-item[href="' + window.location.pathname + '"]');
      elem.css('background-color', 'rgba(255, 255, 255, .33)');
    }
  });
}

function closeSidebar() {
  // Close
  $('#sidebar').hide();
  $('#open-sidebar').show();

  localStorage.setItem('sidebar', 'closed');
  if (window.matchMedia('(max-width: 634px)').matches) {
    $('.wrap').css({'margin-left': '0%'});
  } else if (window.matchMedia('(min-width: 635px) and (max-width: 767px)')
                 .matches) {
    $('.wrap').css({'margin-left': '0', width: '100%'});
  } else if (window.matchMedia('(min-width: 768px) and (max-width: 992px)')
                 .matches) {
    $('.wrap').css({'margin-left': '5%', 'margin-right': '5%', width: '90%'});
  } else if (window.matchMedia('(min-width: 993px) and (max-width: 1200px)')
                 .matches) {
    $('.wrap').css({'margin-left': '10%', 'margin-right': '10%', width: '80%'});
  } else if (window.matchMedia('(min-width: 1200px)').matches) {
    $('.wrap').css({'margin-left': '15%', 'margin-right': '15%', width: '70%'});
  }
}

function openSidebar() {
  $('#sidebar').show();
  $('#open-sidebar').hide();

  localStorage.setItem('sidebar', 'opened');
  if (window.matchMedia('(max-width: 634px)').matches) {
    $('.wrap').css({'margin-left': '50%', width: '100%'});
  } else if (window.matchMedia('(min-width: 635px) and (max-width: 767px)')
                 .matches) {
    $('.wrap').css({'margin-left': '30%', width: '70%'});
  } else if (window.matchMedia('(min-width: 768px) and (max-width: 1200px)')
                 .matches) {
    $('.wrap').css({'margin-left': '25%', width: '75%'});
  } else if (window.matchMedia('(min-width: 1200px)').matches) {
    $('.wrap').css({'margin-left': '25%', width: '80%'});
  }
}

function ProcessComment(comment_list) {
  const children_set = new Set();
  total_comment_list = new Map();
  for (let i = 0; i < comment_list.length; i++) {
    for (let j = 0; j < comment_list[i].reply_ids.length; j++) {
      children_set.add(comment_list[i].reply_ids[j]);
    }
    total_comment_list.set(comment_list[i].comment_id, comment_list[i]);
  }

  for (let i = 0; i < comment_list.length; i++) {
    if (!children_set.has(comment_list[i].comment_id)) {
      parent_comment_list.push(comment_list[i].comment_id);
    }
  }
  parent_comment_list = parent_comment_list.reverse();
}

function RecursiveCommentAdder(ul, comment_id) {
  // Add current comment.
  const current_comment = total_comment_list.get(comment_id);
  if (!current_comment) {
    return;
  }

  // Do not display deleted comment only if it does not have any replies.
  if (current_comment.is_deleted && current_comment.reply_ids.length == 0) {
    return;
  }

  const li = $('<li>', {class: 'comment'});
  const div_profile = $('<div>', {class: 'comment-profile'});
  let img_src = '/img/unknown_person.png';
  if (current_comment.image_link.length) {
    img_src = current_comment.image_link;
  }
  div_profile.append($('<img>', {src: img_src, alt: '프로필 사진없음'}));
  li.append(div_profile);

  const div_comment_info = $('<div>', {class: 'comment-info'});
  const div_comment_header = $('<div>', {class: 'comment-header'});
  div_comment_header.append($('<span>', {
                              class: 'comment-author',
                            }).text(current_comment.author_name));
  div_comment_header.append($('<span>', {
                              class: 'comment-date',
                            }).text(current_comment.comment_date));
  div_comment_info.append(div_comment_header);

  div_comment_info.append(
      $('<div>', {class: 'comment-content'}).text(current_comment.content));

  const div_comment_action =
      $('<div>', {class: 'comment-action', id: 'comment-id-' + comment_id});
  div_comment_action.append(
      $('<span>', {class: 'comment-upvote'}).text('추천'));
  div_comment_action.append(
      $('<span>', {class: 'comment-reply'}).text('답글 달기'));
  div_comment_action.append(
      $('<span>', {class: 'comment-delete'}).text('답글 삭제'));
  div_comment_info.append(div_comment_action);
  li.append(div_comment_info);

  ul.append(li);

  const reply_ids = current_comment.reply_ids;
  if (reply_ids.length > 0) {
    const child_ul = $('<ul>', {class: 'comment-list'});
    for (let i = 0; i < reply_ids.length; i++) {
      RecursiveCommentAdder(child_ul, reply_ids[i]);
    }
    ul.append(child_ul);
  }
}

function addComment(num_comment) {
  const ul = $('#root-comment-list');
  for (let i = current_comment_index;
       i < min(current_comment_index + num_comment, parent_comment_list.length);
       i++) {
    RecursiveCommentAdder(ul, parent_comment_list[i]);
  }
  current_comment_index += num_comment;
  if (current_comment_index > parent_comment_list.length) {
    $('#button-box').hide();
  }
  /* Image fallback */
  $(document).ready(function() {
    $('.comment-profile img').on('error', function() {
      $(this).attr('src', './img/unknown_person.png');
    });
  });
}

function isAllowedToComment() {
  if ($('#username') && $('#username').text()) {
    return true;
  }
  if ($('#name').text() && $('#password').text()) {
    return true;
  }
  return false;
}

function postComment() {
  $('#adding-comment').show();
  postGenericComment(
      -1, $('#posted-comment').val(), $('#password').val(), $('#name').val());
}

function postReply(parent_id) {
  postGenericComment(
      parent_id, $('#posted-reply').val(), $('#reply-password').val(),
      $('#reply-id').val());
}

function postGenericComment(parent_id, content, password, name) {
  const url = window.location.href;
  const article_url = url.substr(url.lastIndexOf('/') + 1);
  grecaptcha.ready(function() {
    grecaptcha
        .execute(
            '6LeE_nYUAAAAAGm9qTa71IwvvayWV9Q7flqNkto2', {action: 'Comment'})
        .then(function(token) {
          fetch('/write-comment', {
            method: 'POST',
            mode: 'cors',
            cache: 'no-cache',
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify({
              parent_id: parent_id,
              content: content,
              password: password || '',
              author_name: name,
              article_url: article_url,
              captcha_token: token,
            })
          }).then(data => {
            $('#adding-comment').hide();
              location.reload();
          });
        });
  });
}

function loadComment() {
  var url = window.location.pathname;
  var article_id = url.substr(url.lastIndexOf('/') + 1);

  $.ajax({
    type: 'post',
    url: '/get-comment',
    data: {id: article_id, index_start: current_comment_index},
    success: function(res) {
      ProcessComment(res);

      // If there was a redirect info, then we have to set it.
      let redirect_info = window.localStorage.getItem('redirect-info');
      if (!redirect_info) {
        addComment(50);
        return;
      }
      redirect_info = JSON.parse(redirect_info);
      let current_url = redirect_info.current_url;
      let content_new_comment = redirect_info.content_new_comment;
      let content_new_reply = redirect_info.content_new_reply;
      addComment(redirect_info.current_comment_index);

      if (content_new_comment) {
        $('#posted-comment').val(content_new_comment);
      }
      if (content_new_reply) {
        selected_comment_id = redirect_info.selected_comment_id;
        createReply.bind(
            $('#comment-id-' + selected_comment_id).find('.comment-reply'))();
        $('#posted-reply').val(content_new_reply);
      }
      if (!content_new_comment && content_new_reply) {
        $('html, body')
            .animate({scrollTop: $('#posted-reply').offset().top - 300}, 10);
      } else {
        $('html, body')
            .animate({scrollTop: $('#posted-comment').offset().top - 300}, 10);
      }
      window.localStorage.removeItem('redirect-info');
    }
  });
}

function createReply() {
  if (current_added_comment_box) {
    // Remove previously created reply box to reduce confusion.
    current_added_comment_box.remove();
  }
  let reply_box = $('#comment-post-section').clone();
  reply_box.attr('id', 'comment-reply-section');
  reply_box.find('#posted-comment').attr('id', 'posted-reply');
  reply_box.find('#name').attr('id', 'reply-id');
  reply_box.find('#password').attr('id', 'reply-password');
  reply_box.find('#post-comment').attr('id', 'post-reply');

  reply_box.insertAfter($(this).parent().parent().parent());
  current_added_comment_box = reply_box;
}

function createCodeExecute(elem, index) {
  let code = elem.text();

  let code_language = '';
  if (elem.attr('class').indexOf('py') !== -1) {
    code_language =
        '<button class=\'code-language python\'><i class=\'xi-file-text-o\'>' +
        '</i>&nbsp;Python</button>';
  } else if (elem.attr('class').indexOf('cpp') !== -1) {
    code_language =
        '<button class=\'code-language cpp\'><i class=\'xi-file-text-o\'>' +
        '</i>&nbsp;C/C++</button>';
  }

  let code_font_change_and_lang = code_language +
      '<button class="shrink-btn" id=\'code-font-large-' + index +
      '\'><i class="xi-zoom-in"></i>&nbsp;확대</button>' +
      '<button class="shrink-btn" id=\'code-font-small-' + index +
      '\'><i class="xi-zoom-out"></i>&nbsp;축소</button>';

  if (elem.height() > 300) {
    $('<div><button class="shrink-btn" id=\'shrink-' + index +
      '\'><i class="xi-angle-up"></i>&nbsp;코드 크기 줄이기</button>' +
      code_font_change_and_lang + '</div>')
        .insertBefore(elem);
  } else {
    $('<div>' + code_font_change_and_lang + '</div>').insertBefore(elem);
  }

  $('#shrink-' + index).click(function() {
    let height = min($('#' + index).height(), 300);
    $('#' + index).height(height);
  });

  $('#code-font-large-' + index).click(function() {
    let current_font_size = parseInt($('#' + index).css('font-size'));
    current_font_size++;
    $('#' + index).css('font-size', current_font_size + 'px');
  });

  $('#code-font-small-' + index).click(function() {
    let current_font_size = parseInt($('#' + index).css('font-size'));
    current_font_size--;
    $('#' + index).css('font-size', current_font_size + 'px');
  });

  elem.attr('id', index);

  // Check whether the code starts with #include. If it is, then it is
  // probably executable.
  if ((code[0] != '#' && code[0] != '/') || code.indexOf('main') == -1) {
    return;
  }

  elem.addClass('plain-code')
  $('<div class=\'button-group\'><label class=\'stdin-label\' for=\'stdin-' +
    index + '\'>입력</label><input type=\'text\' class=\'stdin\' ' +
    'id=\'stdin-' + index + '\' name=\'stdin-' + index + '\' placeholder=\'' +
    '프로그램 입력값을 여기에 입력하세요.\'>' +
    '<button class=\'edit\' id=\'edit-' + index +
    '\'><i class=\'xi-pen\'></i><span class="btn-text">&nbsp;&nbsp;코드 수정</span></button>' +
    '<button class=\'run\' id=\'run-' + index + '\'><i class=\'xi-refresh\'>' +
    '</i><span class="btn-text">&nbsp;&nbsp;실행</span></button></div>')
      .insertAfter(elem);

  $('<div style="display:none;"><p class="exec-result-title">실행 결과</p>' +
    '<pre id="result-' + index + '" class="exec-result"></pre></div>')
      .insertAfter($('#' + index).next());

  $('#edit-' + index).click(function() {
    require(['vs/editor/editor.main'], function() {
      let previous_height = countLine(code);
      let current_code_box = '#' + index;
      console.log(
          'current code box ', $(current_code_box),
          $(current_code_box).height());

      $(current_code_box).empty();
      $(current_code_box).height(19 * previous_height + 30);
      $(current_code_box).css('padding', '5px');
      let new_div =
          $('<div id=\'div-' + index + '\' class=\'monaco-container\'></div>')
              .height(19 * previous_height + 30);
      $(current_code_box).append(new_div);
      editors[index] = monaco.editor.create(
          document.getElementById('div-' + index),
          {value: code, language: 'cpp'});
      $('#' + index).removeClass('plain-code');
    });
  });

  elem.css({'margin-bottom': '3px'});

  $('#run-' + index).click(function() {
    let id = parseInt(elem.attr('id'));
    let code = '';
    if ($('#' + id).hasClass('plain-code')) {
      code = $('#' + id).text();
    } else {
      code = editors[id].getValue();
    }
    gtag(
        'event', 'execute-code',
        {'event_category': 'code', 'event_label': 'cpp'});

    $('#result-' + index).parent().show();
    $('#result-' + index)
        .prev()
        .html(
            '실행 중 <div class="lds-ring"><div></div><div></div><div></div><div></div></div>');
    $.ajax({
      type: 'POST',
      url: '/run',
      data: {code: code, stdin: $('#stdin-' + id).val()},
      success: function(result) {
        let is_editor = !$('#' + id).hasClass('plain-code');

        if (is_editor) {
          let deco = editors[id].getModel().getAllDecorations();
          for (var i = 0; i < deco.length; i++) {
            deco[i].options = {linesDecorationsClassName: ''};
          }
          editor_deco[id] = editors[id].deltaDecorations([], deco);
        }

        if (result.compile_error.length > 0) {
          let marked_lines = new Set();
          formatted = FormatCompileError(result.compile_error, marked_lines);
          $('#result-' + index).text(formatted);

          if (is_editor) {
            marked_lines.forEach(function(line_num) {
              editor_deco[id] = editors[id].deltaDecorations([], [
                {
                  range: new monaco.Range(line_num, 1, line_num, 1),
                  options: {
                    isWholeLine: true,
                    linesDecorationsClassName: 'compiler-error-line'
                  }
                },
              ]);
            });
          }
          $('#result-' + index)
              .prev()
              .html(
                  '실행 결과<span class=\'compile-error-title\'>컴파일 오류</span>');
          gtag(
              'event', 'execute-code-fail',
              {'event_category': 'code', 'event_label': 'cpp'});
        } else {
          $('#result-' + index).text(result.exec_result);
          $('#result-' + index)
              .prev()
              .html(
                  '실행 결과<span class=\'run-success-title\'>실행 성공</span>');
          gtag(
              'event', 'execute-code-success',
              {'event_category': 'code', 'event_label': 'cpp'});
        }
      }
    });
  });
}

window.onload = function() {
  BuildTOC();
  $('pre.chroma').each(function(index) {
    createCodeExecute($(this), index);
  });
  initCategory();

  let sidebar_status = localStorage.getItem('sidebar');
  if (!sidebar_status) {
    localStorage.setItem('sidebar', 'opened');
  }

  if (sidebar_status == 'closed' ||
      window.matchMedia('(max-width: 634px)').matches) {
    $('#sidebar').hide();
    $('#open-sidebar').show();
    closeSidebar();
  } else {
    $('#sidebar').show();
    $('#open-sidebar').hide();
    openSidebar();
  }

  // Handle sidebars.
  $('#hide-sidebar').click(function() {
    let status = localStorage.getItem('sidebar');
    if (status == 'opened') {
      closeSidebar();
    }
  });

  $('#open-sidebar-btn').click(function() {
    let status = localStorage.getItem('sidebar');
    if (status == 'closed') {
      // show
      openSidebar();
    }
  });

  // Handle comment.
  loadComment();
  $('#open-comment').click(function() {
    addComment(50);
  });

  $(document).on('click', '.comment-reply', function() {
    selected_comment_id = $(this).parent().attr('id');
    selected_comment_id = parseInt(
        selected_comment_id.substr(selected_comment_id.lastIndexOf('-') + 1));
    createReply.bind(this)();
  });

  function deleteComment(comment_id, password) {
    $.ajax({
      type: 'POST',
      url: '/delete-comment',
      data: {comment_id: comment_id, password: password},
      success: function(data) {
        location.reload();
      }
    });
  }

  $(document).on('click', '.comment-delete', function() {
    selected_comment_id = $(this).parent().attr('id');
    selected_comment_id = parseInt(
        selected_comment_id.substr(selected_comment_id.lastIndexOf('-') + 1));

    // If the user has not logged in, open the dialog to let them enter the
    // password.
    if ($('#username').text().length == 0) {
      if (!$('#delete-btn-' + selected_comment_id).length) {
        $('<button id="delete-btn-' + selected_comment_id +
          '" class="delete-btn">확인</button>')
            .insertAfter(this);
        $('<input type="password" id="delete-password-' + selected_comment_id +
          '" class="delete-password">')
            .insertAfter(this);
        $('<label for="delete-password-' + selected_comment_id +
          '" class="delete-password-label">댓글 비밀번호 :</label>')
            .insertAfter(this);
      }
    } else {
      deleteComment(selected_comment_id, '');
    }
  });

  $(document).on('click', '.delete-btn', function() {
    selected_comment_id = $(this).attr('id');
    selected_comment_id = parseInt(
        selected_comment_id.substr(selected_comment_id.lastIndexOf('-') + 1));
    deleteComment(
        selected_comment_id,
        $('#delete-password-' + selected_comment_id).val());
  });

  $(document).on('click', '#post-reply', function() {
    postReply(selected_comment_id);
  });


  $('#post-comment').click(function() {
    postComment();
  })

  // Handle authentication.
  $(document).on('click', '.fb-login', function() {
    let current_url = window.location.href;
    let content_new_comment = $('#posted-comment').val();
    let content_new_reply = undefined;
    if ($('#posted-reply').length) {
      content_new_reply = $('#posted-reply').val();
    }
    localStorage.setItem('redirect-info', JSON.stringify({
      current_url: current_url,
      current_comment_index: current_comment_index,
      content_new_comment: content_new_comment,
      content_new_reply: content_new_reply,
      selected_comment_id: selected_comment_id
    }));
    window.location.href = '/auth/fb';
  });

  $(document).on('click', '.social-login', function() {
    console.log("G id onload!");
    let current_url = window.location.href;
    let content_new_comment = $('#posted-comment').val();
    let content_new_reply = undefined;
    if ($('#posted-reply').length) {
      content_new_reply = $('#posted-reply').val();
    }
    window.localStorage.setItem('redirect-info', JSON.stringify({
      current_url: current_url,
      current_comment_index: current_comment_index,
      content_new_comment: content_new_comment,
      content_new_reply: content_new_reply,
      selected_comment_id: selected_comment_id
    }));
    window.location.href = '/auth/goog';
  });

  window.onresize =
      function() {
    $('.sidenote').each(function(index) {
      if ($(this).css('position') == 'absolute') {
        if (!already_added) {
          $(this).css('top', '-=40');
          already_added = true;
        }
      } else {
        already_added = false;
      }
    })
  }

      $('img')
          .click(function(e) {

          });

  require.config({paths: {'vs': '/lib/monaco-editor/min/vs'}});
};

document.addEventListener('DOMContentLoaded', function() {
  elems = document.querySelectorAll('.math-latex');
  for (let i = 0; i < elems.length; i++) {
    renderMathInElement(elems[i], {
      delimiters: [
        {left: '$$', right: '$$', display: true},
        {left: '$', right: '$', display: false}
      ]
    });
  }
});

function BuildTOC() {
  let toc_infos = [];
  $(':header').each(function() {
    let id = $(this).attr('id');
    let tag = $(this).prop('nodeName');
    let content = $(this).text();
    if (!id) {
      return;
    }
    toc_infos.push({id: id, tag: tag, content: content});
  });
  for (let i = 0; i < toc_infos.length; i++) {
    let elem =
        $('<li></ul><a href="#' + toc_infos[i].id + '" class="toc-' +
          toc_infos[i].tag + '">' + toc_infos[i].content + '</a></li>');
    $('#toc').append(elem);
  }
}

function GoogleSignIn(sign_in) {
  fetch('/auth/goog', {
    method: 'post',
    headers: {
      'Accept': 'application/json',
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      token: sign_in.credential
    }),
  }).then(function(response) {
    let current_url = window.location.href;
    let content_new_comment = $('#posted-comment').val();
    let content_new_reply = undefined;
    if ($('#posted-reply').length) {
      content_new_reply = $('#posted-reply').val();
    }
    localStorage.setItem('redirect-info', JSON.stringify({
      current_url: current_url,
      current_comment_index: current_comment_index,
      content_new_comment: content_new_comment,
      content_new_reply: content_new_reply,
      selected_comment_id: selected_comment_id
    }));

    location.reload();
  });
}
