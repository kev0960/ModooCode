var saved_htmls = {};
var editors = {}

function count_line(code) {
  var cnt = 0;
  for (var i = 0; i < code.length; i++) {
    if (code[i] == '\n') {
      cnt++;
    }
  }
  return cnt;
}

function min(a, b) {
  return a > b ? b : a;
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
      }
      $(this).attr('id', index);
      $(this).addClass('plain-code')

      $("<div class='button-group'><button class='edit' id='edit-" + index +
        "'><i class='fas fa-edit'></i>&nbsp;&nbsp;수정</button>" +
        "<button class='run' id='run-" + index + "'><i class='fas fa-cogs'>" +
        "</i>&nbsp;&nbsp;실행</button></div>").insertAfter($(this));
      if ($(this).height() > 500) {
        $("<div><button id='shrink-" + index + "'>Shrink</button></div>")
          .insertBefore($(this));
      }
      $('<pre id="result-' + index + '" style="display:none;"></pre>')
        .insertAfter($('#' + index).next());

      $('#edit-' + index).click(function () {
        var previous_height = count_line(code);
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
        var height = min($('#' + index).height(), 500);
        $('#' + index).height(height);
      });

      $('#run-' + index).click(function () {
        var id = parseInt($(this).attr('id').split('-')[1]);
        console.log("Send!")
        $.ajax({
                 type: 'POST',
                 url: '/run',
                 data: {
                   code: editors[id].getValue()
                 },
                 success: function (result) {
                   if (result.compile_error.length > 0) {
                     $('#result-' + index).text(result.compile_error);
                   } else {
                     $('#result-' + index).text(result.exec_result);
                   }
                   $('#result-' + index).show();
                 }
               });
      });
    });
  });
});
