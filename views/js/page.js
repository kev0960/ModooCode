var saved_htmls = {};

function count_line(code) {
  var cnt = 0;
  for (var i = 0; i < code.length; i++) {
    if (code[i] == '\n') {
      cnt++;
    }
  }
  return cnt;
}

$(function () {
  require.config({paths: {'vs': '/lib/monaco-editor/min/vs'}});
  require(['vs/editor/editor.main'], function () {
  });
  $('pre.chroma').each(function (index) {
    var code = $(this).text();

    // Check whether the code starts with #include. If it is, then it is probably executable.
    if (code[0] != '#' && code[0] != '/') {
      return;
    }
    $(this).attr('id', index);

    $("<button class='edit' id='edit-" + index + "'><i class='fas fa-edit'>" +
      "</i>&nbsp;&nbsp;Edit</button>" +
      "<button class='run' id='run-" + index + "'><i class='fas fa-cogs'>" +
      "</i>&nbsp;&nbsp;Run</button>").insertBefore($(this));

    $('#edit-' + index).click(function () {
      var previous_height = count_line(code);
      var current_code_box = '#' + index;
      $(current_code_box).empty();
      $(current_code_box).height(19 * previous_height);
      var new_div = $("<div id='div-" + index + "' class='monaco-container'></div>")
        .height(19 * previous_height);
      $(current_code_box).append(new_div);
      monaco.editor.create(document.getElementById('div-' + index), {
        value: code,
        language: 'cpp'
      });
      //$('#' + index + ' .monaco-editor').height(previous_height);
    });
  });
});