(()=>{var e={778:()=>{window.onGoogleLogin=function(e){fetch("/auth/goog",{method:"post",headers:{Accept:"application/json","Content-Type":"application/json"},body:JSON.stringify({token:e.credential})}).then((function(e){console.log(e),location.reload()}))}}},t={};function n(o){var r=t[o];if(void 0!==r)return r.exports;var i=t[o]={exports:{}};return e[o](i,i.exports,n),i.exports}(()=>{"use strict";var e=function(e,t,n,o){return new(n||(n=Promise))((function(r,i){function a(e){try{l(o.next(e))}catch(e){i(e)}}function c(e){try{l(o.throw(e))}catch(e){i(e)}}function l(e){var t;e.done?r(e.value):(t=e.value,t instanceof n?t:new n((function(e){e(t)}))).then(a,c)}l((o=o.apply(e,t||[])).next())}))},t=function(e,t){var n,o,r,i,a={label:0,sent:function(){if(1&r[0])throw r[1];return r[1]},trys:[],ops:[]};return i={next:c(0),throw:c(1),return:c(2)},"function"==typeof Symbol&&(i[Symbol.iterator]=function(){return this}),i;function c(c){return function(l){return function(c){if(n)throw new TypeError("Generator is already executing.");for(;i&&(i=0,c[0]&&(a=0)),a;)try{if(n=1,o&&(r=2&c[0]?o.return:c[0]?o.throw||((r=o.return)&&r.call(o),0):o.next)&&!(r=r.call(o,c[1])).done)return r;switch(o=0,r&&(c=[2&c[0],r.value]),c[0]){case 0:case 1:r=c;break;case 4:return a.label++,{value:c[1],done:!1};case 5:a.label++,o=c[1],c=[0];continue;case 7:c=a.ops.pop(),a.trys.pop();continue;default:if(!((r=(r=a.trys).length>0&&r[r.length-1])||6!==c[0]&&2!==c[0])){a=0;continue}if(3===c[0]&&(!r||c[1]>r[0]&&c[1]<r[3])){a.label=c[1];break}if(6===c[0]&&a.label<r[1]){a.label=r[1],r=c;break}if(r&&a.label<r[2]){a.label=r[2],a.ops.push(c);break}r[2]&&a.ops.pop(),a.trys.pop();continue}c=t.call(e,a)}catch(e){c=[6,e],o=0}finally{n=r=0}if(5&c[0])throw c[1];return{value:c[0]?c[1]:void 0,done:!0}}([c,l])}}},o=function(){function n(){this.last_comment_index_=0,this.comments_=new Map,this.root_comments_=[],this.num_total_comments_=getNumTotalComments()}return n.prototype.LoadComments=function(){return e(this,void 0,void 0,(function(){var e,n,o,r,i,a,c;return t(this,(function(t){switch(t.label){case 0:return e=window.location.pathname,n=e.substr(e.lastIndexOf("/")+1),[4,fetch("/get-comment",{method:"POST",mode:"cors",cache:"no-cache",headers:{Accept:"application/json","Content-Type":"application/json"},body:JSON.stringify({article_url:n,index_start:this.last_comment_index_})})];case 1:return[4,t.sent().json()];case 2:for(o=t.sent(),r=o.comments,i=0,a=r;i<a.length;i++)c=a[i],this.comments_.set(c.comment_id,c);return this.last_comment_index_+=50,[2]}}))}))},n.prototype.PostComment=function(n,o,r,i){return e(this,void 0,void 0,(function(){var e,a;return t(this,(function(t){return e=window.location.href,a=e.substr(e.lastIndexOf("/")+1),grecaptcha.ready((function(){grecaptcha.execute("6LeE_nYUAAAAAGm9qTa71IwvvayWV9Q7flqNkto2",{action:"Comment"}).then((function(e){fetch("/write-comment",{method:"POST",mode:"cors",cache:"no-cache",headers:{"Content-Type":"application/json"},body:JSON.stringify({parent_id:i,content:n,password:o||"",author_name:r,article_url:a,captcha_token:e})}).then((function(e){console.log(e),document.getElementById("adding-comment").hidden=!0,location.reload()}))}))})),[2]}))}))},n.prototype.ComputeRootComments=function(){var e=Array.from(this.comments_.keys()).sort((function(e,t){return e-t})),t=new Set;this.root_comments_=[];for(var n=0,o=e;n<o.length;n++){var r=o[n];t.has(r)||(this.root_comments_.push(this.comments_.get(r)),this.VisitAllChildComments(r,t))}this.root_comments_=this.root_comments_.reverse()},n.prototype.VisitAllChildComments=function(e,t){var n=this.comments_.get(e);if(n){t.add(e);for(var o=0,r=n.reply_ids||[];o<r.length;o++){var i=r[o];this.VisitAllChildComments(i,t)}}},n.prototype.CreateCommentList=function(){var e=document.createElement("ul");e.classList.add("comment-list"),e.id="root-comment-list";for(var t=0,n=this.root_comments_;t<n.length;t++)for(var o=n[t],r=0,i=this.CreateComment(o.comment_id);r<i.length;r++){var a=i[r];e.appendChild(a)}return e},n.prototype.CreateComment=function(e){var t=this,n=this.comments_.get(e);if(!n)return[];var o=document.createElement("li");o.classList.add("comment");var r=document.createElement("div");r.classList.add("comment-profile");var i=document.createElement("img");n.image_link?(i.src=n.image_link,i.alt="프로필 사진"):(i.src="./img/unknown_person.png",i.alt="프로필 사진 없음"),r.appendChild(i),o.appendChild(r);var a=document.createElement("div");a.classList.add("comment-info");var c=document.createElement("div");c.classList.add("comment-header");var l=function(e,t){var n=document.createElement("span");return n.classList.add(e),n.textContent=t,n};c.appendChild(l("comment-author",n.author_name||"")),c.appendChild(l("comment-date",n.comment_date||"")),a.appendChild(c);var s=document.createElement("div");s.classList.add("comment-content"),s.textContent=n.content,a.appendChild(s);var m=document.createElement("div");m.classList.add("comment-action"),m.id="comment-id-"+e;var d=l("comment-reply","답글 달기");d.onclick=function(){t.CreateCommentReply(e)},m.appendChild(d);var u=l("comment-delete","답글 삭제");if(m.appendChild(u),a.appendChild(m),o.appendChild(a),!n.reply_ids)return[o];if(!n.reply_ids.length)return[o];var h=document.createElement("ul");h.classList.add("comment-list");for(var p=0,_=n.reply_ids;p<_.length;p++)for(var f=_[p],v=0,g=this.CreateComment(f);v<g.length;v++){var y=g[v];h.append(y)}return[o,h]},n.prototype.GetNumTotalComments=function(){return this.num_total_comments_},n.prototype.GetLastCommentIndex=function(){return this.last_comment_index_},n.prototype.CreateCommentReply=function(e){var t=this;this.current_reply_comment_box&&this.current_reply_comment_box.remove();var n=document.getElementById("comment-post-section").cloneNode(!0);n.id="reply-post-section",document.getElementById("comment-id-"+e).parentElement.parentElement.insertAdjacentElement("afterend",n),n.getElementsByClassName("comment-btn")[0].onclick=function(){var o="",r="";n.getElementsByClassName("comment-box-name").length>0&&(o=n.getElementsByClassName("comment-box-name")[0].value,r=n.getElementsByClassName("comment-box-name")[0].value);var i=n.getElementsByClassName("comment-textarea")[0].value;t.PostComment(i,r,o,e).then((function(e){console.log(e)}))},this.current_reply_comment_box=n},n}(),r=function(){function e(){this.last_position=window.scrollY,this.time_to_update_toc=!0,this.scroll_down_event_handlers=[],this.scroll_up_event_handlers=[],this.InstallScrollEventHandler()}return e.prototype.InstallScrollEventHandler=function(){var e=this;window.addEventListener("scroll",(function(t){e.time_to_update_toc&&(window.requestAnimationFrame((function(){if(e.time_to_update_toc=!0,e.last_position>window.scrollY)for(var t=0,n=e.scroll_up_event_handlers;t<n.length;t++)(0,n[t])();else for(var o=0,r=e.scroll_down_event_handlers;o<r.length;o++)(0,r[o])();e.last_position=window.scrollY})),e.time_to_update_toc=!1)}))},e.prototype.RegisterScrollUpHandler=function(e){this.scroll_up_event_handlers.push(e)},e.prototype.RegisterScrollDownHandler=function(e){this.scroll_down_event_handlers.push(e)},e}();function i(e){for(var t=0;t<e.length&&" "==e[t];t++);return e.substring(t)}var a=function(){function e(){this.toc_headers_=[],this.time_to_update_toc=!0,this.prev_highlighted=0,this.FetchHeaders()}return e.prototype.FetchHeaders=function(){for(var e,t=0,n=document.querySelectorAll(".header-general");t<n.length;t++){var o=n[t],r=i(o.innerText),a="h"!=(e=o.tagName)[0]&&"H"!=e[0]?-1:parseInt(e.substring(1)),c=o.id,l=o.getBoundingClientRect().top+window.scrollY;this.toc_headers_.push({header_name:r,header_tag:a,header_id:c,header_pos:l,header_elem_link:null})}},e.prototype.RecursiveTOCCreator=function(e,t,n){for(var o=null,r=t;r<this.toc_headers_.length;r++){var i=this.toc_headers_[r];if(i.header_tag<n)return r;if(i.header_tag>n){var a=document.createElement("ol");a.className="toc-list",o.appendChild(a),r=this.RecursiveTOCCreator(a,r,i.header_tag),r--}else{var l=c(i);i.header_elem_link=l.firstChild,e.appendChild(l),o=l}}return r},e.prototype.CreateTOCList=function(){var e=document.querySelector(".toc-list");null!=e&&(0!=this.toc_headers_.length&&this.RecursiveTOCCreator(e,0,this.toc_headers_[0].header_tag),this.InstallTOCEventHandlers())},e.prototype.InstallTOCEventHandlers=function(){var e=this;window.addEventListener("scroll",(function(){var t=window.scrollY;e.time_to_update_toc&&(window.requestAnimationFrame((function(){e.time_to_update_toc=!0;var n=e.GetCurrentActiveTOCItem(t);e.HighlightActiveItem(n)})),e.time_to_update_toc=!1)}))},e.prototype.HighlightActiveItem=function(e){this.toc_headers_[this.prev_highlighted].header_elem_link.className="toc-item-link",this.toc_headers_[e].header_elem_link.className="toc-item-link toc-active-item",this.prev_highlighted=e},e.prototype.InstallLinkClickHandler=function(){for(var e=function(e){e.header_elem_link.onclick=function(t){window.scrollTo(0,e.header_pos-150),console.log(e.header_pos-150)}},t=0,n=this.toc_headers_;t<n.length;t++)e(n[t])},e.prototype.GetCurrentActiveTOCItem=function(e){if(e<this.toc_headers_[0].header_pos)return 0;for(var t,n=0;n<this.toc_headers_.length&&n!=this.toc_headers_.length-1;n++)if(this.toc_headers_[n].header_pos<=e&&e<this.toc_headers_[n+1].header_pos)return e-this.toc_headers_[n].header_pos>this.toc_headers_[n+1].header_pos-e&&(void 0,(t=this.toc_headers_[n+1].header_elem_link.getBoundingClientRect()).top>=0&&t.left>=0&&t.right<=(window.innerWidth||document.documentElement.clientWidth)&&t.bottom<=(window.innerHeight||document.documentElement.clientHeight))?n+1:n;return n},e}();function c(e){var t=document.createElement("li");t.className="toc-list-item";var n=document.createElement("span");return n.className="toc-item-link",n.textContent=e.header_name,t.appendChild(n),t}n(778);function l(){return e=this,t=void 0,i=function(){var e;return function(e,t){var n,o,r,i,a={label:0,sent:function(){if(1&r[0])throw r[1];return r[1]},trys:[],ops:[]};return i={next:c(0),throw:c(1),return:c(2)},"function"==typeof Symbol&&(i[Symbol.iterator]=function(){return this}),i;function c(c){return function(l){return function(c){if(n)throw new TypeError("Generator is already executing.");for(;i&&(i=0,c[0]&&(a=0)),a;)try{if(n=1,o&&(r=2&c[0]?o.return:c[0]?o.throw||((r=o.return)&&r.call(o),0):o.next)&&!(r=r.call(o,c[1])).done)return r;switch(o=0,r&&(c=[2&c[0],r.value]),c[0]){case 0:case 1:r=c;break;case 4:return a.label++,{value:c[1],done:!1};case 5:a.label++,o=c[1],c=[0];continue;case 7:c=a.ops.pop(),a.trys.pop();continue;default:if(!((r=(r=a.trys).length>0&&r[r.length-1])||6!==c[0]&&2!==c[0])){a=0;continue}if(3===c[0]&&(!r||c[1]>r[0]&&c[1]<r[3])){a.label=c[1];break}if(6===c[0]&&a.label<r[1]){a.label=r[1],r=c;break}if(r&&a.label<r[2]){a.label=r[2],a.ops.push(c);break}r[2]&&a.ops.pop(),a.trys.pop();continue}c=t.call(e,a)}catch(e){c=[6,e],o=0}finally{n=r=0}if(5&c[0])throw c[1];return{value:c[0]?c[1]:void 0,done:!0}}([c,l])}}}(this,(function(t){switch(t.label){case 0:return(n=new a).CreateTOCList(),n.InstallLinkClickHandler(),(new r).RegisterScrollUpHandler((function(){})),[4,(e=new o).LoadComments()];case 1:return t.sent(),e.ComputeRootComments(),document.getElementById("root-comment-list").replaceWith(e.CreateCommentList()),e.GetNumTotalComments()>=e.GetLastCommentIndex()&&(document.getElementById("button-box").hidden=!1),document.getElementById("post-comment").onclick=function(){var t=document.getElementById("posted-comment").value,n="";document.getElementById("password")&&(n=document.getElementById("password").value);var o="";document.getElementById("name")&&(o=document.getElementById("name").value),e.PostComment(t,n,o).then((function(e){console.log(e)}))},[2]}var n}))},new((n=void 0)||(n=Promise))((function(o,r){function a(e){try{l(i.next(e))}catch(e){r(e)}}function c(e){try{l(i.throw(e))}catch(e){r(e)}}function l(e){var t;e.done?o(e.value):(t=e.value,t instanceof n?t:new n((function(e){e(t)}))).then(a,c)}l((i=i.apply(e,t||[])).next())}));var e,t,n,i}window.onload=function(){l()}})()})();