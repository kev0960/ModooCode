var saved_htmls = {};
var editors = {};
var editor_deco = {};

function CountLine(code) {
  var cnt = 0;
  for (var i = 0; i < code.length; i++) {
    if (code[i] == '\n') {
      cnt++;
    }
  }
  return cnt;
}

function Min(a, b) {
  return a > b ? b : a;
}

function IsNumeric(value) {
  return /^-{0,1}\d+$/.test(value);
}

function FormatCompileError(msg, marked_lines) {
  var eol = 0, formatted = '';
  while (eol !== -1) {
    var begin = (eol === 0 ? -1 : eol);
    eol = msg.indexOf('\n', begin + 1);
    if (eol === -1) {
      var line = msg.substr(begin + 1);
    } else {
      var line = msg.substr(begin + 1, eol - begin - 1);
    }
    if (line.indexOf('<stdin>') === 0) {
      line = line.slice(7);
    }
    var line_number_end = line.indexOf(':', 1);
    var line_number = line.substr(1, line_number_end - 1);
    if (IsNumeric(line_number)) {
      marked_lines.add(parseInt(line_number));
      line = line.slice(1);
      line = "줄 " + line;
    } else {
      if (line[0] == ':') {
        line = line.slice(1);
      }
    }
    formatted += (line + "\n");
  }
  return formatted;
}

var page_infos, file_info;

function InitCategory() {
  function GetPagePathFromNavId(elem) {
    var path = [elem.attr('name')];
    while (elem.parent().attr('class').indexOf('inner-menu') !== -1) {
      elem = elem.parent().prev();
      path.unshift(elem.attr('name'));
    }
    return path;
  }

  function GetFilesFromPath(path) {
    var current_dir = page_infos[""];
    for (var i = 0; i < path.length; i++) {
      current_dir = current_dir[path[i]];
    }
    return current_dir;
  }

  page_infos = JSON.parse($('#page-infos').html());
  file_infos = JSON.parse($('#file-infos').text());
  $(document).on('click', '.sidebar-nav-item.dir', function () {
    var path = GetPagePathFromNavId($(this));
    if ($(this).hasClass('open-cat')) {
      // Clicked the opened category; Need to collapse.
      $(this).removeClass('open-cat');
      // Remove all the child categories.
      $(this).next().remove();

      var html = $(this).html();
      html = html.replace("<i class=\"fas fa-caret-down\"></i>",
                          "<i class=\"fas fa-plus-square\" style=\"font-size:0.75em;\"></i>");
      $(this).html(html);

    } else {
      // Clicked the collapsed category; Need to open it.
      $(this).addClass('open-cat');
      var html = $(this).html();
      html = html.replace(
        "<i class=\"fas fa-plus-square\" style=\"font-size:0.75em;\"></i>",
        "<i class='fas fa-caret-down'></i>");
      $(this).html(html);

      // Get the directory.
      var current_dir = GetFilesFromPath(path);
      // Add directories.
      var folders = Object.keys(current_dir);
      var div = $("<div>", {'class': 'inner-menu' + path.length});
      for (var i = 0; i < folders.length; i++) {
        if (folders[i] !== 'files') {
          var dir_folders = Object.keys(current_dir[folders[i]]);
          var folder_html = folders[i];
          if (dir_folders.length >= 2 ||
              current_dir[folders[i]]["files"].length > 0) {
            folder_html = "<i class=\"fas fa-plus-square\" " +
                          "style=\"font-size:0.75em;\"></i>&nbsp;&nbsp;" +
                          folder_html;
          }
          div.append($("<a>", {
            'class': 'sidebar-nav-item dir',
            'html': folder_html,
            'name': folders[i],
          }));
        }
      }
      // Add files.
      for (var i = 0; i < current_dir.files.length; i++) {
        var file_id = current_dir.files[i];
        var cat_title = file_infos[file_id].title;
        if (file_infos[file_id].cat_title) {
          cat_title = file_infos[file_id].cat_title;
        }
        console.log(file_infos[file_id])
        div.append($("<a>", {
          'class': 'sidebar-nav-item file',
          'text': cat_title,
          'href': file_id,
          'name': cat_title
        }));
      }
      div.insertAfter($(this));
    }
  });
}

function CloseSidebar() {
  // Close
  $('#sidebar').hide();
  $('#open-sidebar').show();

  localStorage.setItem('sidebar', 'closed');
  if (window.matchMedia('(max-width: 767px)').matches) {
    $('.wrap').css({'margin-left': '0', 'width': '100%'});
  } else if (window.matchMedia(
    '(min-width: 768px) and (max-width: 992px)').matches) {
    $('.wrap')
      .css({'margin-left': '5%', 'margin-right': '5%', 'width': '90%'});
  } else if (window.matchMedia(
    '(min-width: 993px) and (max-width: 1200px)').matches) {
    $('.wrap')
      .css({'margin-left': '10%', 'margin-right': '10%', 'width': '80%'});
  } else if (window.matchMedia(
    '(min-width: 1200px)').matches) {
    $('.wrap')
      .css({'margin-left': '15%', 'margin-right': '15%', 'width': '70%'});
  }
}

function OpenSidebar() {
  $('#sidebar').show();
  $('#open-sidebar').hide();

  localStorage.setItem('sidebar', 'opened');
  if (window.matchMedia('(max-width: 767px)').matches) {
    $('.wrap').css({'margin-left': '30%', 'width': '70%'});
  } else if (window.matchMedia(
    '(min-width: 768px) and (max-width: 992px)').matches) {
    $('.wrap')
      .css({'margin-left': '25%', 'width': '75%'});
  } else if (window.matchMedia(
    '(min-width: 993px) and (max-width: 1200px)').matches) {
    $('.wrap')
      .css({'margin-left': '20%', 'width': '80%'});
  } else if (window.matchMedia(
    '(min-width: 1200px)').matches) {
    $('.wrap')
      .css({'margin-left': '30%', 'width': '70%'});
  }
}

$(function () {
  require.config({paths: {'vs': '/lib/monaco-editor/min/vs'}});
  require(['vs/editor/editor.main'], function () {
    $('pre.chroma').each(function (index) {
      var code = $(this).text();

      // Check whether the code starts with #include. If it is, then it is
      // probably executable.
      if (code[0] != '#' && code[0] != '/') {
        return;
      } else if (code.indexOf('main') == -1) {
        return;
      }

      $(this).attr('id', index);
      $(this).addClass('plain-code')

      $("<div class='button-group'><label class='stdin-label' for='stdin-"
        + index + "'>입력</label><input type='text' class='stdin' " +
        "id='stdin-" + index + "' name='stdin-" + index + "' placeholder='" +
        "프로그램 입력값을 여기에 입력하세요.'>" +
        "<button class='edit' id='edit-" + index +
        "'><i class='fas fa-edit'></i>&nbsp;&nbsp;코드 수정</button>" +
        "<button class='run' id='run-" + index + "'><i class='fas fa-cogs'>" +
        "</i>&nbsp;&nbsp;실행</button></div>").insertAfter($(this));
      if ($(this).height() > 500) {
        $("<div><button id='shrink-" + index + "'>Shrink</button></div>")
          .insertBefore($(this));
      }
      $('<div style="display:none;"><p class="exec-result-title">실행 결과</p>' +
        '<pre id="result-' + index + '" class="exec-result"></pre></div>')
        .insertAfter($('#' + index).next());

      $('#edit-' + index).click(function () {
        var previous_height = CountLine(code);
        var current_code_box = '#' + index;
        $(current_code_box).empty();
        $(current_code_box).height(16 * previous_height + 60);
        var new_div = $(
          "<div id='div-" + index + "' class='monaco-container'></div>")
          .height(16 * previous_height + 15);
        $(current_code_box).append(new_div);
        editors[index] = monaco.editor.create(
          document.getElementById('div-' + index), {
            value: code,
            language: 'cpp'
          });
        $('#' + index).removeClass('plain-code');
      });

      $(this).css({'margin-bottom': '3px'});

      $('#shrink-' + index).click(function () {
        var height = Min($('#' + index).height(), 500);
        $('#' + index).height(height);
      });

      $('#run-' + index).click(function () {
        var id = parseInt($(this).attr('id').split('-')[1]);
        var code = '';
        if ($('#' + id).hasClass('plain-code')) {
          code = $('#' + id).text();
        } else {
          code = editors[id].getValue();
        }
        $.ajax({
                 type: 'POST',
                 url: '/run',
                 data: {
                   code: code,
                   stdin: $('#stdin-' + id).val()
                 },
                 success: function (result) {
                   var is_editor = !$('#' + id).hasClass('plain-code');

                   if (is_editor) {
                     var deco = editors[id].getModel().getAllDecorations();
                     for (var i = 0; i < deco.length; i++) {
                       deco[i].options = {linesDecorationsClassName: ''};
                     }
                     editor_deco[id] = editors[id].deltaDecorations([], deco);
                   }

                   if (result.compile_error.length > 0) {
                     var marked_lines = new Set();
                     formatted =
                       FormatCompileError(result.compile_error, marked_lines);
                     console.log(marked_lines)
                     $('#result-' + index).text(formatted);

                     if (is_editor) {
                       marked_lines.forEach(
                         function (line_num) {
                           console.log('line num ', line_num)
                           editor_deco[id] =
                             editors[id].deltaDecorations([], [
                               {
                                 range: new monaco.Range(line_num, 1, line_num,
                                                         1),
                                 options: {
                                   isWholeLine: true,
                                   linesDecorationsClassName: 'compiler-error-line'
                                 }
                               },
                             ]);
                         }
                       );
                     }
                     $('#result-' + index).prev().html(
                       "실행 결과<span class='compile-error-title'>컴파일 오류</span>")
                   }
                   else {
                     $('#result-' + index).text(result.exec_result);
                     $('#result-' + index).prev().html(
                       "실행 결과<span class='run-success-title'>실행 성공</span>")
                   }
                   $('#result-' + index).parent().show();
                 }
               });
      });
    });
  });
  InitCategory();

  var sidebar_status = localStorage.getItem('sidebar');
  if (!sidebar_status) {
    localStorage.setItem('sidebar', 'opened');
  }

  console.log(sidebar_status)
  if (sidebar_status == 'closed') {
    $('#sidebar').hide();
    $('#open-sidebar').show();
    CloseSidebar();
  } else {
    $('#sidebar').show();
    $('#open-sidebar').hide();
    OpenSidebar();
  }

  $('#hide-sidebar').click(function () {
    var status = localStorage.getItem('sidebar');
    if (status == 'opened') {
      CloseSidebar();
    }
  });

  $('#open-sidebar-btn').click(function () {
    var status = localStorage.getItem('sidebar');
    if (status == 'closed') {
      // show
      OpenSidebar();
    }
  });

  $('#open-comment').click(function () {
    var url = window.location.pathname;
    var article_id = url.substr(url.lastIndexOf('/') + 1);
    $.ajax({
             type: 'post',
             url: '/get-comment',
             data: {
               id: article_id
             },
             success: function (res) {
               console.log(res);
             }
           });
  });
});
