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

function escapeHTML(html) {
  return html
         .replace(/&/g, "&amp;")
         .replace(/</g, "&lt;")
         .replace(/>/g, "&gt;")
         .replace(/"/g, "&quot;")
         .replace(/'/g, "&#039;");
}

function normalizeDate(date) {
  let dates = date.split('-');
  for (let i = 0; i < dates.length; i ++) {
    if (dates[i].length < 2) {
      dates[i] = '0' + dates[i];
    }
  }
  return dates.join('-');
}

module.exports = {
  getDateTime,
  escapeHTML,
  normalizeDate
};