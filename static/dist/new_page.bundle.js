(()=>{"use strict";var e=function(){function e(){this.last_comment_index_=0,this.comments_=new Map,this.root_comments_=[]}return e.prototype.LoadComments=function(){return e=this,t=void 0,o=function(){var e,t,n,o,r,i,a;return function(e,t){var n,o,r,i,a={label:0,sent:function(){if(1&r[0])throw r[1];return r[1]},trys:[],ops:[]};return i={next:l(0),throw:l(1),return:l(2)},"function"==typeof Symbol&&(i[Symbol.iterator]=function(){return this}),i;function l(l){return function(s){return function(l){if(n)throw new TypeError("Generator is already executing.");for(;i&&(i=0,l[0]&&(a=0)),a;)try{if(n=1,o&&(r=2&l[0]?o.return:l[0]?o.throw||((r=o.return)&&r.call(o),0):o.next)&&!(r=r.call(o,l[1])).done)return r;switch(o=0,r&&(l=[2&l[0],r.value]),l[0]){case 0:case 1:r=l;break;case 4:return a.label++,{value:l[1],done:!1};case 5:a.label++,o=l[1],l=[0];continue;case 7:l=a.ops.pop(),a.trys.pop();continue;default:if(!((r=(r=a.trys).length>0&&r[r.length-1])||6!==l[0]&&2!==l[0])){a=0;continue}if(3===l[0]&&(!r||l[1]>r[0]&&l[1]<r[3])){a.label=l[1];break}if(6===l[0]&&a.label<r[1]){a.label=r[1],r=l;break}if(r&&a.label<r[2]){a.label=r[2],a.ops.push(l);break}r[2]&&a.ops.pop(),a.trys.pop();continue}l=t.call(e,a)}catch(e){l=[6,e],o=0}finally{n=r=0}if(5&l[0])throw l[1];return{value:l[0]?l[1]:void 0,done:!0}}([l,s])}}}(this,(function(l){switch(l.label){case 0:return e=window.location.pathname,t=e.substr(e.lastIndexOf("/")+1),[4,fetch("/get-comment",{method:"POST",mode:"cors",cache:"no-cache",headers:{Accept:"application/json","Content-Type":"application/json"},body:JSON.stringify({article_url:t,index_start:this.last_comment_index_})})];case 1:return[4,l.sent().json()];case 2:for(n=l.sent(),o=n.comments,r=0,i=o;r<i.length;r++)a=i[r],this.comments_.set(a.comment_id,a);return[2]}}))},new((n=void 0)||(n=Promise))((function(r,i){function a(e){try{s(o.next(e))}catch(e){i(e)}}function l(e){try{s(o.throw(e))}catch(e){i(e)}}function s(e){var t;e.done?r(e.value):(t=e.value,t instanceof n?t:new n((function(e){e(t)}))).then(a,l)}s((o=o.apply(e,t||[])).next())}));var e,t,n,o},e.prototype.ComputeRootComments=function(){var e=Array.from(this.comments_.keys()).sort((function(e,t){return e-t})),t=new Set;this.root_comments_=[];for(var n=0,o=e;n<o.length;n++){var r=o[n];t.has(r)||(this.root_comments_.push(this.comments_.get(r)),this.VisitAllChildComments(r,t))}this.root_comments_=this.root_comments_.reverse()},e.prototype.VisitAllChildComments=function(e,t){var n=this.comments_.get(e);if(n){t.add(e);for(var o=0,r=n.reply_ids||[];o<r.length;o++){var i=r[o];this.VisitAllChildComments(i,t)}}},e.prototype.CreateCommentList=function(){for(var e=[],t=0,n=this.root_comments_;t<n.length;t++){var o=n[t];e.push(this.CreateComment(o.comment_id))}return e.flat()},e.prototype.CreateComment=function(e){var t,n=this.comments_.get(e);if(n){var o=document.createElement("li");o.classList.add("comment");var r=document.createElement("div");r.classList.add("comment-profile");var i=document.createElement("img");n.image_link?(i.src=n.image_link,i.alt="프로필 사진"):(i.src="./img/unknown_person.png",i.alt="프로필 사진 없음"),r.appendChild(i),o.appendChild(r);var a=document.createElement("div");a.classList.add("comment-info");var l=document.createElement("div");l.classList.add("comment-header");var s=function(e,t){var n=document.createElement("span");return n.classList.add(e),n.textContent=t,n};l.appendChild(s("comment-author",n.author_name||"")),l.appendChild(s("comment-date",n.comment_date||"")),a.appendChild(l);var c=document.createElement("div");c.classList.add("comment-content"),c.textContent=n.content,a.appendChild(c);var d=document.createElement("div");if(d.classList.add("comment-action"),d.id="comment-id-"+e,d.appendChild(s("comment-upvote","추천")),d.appendChild(s("comment-reply","답글")),d.appendChild(s("comment-delete","답글 삭제")),a.appendChild(d),o.appendChild(a),!(null===(t=n.reply_ids)||void 0===t?void 0:t.length))return[o];var h=document.createElement("ul");h.classList.add("comment-list");for(var u=0,m=n.reply_ids;u<m.length;u++)for(var p=m[u],_=0,f=this.CreateComment(p);_<f.length;_++){var v=f[_];h.append(v)}return[o,h]}},e}(),t=function(){function e(){this.last_position=window.scrollY,this.time_to_update_toc=!0,this.scroll_down_event_handlers=[],this.scroll_up_event_handlers=[],this.InstallScrollEventHandler()}return e.prototype.InstallScrollEventHandler=function(){var e=this;window.addEventListener("scroll",(function(t){e.time_to_update_toc&&(window.requestAnimationFrame((function(){if(e.time_to_update_toc=!0,e.last_position>window.scrollY)for(var t=0,n=e.scroll_up_event_handlers;t<n.length;t++)(0,n[t])();else for(var o=0,r=e.scroll_down_event_handlers;o<r.length;o++)(0,r[o])();e.last_position=window.scrollY})),e.time_to_update_toc=!1)}))},e.prototype.RegisterScrollUpHandler=function(e){this.scroll_up_event_handlers.push(e)},e.prototype.RegisterScrollDownHandler=function(e){this.scroll_down_event_handlers.push(e)},e}();function n(e){for(var t=0;t<e.length&&" "==e[t];t++);return e.substring(t)}var o=function(){function e(){this.toc_headers_=[],this.time_to_update_toc=!0,this.prev_highlighted=0,this.FetchHeaders()}return e.prototype.FetchHeaders=function(){for(var e,t=0,o=document.querySelectorAll(".header-general");t<o.length;t++){var r=o[t],i=n(r.innerText),a="h"!=(e=r.tagName)[0]&&"H"!=e[0]?-1:parseInt(e.substring(1)),l=r.id,s=r.getBoundingClientRect().top+window.scrollY;this.toc_headers_.push({header_name:i,header_tag:a,header_id:l,header_pos:s,header_elem_link:null})}},e.prototype.RecursiveTOCCreator=function(e,t,n){for(var o=null,i=t;i<this.toc_headers_.length;i++){var a=this.toc_headers_[i];if(a.header_tag<n)return i;if(a.header_tag>n){var l=document.createElement("ol");l.className="toc-list",o.appendChild(l),i=this.RecursiveTOCCreator(l,i,a.header_tag),i--}else{var s=r(a);a.header_elem_link=s.firstChild,e.appendChild(s),o=s}}return i},e.prototype.CreateTOCList=function(){var e=document.querySelector(".toc-list");null!=e&&(this.RecursiveTOCCreator(e,0,this.toc_headers_[0].header_tag),this.InstallTOCEventHandlers())},e.prototype.InstallTOCEventHandlers=function(){var e=this;window.addEventListener("scroll",(function(){var t=window.scrollY;e.time_to_update_toc&&(window.requestAnimationFrame((function(){e.time_to_update_toc=!0;var n=e.GetCurrentActiveTOCItem(t);e.HighlightActiveItem(n)})),e.time_to_update_toc=!1)}))},e.prototype.HighlightActiveItem=function(e){this.toc_headers_[this.prev_highlighted].header_elem_link.className="toc-item-link",this.toc_headers_[e].header_elem_link.className="toc-item-link toc-active-item",this.prev_highlighted=e},e.prototype.InstallLinkClickHandler=function(){for(var e=function(e){e.header_elem_link.onclick=function(t){window.scrollTo(0,e.header_pos-150),console.log(e.header_pos-150)}},t=0,n=this.toc_headers_;t<n.length;t++)e(n[t])},e.prototype.GetCurrentActiveTOCItem=function(e){if(e<this.toc_headers_[0].header_pos)return 0;for(var t,n=0;n<this.toc_headers_.length&&n!=this.toc_headers_.length-1;n++)if(this.toc_headers_[n].header_pos<=e&&e<this.toc_headers_[n+1].header_pos)return e-this.toc_headers_[n].header_pos>this.toc_headers_[n+1].header_pos-e&&(void 0,(t=this.toc_headers_[n+1].header_elem_link.getBoundingClientRect()).top>=0&&t.left>=0&&t.right<=(window.innerWidth||document.documentElement.clientWidth)&&t.bottom<=(window.innerHeight||document.documentElement.clientHeight))?n+1:n;return n},e}();function r(e){var t=document.createElement("li");t.className="toc-list-item";var n=document.createElement("span");return n.className="toc-item-link",n.textContent=e.header_name,t.appendChild(n),t}function i(){return n=this,r=void 0,a=function(){var n,r,i,a;return function(e,t){var n,o,r,i,a={label:0,sent:function(){if(1&r[0])throw r[1];return r[1]},trys:[],ops:[]};return i={next:l(0),throw:l(1),return:l(2)},"function"==typeof Symbol&&(i[Symbol.iterator]=function(){return this}),i;function l(l){return function(s){return function(l){if(n)throw new TypeError("Generator is already executing.");for(;i&&(i=0,l[0]&&(a=0)),a;)try{if(n=1,o&&(r=2&l[0]?o.return:l[0]?o.throw||((r=o.return)&&r.call(o),0):o.next)&&!(r=r.call(o,l[1])).done)return r;switch(o=0,r&&(l=[2&l[0],r.value]),l[0]){case 0:case 1:r=l;break;case 4:return a.label++,{value:l[1],done:!1};case 5:a.label++,o=l[1],l=[0];continue;case 7:l=a.ops.pop(),a.trys.pop();continue;default:if(!((r=(r=a.trys).length>0&&r[r.length-1])||6!==l[0]&&2!==l[0])){a=0;continue}if(3===l[0]&&(!r||l[1]>r[0]&&l[1]<r[3])){a.label=l[1];break}if(6===l[0]&&a.label<r[1]){a.label=r[1],r=l;break}if(r&&a.label<r[2]){a.label=r[2],a.ops.push(l);break}r[2]&&a.ops.pop(),a.trys.pop();continue}l=t.call(e,a)}catch(e){l=[6,e],o=0}finally{n=r=0}if(5&l[0])throw l[1];return{value:l[0]?l[1]:void 0,done:!0}}([l,s])}}}(this,(function(l){switch(l.label){case 0:return(s=new o).CreateTOCList(),s.InstallLinkClickHandler(),(new t).RegisterScrollUpHandler((function(){})),[4,(n=new e).LoadComments()];case 1:for(l.sent(),n.ComputeRootComments(),r=0,i=n.CreateCommentList();r<i.length;r++)a=i[r],console.log(a.innerHTML);return console.log(n.CreateCommentList()),[2]}var s}))},new((i=void 0)||(i=Promise))((function(e,t){function o(e){try{s(a.next(e))}catch(e){t(e)}}function l(e){try{s(a.throw(e))}catch(e){t(e)}}function s(t){var n;t.done?e(t.value):(n=t.value,n instanceof i?n:new i((function(e){e(n)}))).then(o,l)}s((a=a.apply(n,r||[])).next())}));var n,r,i,a}window.onload=function(){i()}})();
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoibmV3X3BhZ2UuYnVuZGxlLmpzIiwibWFwcGluZ3MiOiJ1QkFlQSxhQUNFLGFBQ0VBLEtBQUtDLG9CQUFzQixFQUMzQkQsS0FBS0UsVUFBWSxJQUFJQyxJQUNyQkgsS0FBS0ksZUFBaUIsRUFDeEIsQ0F5SkYsT0F2SmUsWUFBQUMsYUFBYixXLGdxQ0FJaUIsT0FIWEMsRUFBTUMsT0FBT0MsU0FBU0MsU0FDdEJDLEVBQWNKLEVBQUlLLE9BQU9MLEVBQUlNLFlBQVksS0FBTyxHQUVyQyxHQUFNQyxNQUFNLGVBQWdCLENBQ3pDQyxPQUFRLE9BQ1JDLEtBQU0sT0FDTkMsTUFBTyxXQUNQQyxRQUFTLENBQ1BDLE9BQVEsbUJBQ1IsZUFBZ0Isb0JBRWxCQyxLQUFNQyxLQUFLQyxVQUFVLENBQ25CWCxZQUFXLEVBQ1hZLFlBQWF0QixLQUFLQyx5QixPQUl5QixTQWRoQyxTQWMrQ3NCLFEsT0FFOUQsSUFGSUMsRUFBMkMsU0FDM0NDLEVBQVdELEVBQXFCQyxTQUMvQixFQUFMLEVBQW9CLEVBQUFBLEVBQUEsZUFBWEMsRUFBTyxLQUNkMUIsS0FBS0UsVUFBVXlCLElBQUlELEVBQVFFLFdBQVlGLEcsK1NBSTNDLFlBQUFHLG9CQUFBLFdBQ0UsSUFBSUMsRUFBY0MsTUFBTUMsS0FBS2hDLEtBQUtFLFVBQVUrQixRQUFRQyxNQUFLLFNBQUNDLEVBQUdDLEdBQU0sT0FBQUQsRUFBSUMsQ0FBSixJQUMvREMsRUFBbUIsSUFBSUMsSUFFM0J0QyxLQUFLSSxlQUFpQixHQUd0QixJQUF1QixVQUFBMEIsRUFBQSxlQUFhLENBQS9CLElBQUlGLEVBQVUsS0FDYlMsRUFBaUJFLElBQUlYLEtBSXpCNUIsS0FBS0ksZUFBZW9DLEtBQUt4QyxLQUFLRSxVQUFVdUMsSUFBSWIsSUFDNUM1QixLQUFLMEMsc0JBQXNCZCxFQUFZUyxHLENBR3pDckMsS0FBS0ksZUFBaUJKLEtBQUtJLGVBQWV1QyxTQUM1QyxFQUVBLFlBQUFELHNCQUFBLFNBQXNCZCxFQUFvQlMsR0FDeEMsSUFBSVgsRUFBVTFCLEtBQUtFLFVBQVV1QyxJQUFJYixHQUNqQyxHQUFLRixFQUFMLENBSUFXLEVBQWlCTyxJQUFJaEIsR0FDckIsSUFBNkIsVUFBQUYsRUFBUW1CLFdBQWEsR0FBckIsZUFBeUIsQ0FBakQsSUFBSUMsRUFBZ0IsS0FDdkI5QyxLQUFLMEMsc0JBQXNCSSxFQUFrQlQsRSxFQUlqRCxFQUVBLFlBQUFVLGtCQUFBLFdBRUUsSUFEQSxJQUFJdEIsRUFBVyxHQUNPLE1BQUF6QixLQUFLSSxlQUFMLGVBQXFCLENBQXRDLElBQU1zQixFQUFPLEtBQ2hCRCxFQUFTZSxLQUFLeEMsS0FBS2dELGNBQWN0QixFQUFRRSxZLENBRzNDLE9BQU9ILEVBQVN3QixNQUNsQixFQUVBLFlBQUFELGNBQUEsU0FBY3BCLEcsTUFDUkYsRUFBVTFCLEtBQUtFLFVBQVV1QyxJQUFJYixHQUNqQyxHQUFLRixFQUFMLENBSUEsSUFBSXdCLEVBQWVDLFNBQVNDLGNBQWMsTUFDMUNGLEVBQWFHLFVBQVVULElBQUksV0FFM0IsSUFBSVUsRUFBa0JILFNBQVNDLGNBQWMsT0FDN0NFLEVBQWdCRCxVQUFVVCxJQUFJLG1CQUU5QixJQUFJVyxFQUFhSixTQUFTQyxjQUFjLE9BQ3BDMUIsRUFBUTZCLFlBQ1ZBLEVBQVdDLElBQU05QixFQUFRNkIsV0FDekJBLEVBQVdFLElBQU0sV0FFakJGLEVBQVdDLElBQU0sMkJBQ2pCRCxFQUFXRSxJQUFNLGFBR25CSCxFQUFnQkksWUFBWUgsR0FDNUJMLEVBQWFRLFlBQVlKLEdBRXpCLElBQUlLLEVBQWVSLFNBQVNDLGNBQWMsT0FDMUNPLEVBQWFOLFVBQVVULElBQUksZ0JBRzNCLElBQUlnQixFQUFpQlQsU0FBU0MsY0FBYyxPQUM1Q1EsRUFBZVAsVUFBVVQsSUFBSSxrQkFFN0IsSUFBSWlCLEVBQW1CLFNBQUNDLEVBQW9CQyxHQUMxQyxJQUFJQyxFQUFPYixTQUFTQyxjQUFjLFFBR2xDLE9BRkFZLEVBQUtYLFVBQVVULElBQUlrQixHQUNuQkUsRUFBS0MsWUFBY0YsRUFDWkMsQ0FDVCxFQUVBSixFQUFlRixZQUNiRyxFQUFpQixpQkFBa0JuQyxFQUFRd0MsYUFBZSxLQUU1RE4sRUFBZUYsWUFDYkcsRUFBaUIsZUFBZ0JuQyxFQUFReUMsY0FBZ0IsS0FHM0RSLEVBQWFELFlBQVlFLEdBR3pCLElBQUlRLEVBQWtCakIsU0FBU0MsY0FBYyxPQUM3Q2dCLEVBQWdCZixVQUFVVCxJQUFJLG1CQUM5QndCLEVBQWdCSCxZQUFjdkMsRUFBUTJDLFFBQ3RDVixFQUFhRCxZQUFZVSxHQUV6QixJQUFJRSxFQUFpQm5CLFNBQVNDLGNBQWMsT0FXNUMsR0FWQWtCLEVBQWVqQixVQUFVVCxJQUFJLGtCQUM3QjBCLEVBQWVDLEdBQUssY0FBZ0IzQyxFQUVwQzBDLEVBQWVaLFlBQVlHLEVBQWlCLGlCQUFrQixPQUM5RFMsRUFBZVosWUFBWUcsRUFBaUIsZ0JBQWlCLE9BQzdEUyxFQUFlWixZQUFZRyxFQUFpQixpQkFBa0IsVUFDOURGLEVBQWFELFlBQVlZLEdBRXpCcEIsRUFBYVEsWUFBWUMsS0FFSCxRQUFqQixFQUFBakMsRUFBUW1CLGlCQUFTLGVBQUUyQixRQUN0QixNQUFPLENBQUN0QixHQUdWLElBQUl1QixFQUFpQnRCLFNBQVNDLGNBQWMsTUFDNUNxQixFQUFlcEIsVUFBVVQsSUFBSSxnQkFFN0IsSUFBdUIsVUFBQWxCLEVBQVFtQixVQUFSLGVBRXJCLElBRkcsSUFBTTZCLEVBQVEsS0FFRSxNQURQMUUsS0FBS2dELGNBQWMwQixHQUNaLGVBQU8sQ0FBckIsSUFBTVYsRUFBSSxLQUNiUyxFQUFlRSxPQUFPWCxFLENBSTFCLE1BQU8sQ0FBQ2QsRUFBY3VCLEUsQ0FDeEIsRUFLRixFQTlKQSxHQ2ZBLGFBQ0UsYUFDRXpFLEtBQUs0RSxjQUFnQnJFLE9BQU9zRSxRQUM1QjdFLEtBQUs4RSxvQkFBcUIsRUFFMUI5RSxLQUFLK0UsMkJBQTZCLEdBQ2xDL0UsS0FBS2dGLHlCQUEyQixHQUVoQ2hGLEtBQUtpRiwyQkFDUCxDQXNDRixPQXBDVSxZQUFBQSwwQkFBUixzQkFDRTFFLE9BQU8yRSxpQkFBaUIsVUFBVSxTQUFDQyxHQUM3QixFQUFLTCxxQkFDUHZFLE9BQU82RSx1QkFBc0IsV0FFM0IsR0FEQSxFQUFLTixvQkFBcUIsRUFDdEIsRUFBS0YsY0FBZ0JyRSxPQUFPc0UsUUFDOUIsSUFBaUIsWUFBS0cseUJBQUwsZ0JBQVJLLEVBQUksYUFJYixJQUFpQixZQUFLTiwyQkFBTCxnQkFBUk0sRUFBSSxRQUlmLEVBQUtULGNBQWdCckUsT0FBT3NFLE9BQzlCLElBQ0EsRUFBS0Msb0JBQXFCLEVBRTlCLEdBQ0YsRUFFTyxZQUFBUSx3QkFBUCxTQUErQkQsR0FDN0JyRixLQUFLZ0YseUJBQXlCeEMsS0FBSzZDLEVBQ3JDLEVBRU8sWUFBQUUsMEJBQVAsU0FBaUNGLEdBQy9CckYsS0FBSytFLDJCQUEyQnZDLEtBQUs2QyxFQUN2QyxFQVNGLEVBL0NBLEdDQU8sU0FBU0csRUFBZ0JDLEdBRTlCLElBREEsSUFBSUMsRUFBSSxFQUNEQSxFQUFJRCxFQUFJakIsUUFDQyxLQUFWaUIsRUFBSUMsR0FEYUEsS0FPdkIsT0FBT0QsRUFBSUUsVUFBVUQsRUFDdkIsQ0NBQSxpQkFDRSxhQUNFMUYsS0FBSzRGLGFBQWUsR0FDcEI1RixLQUFLOEUsb0JBQXFCLEVBQzFCOUUsS0FBSzZGLGlCQUFtQixFQUd4QjdGLEtBQUs4RixjQUNQLENBMEhGLE9BeEhVLFlBQUFBLGFBQVIsV0FLRSxJQUhBLElEVnlCTCxFQ2FOLE1BRmZ0QyxTQUFTNEMsaUJBQWlCLG1CQUVYLGVBQWdCLENBQTlCLElBQUlDLEVBQU0sS0FDVEMsRUFBc0IsRUFBcUJELEVBQU9FLFdBQ2xEQyxFRGRRLE1BRFdWLEVDZW9CTyxFQUFPSSxTRGQ1QyxJQUF1QixLQUFWWCxFQUFJLElBQ2pCLEVBR0hZLFNBQVNaLEVBQUlFLFVBQVUsSUNXdEJXLEVBQW9CTixFQUFPekIsR0FDM0JnQyxFQUNBUCxFQUFPUSx3QkFBd0JDLElBQU1sRyxPQUFPc0UsUUFDaEQ3RSxLQUFLNEYsYUFBYXBELEtBQUssQ0FDckJ5RCxZQUFXLEVBQ1hFLFdBQVUsRUFDVkcsVUFBUyxFQUNUQyxXQUFVLEVBQ1ZHLGlCQUFrQixNLENBR3hCLEVBRVEsWUFBQUMsb0JBQVIsU0FDSUMsRUFBNkJDLEVBQzdCQyxHQUdGLElBRkEsSUFBSUMsRUFBYSxLQUNickIsRUFBSW1CLEVBQ0RuQixFQUFJMUYsS0FBSzRGLGFBQWFwQixPQUFRa0IsSUFBSyxDQUN4QyxJQUFJTSxFQUFTaEcsS0FBSzRGLGFBQWFGLEdBRy9CLEdBQUlNLEVBQU9HLFdBQWFXLEVBQ3RCLE9BQU9wQixFQUdKLEdBQUlNLEVBQU9HLFdBQWFXLEVBQVksQ0FDdkMsSUFBSUUsRUFBa0I3RCxTQUFTQyxjQUFjLE1BQzdDNEQsRUFBZ0JDLFVBQVksV0FDNUJGLEVBQVdyRCxZQUFZc0QsR0FDdkJ0QixFQUFJMUYsS0FBSzJHLG9CQUFvQkssRUFBaUJ0QixFQUFHTSxFQUFPRyxZQUN4RFQsRyxLQUNLLENBQ0wsSUFBSXdCLEVBQVVDLEVBQXlCbkIsR0FDdkNBLEVBQU9VLGlCQUFtQlEsRUFBUUUsV0FDbENSLEVBQVVsRCxZQUFZd0QsR0FDdEJILEVBQWFHLEMsRUFHakIsT0FBT3hCLENBQ1QsRUFFTyxZQUFBMkIsY0FBUCxXQUNFLElBQUlDLEVBQVVuRSxTQUFTb0UsY0FBYyxhQUN0QixNQUFYRCxJQUdKdEgsS0FBSzJHLG9CQUFvQlcsRUFBUyxFQUFHdEgsS0FBSzRGLGFBQWEsR0FBR08sWUFFMURuRyxLQUFLd0gsMEJBQ1AsRUFFUSxZQUFBQSx3QkFBUixXQUNFLElBQUlDLEVBQU96SCxLQUNYTyxPQUFPMkUsaUJBQWlCLFVBQVUsV0FDaEMsSUFBSXdDLEVBQXdCbkgsT0FBT3NFLFFBQy9CNEMsRUFBSzNDLHFCQUNQdkUsT0FBTzZFLHVCQUFzQixXQUMzQnFDLEVBQUszQyxvQkFBcUIsRUFDMUIsSUFBSTZDLEVBQWFGLEVBQUtHLHdCQUF3QkYsR0FDOUNELEVBQUtJLG9CQUFvQkYsRUFDM0IsSUFDQUYsRUFBSzNDLG9CQUFxQixFQUU5QixHQUNGLEVBRVEsWUFBQStDLG9CQUFSLFNBQTRCQyxHQUMxQjlILEtBQUs0RixhQUFhNUYsS0FBSzZGLGtCQUFrQmEsaUJBQWlCTyxVQUN0RCxnQkFDSmpILEtBQUs0RixhQUFha0MsR0FBVXBCLGlCQUFpQk8sVUFDekMsZ0NBQ0pqSCxLQUFLNkYsaUJBQW1CaUMsQ0FDMUIsRUFFTyxZQUFBQyx3QkFBUCxXQUNFLEksZUFBUy9CLEdBQ1BBLEVBQU9VLGlCQUFpQnNCLFFBQVUsU0FBQzdDLEdBQ2pDNUUsT0FBTzBILFNBQVMsRUFBR2pDLEVBQU9PLFdBQWEsS0FDdkMyQixRQUFRQyxJQUFJbkMsRUFBT08sV0FBYSxJQUNsQyxDLEVBSmlCLE1BQUF2RyxLQUFLNEYsYUFBTCxlLEVBQUosS0FNakIsRUFFUSxZQUFBZ0Msd0JBQVIsU0FBZ0NRLEdBQzlCLEdBQUlBLEVBQWFwSSxLQUFLNEYsYUFBYSxHQUFHVyxXQUNwQyxPQUFPLEVBSVQsSUFEQSxJRGhHRThCLEVDZ0dFM0MsRUFBSSxFQUNEQSxFQUFJMUYsS0FBSzRGLGFBQWFwQixRQUN2QmtCLEdBQUsxRixLQUFLNEYsYUFBYXBCLE9BQVMsRUFERGtCLElBRzVCLEdBQ0gxRixLQUFLNEYsYUFBYUYsR0FBR2EsWUFBYzZCLEdBQ25DQSxFQUFhcEksS0FBSzRGLGFBQWFGLEVBQUksR0FBR2EsV0FDeEMsT0FBSTZCLEVBQWFwSSxLQUFLNEYsYUFBYUYsR0FBR2EsV0FDOUJ2RyxLQUFLNEYsYUFBYUYsRUFBSSxHQUFHYSxXQUFhNkIsU0R4R2hEQyxLQzBHVXJJLEtBQUs0RixhQUFhRixFQUFJLEdBQUdnQixpQkQxR3JCRix5QkFDRkMsS0FBTyxHQUFLNEIsRUFBU0MsTUFBUSxHQUN6Q0QsRUFBU0UsUUFDUmhJLE9BQU9pSSxZQUFjckYsU0FBU3NGLGdCQUFnQkMsY0FDL0NMLEVBQVNNLFNBQ1JwSSxPQUFPcUksYUFBZXpGLFNBQVNzRixnQkFBZ0JJLGVDc0dyQ25ELEVBQUksRUFFSkEsRUFJYixPQUFPQSxDQUNULEVBS0YsRUFsSUEsR0FvSUEsU0FBU3lCLEVBQXlCbkIsR0FDaEMsSUFBSWtCLEVBQVUvRCxTQUFTQyxjQUFjLE1BQ3JDOEQsRUFBUUQsVUFBWSxnQkFFcEIsSUFBSTZCLEVBQU8zRixTQUFTQyxjQUFjLFFBS2xDLE9BSkEwRixFQUFLN0IsVUFBWSxnQkFDakI2QixFQUFLN0UsWUFBYytCLEVBQU9DLFlBRTFCaUIsRUFBUXhELFlBQVlvRixHQUNiNUIsQ0FDVCxDQ25KQSxTQUFlNkIsSSwwcENBaUJiLE9EcUlJQyxFQUFNLElBQUlDLEdBQ1Y1QixnQkFHSjJCLEVBQUlqQiwyQkY3R1MsSUFBSW1CLEdHekNWNUQseUJBQXdCLFdBVS9CLElBR0EsSUFESTZELEVKMkpVLElBQUlDLEdJMUpJL0ksZ0IsT0FHdEIsSUFIQSxTQUVBOEksRUFBZ0J0SCxzQkFDWCxFQUFMLEVBQW1CLEVBQUFzSCxFQUFnQnBHLG9CQUFoQixlQUFSaUIsRUFBSSxLQUNia0UsUUFBUUMsSUFBSW5FLEVBQUtxRixXLE9BRW5CbkIsUUFBUUMsSUFBSWdCLEVBQWdCcEcscUIsSUQ4SHZCLElBQ0RpRyxDLG9TQzVITnpJLE9BQU8rSSxPQUFTLFdBQ2RQLEdBQ0YsQyIsInNvdXJjZXMiOlsid2VicGFjazovL01vZG9vQ29kZSBGcm9udGVudCBBcHAvLi9zcmMvY29tbWVudC50cyIsIndlYnBhY2s6Ly9Nb2Rvb0NvZGUgRnJvbnRlbnQgQXBwLy4vc3JjL3Njcm9sbC50cyIsIndlYnBhY2s6Ly9Nb2Rvb0NvZGUgRnJvbnRlbnQgQXBwLy4vc3JjL3V0aWwudHMiLCJ3ZWJwYWNrOi8vTW9kb29Db2RlIEZyb250ZW50IEFwcC8uL3NyYy90b2MudHMiLCJ3ZWJwYWNrOi8vTW9kb29Db2RlIEZyb250ZW50IEFwcC8uL3NyYy9pbmRleC50cyJdLCJzb3VyY2VzQ29udGVudCI6WyJpbnRlcmZhY2UgQ29tbWVudCB7XG4gIGNvbW1lbnRfaWQ6IG51bWJlcjtcbiAgYXJ0aWNsZV91cmw6IHN0cmluZztcbiAgcmVwbHlfaWRzOiBudW1iZXJbXTtcbiAgY29tbWVudF9kYXRlOiBzdHJpbmc7XG4gIGF1dGhvcl9uYW1lPzogc3RyaW5nO1xuICBpbWFnZV9saW5rOiBzdHJpbmc7XG4gIGNvbnRlbnQ6IHN0cmluZztcbiAgaXNfbWQ6IGJvb2xlYW47XG59XG5cbmludGVyZmFjZSBHZXRDb21tZW50UmVzcG9uc2Uge1xuICBjb21tZW50czogQ29tbWVudFtdO1xufVxuXG5jbGFzcyBDb21tZW50TWFuYWdlciB7XG4gIGNvbnN0cnVjdG9yKCkge1xuICAgIHRoaXMubGFzdF9jb21tZW50X2luZGV4XyA9IDA7XG4gICAgdGhpcy5jb21tZW50c18gPSBuZXcgTWFwKCk7XG4gICAgdGhpcy5yb290X2NvbW1lbnRzXyA9IFtdO1xuICB9XG5cbiAgcHVibGljIGFzeW5jIExvYWRDb21tZW50cygpIHtcbiAgICBsZXQgdXJsID0gd2luZG93LmxvY2F0aW9uLnBhdGhuYW1lO1xuICAgIGxldCBhcnRpY2xlX3VybCA9IHVybC5zdWJzdHIodXJsLmxhc3RJbmRleE9mKFwiL1wiKSArIDEpO1xuXG4gICAgbGV0IHJlc3BvbnNlID0gYXdhaXQgZmV0Y2goXCIvZ2V0LWNvbW1lbnRcIiwge1xuICAgICAgbWV0aG9kOiBcIlBPU1RcIixcbiAgICAgIG1vZGU6IFwiY29yc1wiLFxuICAgICAgY2FjaGU6IFwibm8tY2FjaGVcIixcbiAgICAgIGhlYWRlcnM6IHtcbiAgICAgICAgQWNjZXB0OiBcImFwcGxpY2F0aW9uL2pzb25cIixcbiAgICAgICAgXCJDb250ZW50LVR5cGVcIjogXCJhcHBsaWNhdGlvbi9qc29uXCIsXG4gICAgICB9LFxuICAgICAgYm9keTogSlNPTi5zdHJpbmdpZnkoe1xuICAgICAgICBhcnRpY2xlX3VybCxcbiAgICAgICAgaW5kZXhfc3RhcnQ6IHRoaXMubGFzdF9jb21tZW50X2luZGV4XyxcbiAgICAgIH0pLFxuICAgIH0pO1xuXG4gICAgbGV0IGdldF9jb21tZW50X3Jlc3BvbnNlOiBHZXRDb21tZW50UmVzcG9uc2UgPSBhd2FpdCByZXNwb25zZS5qc29uKCk7XG4gICAgbGV0IGNvbW1lbnRzID0gZ2V0X2NvbW1lbnRfcmVzcG9uc2UuY29tbWVudHM7XG4gICAgZm9yIChsZXQgY29tbWVudCBvZiBjb21tZW50cykge1xuICAgICAgdGhpcy5jb21tZW50c18uc2V0KGNvbW1lbnQuY29tbWVudF9pZCwgY29tbWVudCk7XG4gICAgfVxuICB9XG5cbiAgQ29tcHV0ZVJvb3RDb21tZW50cygpIHtcbiAgICBsZXQgY29tbWVudF9pZHMgPSBBcnJheS5mcm9tKHRoaXMuY29tbWVudHNfLmtleXMoKSkuc29ydCgoYSwgYikgPT4gYSAtIGIpO1xuICAgIGxldCB2aXNpdGVkX2NvbW1lbnRzID0gbmV3IFNldDxudW1iZXI+KCk7XG5cbiAgICB0aGlzLnJvb3RfY29tbWVudHNfID0gW107XG5cbiAgICAvLyBGaW5kIHRoZSByb290IGNvbW1lbnRzLlxuICAgIGZvciAobGV0IGNvbW1lbnRfaWQgb2YgY29tbWVudF9pZHMpIHtcbiAgICAgIGlmICh2aXNpdGVkX2NvbW1lbnRzLmhhcyhjb21tZW50X2lkKSkge1xuICAgICAgICBjb250aW51ZTtcbiAgICAgIH1cblxuICAgICAgdGhpcy5yb290X2NvbW1lbnRzXy5wdXNoKHRoaXMuY29tbWVudHNfLmdldChjb21tZW50X2lkKSEpO1xuICAgICAgdGhpcy5WaXNpdEFsbENoaWxkQ29tbWVudHMoY29tbWVudF9pZCwgdmlzaXRlZF9jb21tZW50cyk7XG4gICAgfVxuXG4gICAgdGhpcy5yb290X2NvbW1lbnRzXyA9IHRoaXMucm9vdF9jb21tZW50c18ucmV2ZXJzZSgpO1xuICB9XG5cbiAgVmlzaXRBbGxDaGlsZENvbW1lbnRzKGNvbW1lbnRfaWQ6IG51bWJlciwgdmlzaXRlZF9jb21tZW50czogU2V0PG51bWJlcj4pIHtcbiAgICBsZXQgY29tbWVudCA9IHRoaXMuY29tbWVudHNfLmdldChjb21tZW50X2lkKTtcbiAgICBpZiAoIWNvbW1lbnQpIHtcbiAgICAgIHJldHVybjtcbiAgICB9XG5cbiAgICB2aXNpdGVkX2NvbW1lbnRzLmFkZChjb21tZW50X2lkKTtcbiAgICBmb3IgKGxldCBjaGlsZF9jb21tZW50X2lkIG9mIGNvbW1lbnQucmVwbHlfaWRzIHx8IFtdKSB7XG4gICAgICB0aGlzLlZpc2l0QWxsQ2hpbGRDb21tZW50cyhjaGlsZF9jb21tZW50X2lkLCB2aXNpdGVkX2NvbW1lbnRzKTtcbiAgICB9XG5cbiAgICByZXR1cm47XG4gIH1cblxuICBDcmVhdGVDb21tZW50TGlzdCgpIHtcbiAgICBsZXQgY29tbWVudHMgPSBbXTtcbiAgICBmb3IgKGNvbnN0IGNvbW1lbnQgb2YgdGhpcy5yb290X2NvbW1lbnRzXykge1xuICAgICAgY29tbWVudHMucHVzaCh0aGlzLkNyZWF0ZUNvbW1lbnQoY29tbWVudC5jb21tZW50X2lkKSk7XG4gICAgfVxuXG4gICAgcmV0dXJuIGNvbW1lbnRzLmZsYXQoKTtcbiAgfVxuXG4gIENyZWF0ZUNvbW1lbnQoY29tbWVudF9pZDogbnVtYmVyKSB7XG4gICAgbGV0IGNvbW1lbnQgPSB0aGlzLmNvbW1lbnRzXy5nZXQoY29tbWVudF9pZCk7XG4gICAgaWYgKCFjb21tZW50KSB7XG4gICAgICByZXR1cm47XG4gICAgfVxuXG4gICAgbGV0IGNvbW1lbnRfZWxlbSA9IGRvY3VtZW50LmNyZWF0ZUVsZW1lbnQoXCJsaVwiKTtcbiAgICBjb21tZW50X2VsZW0uY2xhc3NMaXN0LmFkZChcImNvbW1lbnRcIik7XG5cbiAgICBsZXQgY29tbWVudF9wcm9maWxlID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudChcImRpdlwiKTtcbiAgICBjb21tZW50X3Byb2ZpbGUuY2xhc3NMaXN0LmFkZChcImNvbW1lbnQtcHJvZmlsZVwiKTtcblxuICAgIGxldCBpbWFnZV9saW5rID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudChcImltZ1wiKTtcbiAgICBpZiAoY29tbWVudC5pbWFnZV9saW5rKSB7XG4gICAgICBpbWFnZV9saW5rLnNyYyA9IGNvbW1lbnQuaW1hZ2VfbGluaztcbiAgICAgIGltYWdlX2xpbmsuYWx0ID0gXCLtlITroZztlYQg7IKs7KeEXCI7XG4gICAgfSBlbHNlIHtcbiAgICAgIGltYWdlX2xpbmsuc3JjID0gXCIuL2ltZy91bmtub3duX3BlcnNvbi5wbmdcIjtcbiAgICAgIGltYWdlX2xpbmsuYWx0ID0gXCLtlITroZztlYQg7IKs7KeEIOyXhuydjFwiO1xuICAgIH1cblxuICAgIGNvbW1lbnRfcHJvZmlsZS5hcHBlbmRDaGlsZChpbWFnZV9saW5rKTtcbiAgICBjb21tZW50X2VsZW0uYXBwZW5kQ2hpbGQoY29tbWVudF9wcm9maWxlKTtcblxuICAgIGxldCBjb21tZW50X2luZm8gPSBkb2N1bWVudC5jcmVhdGVFbGVtZW50KFwiZGl2XCIpO1xuICAgIGNvbW1lbnRfaW5mby5jbGFzc0xpc3QuYWRkKFwiY29tbWVudC1pbmZvXCIpO1xuXG4gICAgLy8gQ29tbWVudCBoZWFkZXIuXG4gICAgbGV0IGNvbW1lbnRfaGVhZGVyID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudChcImRpdlwiKTtcbiAgICBjb21tZW50X2hlYWRlci5jbGFzc0xpc3QuYWRkKFwiY29tbWVudC1oZWFkZXJcIik7XG5cbiAgICBsZXQgY3JlYXRlU2ltcGxlU3BhbiA9IChjbGFzc19uYW1lOiBzdHJpbmcsIHRleHQ6IHN0cmluZykgPT4ge1xuICAgICAgbGV0IGVsZW0gPSBkb2N1bWVudC5jcmVhdGVFbGVtZW50KFwic3BhblwiKTtcbiAgICAgIGVsZW0uY2xhc3NMaXN0LmFkZChjbGFzc19uYW1lKTtcbiAgICAgIGVsZW0udGV4dENvbnRlbnQgPSB0ZXh0O1xuICAgICAgcmV0dXJuIGVsZW07XG4gICAgfTtcblxuICAgIGNvbW1lbnRfaGVhZGVyLmFwcGVuZENoaWxkKFxuICAgICAgY3JlYXRlU2ltcGxlU3BhbihcImNvbW1lbnQtYXV0aG9yXCIsIGNvbW1lbnQuYXV0aG9yX25hbWUgfHwgXCJcIilcbiAgICApO1xuICAgIGNvbW1lbnRfaGVhZGVyLmFwcGVuZENoaWxkKFxuICAgICAgY3JlYXRlU2ltcGxlU3BhbihcImNvbW1lbnQtZGF0ZVwiLCBjb21tZW50LmNvbW1lbnRfZGF0ZSB8fCBcIlwiKVxuICAgICk7XG5cbiAgICBjb21tZW50X2luZm8uYXBwZW5kQ2hpbGQoY29tbWVudF9oZWFkZXIpO1xuXG4gICAgLy8gQ29tbWVudCBjb250ZW50LlxuICAgIGxldCBjb21tZW50X2NvbnRlbnQgPSBkb2N1bWVudC5jcmVhdGVFbGVtZW50KFwiZGl2XCIpO1xuICAgIGNvbW1lbnRfY29udGVudC5jbGFzc0xpc3QuYWRkKFwiY29tbWVudC1jb250ZW50XCIpO1xuICAgIGNvbW1lbnRfY29udGVudC50ZXh0Q29udGVudCA9IGNvbW1lbnQuY29udGVudDtcbiAgICBjb21tZW50X2luZm8uYXBwZW5kQ2hpbGQoY29tbWVudF9jb250ZW50KTtcblxuICAgIGxldCBjb21tZW50X2FjdGlvbiA9IGRvY3VtZW50LmNyZWF0ZUVsZW1lbnQoXCJkaXZcIik7XG4gICAgY29tbWVudF9hY3Rpb24uY2xhc3NMaXN0LmFkZChcImNvbW1lbnQtYWN0aW9uXCIpO1xuICAgIGNvbW1lbnRfYWN0aW9uLmlkID0gXCJjb21tZW50LWlkLVwiICsgY29tbWVudF9pZDtcblxuICAgIGNvbW1lbnRfYWN0aW9uLmFwcGVuZENoaWxkKGNyZWF0ZVNpbXBsZVNwYW4oXCJjb21tZW50LXVwdm90ZVwiLCBcIuy2lOyynFwiKSk7XG4gICAgY29tbWVudF9hY3Rpb24uYXBwZW5kQ2hpbGQoY3JlYXRlU2ltcGxlU3BhbihcImNvbW1lbnQtcmVwbHlcIiwgXCLri7XquIBcIikpO1xuICAgIGNvbW1lbnRfYWN0aW9uLmFwcGVuZENoaWxkKGNyZWF0ZVNpbXBsZVNwYW4oXCJjb21tZW50LWRlbGV0ZVwiLCBcIuuLteq4gCDsgq3soJxcIikpO1xuICAgIGNvbW1lbnRfaW5mby5hcHBlbmRDaGlsZChjb21tZW50X2FjdGlvbik7XG5cbiAgICBjb21tZW50X2VsZW0uYXBwZW5kQ2hpbGQoY29tbWVudF9pbmZvKTtcblxuICAgIGlmICghY29tbWVudC5yZXBseV9pZHM/Lmxlbmd0aCkge1xuICAgICAgcmV0dXJuIFtjb21tZW50X2VsZW1dO1xuICAgIH1cblxuICAgIGxldCBjaGlsZF9jb21tZW50cyA9IGRvY3VtZW50LmNyZWF0ZUVsZW1lbnQoXCJ1bFwiKTtcbiAgICBjaGlsZF9jb21tZW50cy5jbGFzc0xpc3QuYWRkKFwiY29tbWVudC1saXN0XCIpO1xuXG4gICAgZm9yIChjb25zdCByZXBseV9pZCBvZiBjb21tZW50LnJlcGx5X2lkcykge1xuICAgICAgbGV0IGVsZW1zID0gdGhpcy5DcmVhdGVDb21tZW50KHJlcGx5X2lkKTtcbiAgICAgIGZvciAoY29uc3QgZWxlbSBvZiBlbGVtcykge1xuICAgICAgICBjaGlsZF9jb21tZW50cy5hcHBlbmQoZWxlbSk7XG4gICAgICB9XG4gICAgfVxuXG4gICAgcmV0dXJuIFtjb21tZW50X2VsZW0sIGNoaWxkX2NvbW1lbnRzXTtcbiAgfVxuXG4gIHByaXZhdGUgbGFzdF9jb21tZW50X2luZGV4XzogbnVtYmVyO1xuICBwcml2YXRlIGNvbW1lbnRzXzogTWFwPG51bWJlciwgQ29tbWVudD47XG4gIHByaXZhdGUgcm9vdF9jb21tZW50c186IENvbW1lbnRbXTtcbn1cblxuZXhwb3J0IGZ1bmN0aW9uIENyZWF0ZUNvbW1lbnRNYW5hZ2VyKCk6IENvbW1lbnRNYW5hZ2VyIHtcbiAgbGV0IGNvbW1lbnQgPSBuZXcgQ29tbWVudE1hbmFnZXIoKTtcbiAgcmV0dXJuIGNvbW1lbnQ7XG59XG4iLCJjbGFzcyBTY3JvbGwge1xuICBwdWJsaWMgY29uc3RydWN0b3IoKSB7XG4gICAgdGhpcy5sYXN0X3Bvc2l0aW9uID0gd2luZG93LnNjcm9sbFk7XG4gICAgdGhpcy50aW1lX3RvX3VwZGF0ZV90b2MgPSB0cnVlO1xuXG4gICAgdGhpcy5zY3JvbGxfZG93bl9ldmVudF9oYW5kbGVycyA9IFtdO1xuICAgIHRoaXMuc2Nyb2xsX3VwX2V2ZW50X2hhbmRsZXJzID0gW107XG5cbiAgICB0aGlzLkluc3RhbGxTY3JvbGxFdmVudEhhbmRsZXIoKTtcbiAgfVxuXG4gIHByaXZhdGUgSW5zdGFsbFNjcm9sbEV2ZW50SGFuZGxlcigpIHtcbiAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcignc2Nyb2xsJywgKGUpID0+IHtcbiAgICAgIGlmICh0aGlzLnRpbWVfdG9fdXBkYXRlX3RvYykge1xuICAgICAgICB3aW5kb3cucmVxdWVzdEFuaW1hdGlvbkZyYW1lKCgpID0+IHtcbiAgICAgICAgICB0aGlzLnRpbWVfdG9fdXBkYXRlX3RvYyA9IHRydWU7XG4gICAgICAgICAgaWYgKHRoaXMubGFzdF9wb3NpdGlvbiA+IHdpbmRvdy5zY3JvbGxZKSB7XG4gICAgICAgICAgICBmb3IgKGxldCBmdW5jIG9mIHRoaXMuc2Nyb2xsX3VwX2V2ZW50X2hhbmRsZXJzKSB7XG4gICAgICAgICAgICAgIGZ1bmMoKTtcbiAgICAgICAgICAgIH1cbiAgICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgZm9yIChsZXQgZnVuYyBvZiB0aGlzLnNjcm9sbF9kb3duX2V2ZW50X2hhbmRsZXJzKSB7XG4gICAgICAgICAgICAgIGZ1bmMoKTtcbiAgICAgICAgICAgIH1cbiAgICAgICAgICB9XG4gICAgICAgICAgdGhpcy5sYXN0X3Bvc2l0aW9uID0gd2luZG93LnNjcm9sbFk7XG4gICAgICAgIH0pO1xuICAgICAgICB0aGlzLnRpbWVfdG9fdXBkYXRlX3RvYyA9IGZhbHNlO1xuICAgICAgfVxuICAgIH0pO1xuICB9XG5cbiAgcHVibGljIFJlZ2lzdGVyU2Nyb2xsVXBIYW5kbGVyKGZ1bmM6ICgpPT52b2lkKSB7XG4gICAgdGhpcy5zY3JvbGxfdXBfZXZlbnRfaGFuZGxlcnMucHVzaChmdW5jKTtcbiAgfVxuXG4gIHB1YmxpYyBSZWdpc3RlclNjcm9sbERvd25IYW5kbGVyKGZ1bmM6ICgpPT52b2lkKSB7XG4gICAgdGhpcy5zY3JvbGxfZG93bl9ldmVudF9oYW5kbGVycy5wdXNoKGZ1bmMpO1xuICB9XG5cbiAgcHJpdmF0ZSBsYXN0X3Bvc2l0aW9uOiBudW1iZXI7XG5cbiAgLy8gTWFrZSBzdXJlIG5vdCB0byBoYW5kbGUgc2Nyb2xsIGV2ZW50IHRvbyBvZnRlbi5cbiAgcHJpdmF0ZSB0aW1lX3RvX3VwZGF0ZV90b2M6IGJvb2xlYW47XG5cbiAgcHJpdmF0ZSBzY3JvbGxfZG93bl9ldmVudF9oYW5kbGVyczogKCgpPT4gdm9pZClbXTtcbiAgcHJpdmF0ZSBzY3JvbGxfdXBfZXZlbnRfaGFuZGxlcnM6ICgoKT0+IHZvaWQpW107XG59XG5cbmV4cG9ydCBmdW5jdGlvbiBDcmVhdGVTY3JvbGxIYW5kbGVyKCkgOiBTY3JvbGwge1xuICBsZXQgc2Nyb2xsID0gbmV3IFNjcm9sbCgpO1xuICByZXR1cm4gc2Nyb2xsO1xufVxuIiwiZXhwb3J0IGZ1bmN0aW9uIFN0cmlwUHJlZml4TmJzcChzdHI6IHN0cmluZyk6IHN0cmluZyB7XG4gIGxldCBpID0gMDtcbiAgZm9yICg7IGkgPCBzdHIubGVuZ3RoOyBpKyspIHtcbiAgICBpZiAoc3RyW2ldID09ICfCoCcpIHsgIC8vIFRoaXMgaXMgbm90IHNwYWNlLiBUaGlzIGlzIHVuaWNvZGUgTkJTUCAoVSswMEEwKVxuICAgICAgY29udGludWU7XG4gICAgfSBlbHNlIHtcbiAgICAgIGJyZWFrO1xuICAgIH1cbiAgfVxuICByZXR1cm4gc3RyLnN1YnN0cmluZyhpKTtcbn1cblxuZXhwb3J0IGZ1bmN0aW9uIEdldEhlYWRlck51bShzdHI6IHN0cmluZyk6IG51bWJlciB7XG4gIGlmICghKHN0clswXSA9PSAnaCcgfHwgc3RyWzBdID09ICdIJykpIHtcbiAgICByZXR1cm4gLTE7XG4gIH1cblxuICByZXR1cm4gcGFyc2VJbnQoc3RyLnN1YnN0cmluZygxKSk7XG59XG5cbmV4cG9ydCBmdW5jdGlvbiBJc0VsZW1lbnRJblZpZXdQb3J0KGVsOiBIVE1MRWxlbWVudCk6IGJvb2xlYW4ge1xuICBsZXQgYm91bmRpbmcgPSBlbC5nZXRCb3VuZGluZ0NsaWVudFJlY3QoKTtcbiAgcmV0dXJuIGJvdW5kaW5nLnRvcCA+PSAwICYmIGJvdW5kaW5nLmxlZnQgPj0gMCAmJlxuICAgICAgYm91bmRpbmcucmlnaHQgPD1cbiAgICAgICh3aW5kb3cuaW5uZXJXaWR0aCB8fCBkb2N1bWVudC5kb2N1bWVudEVsZW1lbnQuY2xpZW50V2lkdGgpICYmXG4gICAgICBib3VuZGluZy5ib3R0b20gPD1cbiAgICAgICh3aW5kb3cuaW5uZXJIZWlnaHQgfHwgZG9jdW1lbnQuZG9jdW1lbnRFbGVtZW50LmNsaWVudEhlaWdodCk7XG59IiwiaW1wb3J0ICogYXMgVXRpbCBmcm9tICcuL3V0aWwnO1xuXG5pbnRlcmZhY2UgVE9DSGVhZGVyIHtcbiAgaGVhZGVyX25hbWU6IHN0cmluZztcbiAgaGVhZGVyX3RhZzogbnVtYmVyO1xuICBoZWFkZXJfaWQ6IHN0cmluZztcbiAgaGVhZGVyX3BvczogbnVtYmVyO1xuICBoZWFkZXJfZWxlbV9saW5rOiBIVE1MQW5jaG9yRWxlbWVudDtcbn1cblxuY2xhc3MgVE9DIHtcbiAgY29uc3RydWN0b3IoKSB7XG4gICAgdGhpcy50b2NfaGVhZGVyc18gPSBbXTtcbiAgICB0aGlzLnRpbWVfdG9fdXBkYXRlX3RvYyA9IHRydWU7XG4gICAgdGhpcy5wcmV2X2hpZ2hsaWdodGVkID0gMDtcblxuICAgIC8vIEZldGNoIFRPQyBIZWFkZXJzLlxuICAgIHRoaXMuRmV0Y2hIZWFkZXJzKCk7XG4gIH1cblxuICBwcml2YXRlIEZldGNoSGVhZGVycygpIHtcbiAgICAvLyBGaXJzdCBpZGVudGlmeSBhbGwgdGhlIGhlYWRlcnMuXG4gICAgbGV0IGhlYWRlcnM6IE5vZGVMaXN0T2Y8RWxlbWVudD4gPVxuICAgICAgICBkb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCcuaGVhZGVyLWdlbmVyYWwnKTtcblxuICAgIGZvciAobGV0IGhlYWRlciBvZiBoZWFkZXJzIGFzIGFueSkge1xuICAgICAgbGV0IGhlYWRlcl9uYW1lOiBzdHJpbmcgPSBVdGlsLlN0cmlwUHJlZml4TmJzcChoZWFkZXIuaW5uZXJUZXh0KTtcbiAgICAgIGxldCBoZWFkZXJfdGFnOiBudW1iZXIgPSBVdGlsLkdldEhlYWRlck51bShoZWFkZXIudGFnTmFtZSk7XG4gICAgICBsZXQgaGVhZGVyX2lkOiBzdHJpbmcgPSBoZWFkZXIuaWQ7XG4gICAgICBsZXQgaGVhZGVyX3BvczogbnVtYmVyID1cbiAgICAgICAgICBoZWFkZXIuZ2V0Qm91bmRpbmdDbGllbnRSZWN0KCkudG9wICsgd2luZG93LnNjcm9sbFk7XG4gICAgICB0aGlzLnRvY19oZWFkZXJzXy5wdXNoKHtcbiAgICAgICAgaGVhZGVyX25hbWUsXG4gICAgICAgIGhlYWRlcl90YWcsXG4gICAgICAgIGhlYWRlcl9pZCxcbiAgICAgICAgaGVhZGVyX3BvcyxcbiAgICAgICAgaGVhZGVyX2VsZW1fbGluazogbnVsbFxuICAgICAgfSk7XG4gICAgfVxuICB9XG5cbiAgcHJpdmF0ZSBSZWN1cnNpdmVUT0NDcmVhdG9yKFxuICAgICAgcGFyZW50X29sOiBIVE1MT0xpc3RFbGVtZW50LCBjdXJyZW50X2hlYWRlcl9udW06IG51bWJlcixcbiAgICAgIHRhZ19udW1iZXI6IG51bWJlcikge1xuICAgIGxldCBjdXJyZW50X2xpID0gbnVsbDtcbiAgICBsZXQgaSA9IGN1cnJlbnRfaGVhZGVyX251bTtcbiAgICBmb3IgKDsgaSA8IHRoaXMudG9jX2hlYWRlcnNfLmxlbmd0aDsgaSsrKSB7XG4gICAgICBsZXQgaGVhZGVyID0gdGhpcy50b2NfaGVhZGVyc19baV07XG5cbiAgICAgIC8vIGgzIC0+IGgyXG4gICAgICBpZiAoaGVhZGVyLmhlYWRlcl90YWcgPCB0YWdfbnVtYmVyKSB7XG4gICAgICAgIHJldHVybiBpO1xuICAgICAgfVxuICAgICAgLy8gaDIgLT4gaDNcbiAgICAgIGVsc2UgaWYgKGhlYWRlci5oZWFkZXJfdGFnID4gdGFnX251bWJlcikge1xuICAgICAgICBsZXQgY2hpbGRfcGFyZW50X29sID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudCgnb2wnKSBhcyBIVE1MT0xpc3RFbGVtZW50O1xuICAgICAgICBjaGlsZF9wYXJlbnRfb2wuY2xhc3NOYW1lID0gJ3RvYy1saXN0JztcbiAgICAgICAgY3VycmVudF9saS5hcHBlbmRDaGlsZChjaGlsZF9wYXJlbnRfb2wpO1xuICAgICAgICBpID0gdGhpcy5SZWN1cnNpdmVUT0NDcmVhdG9yKGNoaWxkX3BhcmVudF9vbCwgaSwgaGVhZGVyLmhlYWRlcl90YWcpO1xuICAgICAgICBpLS07XG4gICAgICB9IGVsc2Uge1xuICAgICAgICBsZXQgZWxlbWVudCA9IEJ1aWxkQ2F0ZWdvcnlMaXN0RWxlbWVudChoZWFkZXIpO1xuICAgICAgICBoZWFkZXIuaGVhZGVyX2VsZW1fbGluayA9IGVsZW1lbnQuZmlyc3RDaGlsZCBhcyBIVE1MQW5jaG9yRWxlbWVudDtcbiAgICAgICAgcGFyZW50X29sLmFwcGVuZENoaWxkKGVsZW1lbnQpO1xuICAgICAgICBjdXJyZW50X2xpID0gZWxlbWVudDtcbiAgICAgIH1cbiAgICB9XG4gICAgcmV0dXJuIGk7XG4gIH1cblxuICBwdWJsaWMgQ3JlYXRlVE9DTGlzdCgpIHtcbiAgICBsZXQgcm9vdF9vbCA9IGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoJy50b2MtbGlzdCcpIGFzIEhUTUxPTGlzdEVsZW1lbnQ7XG4gICAgaWYgKHJvb3Rfb2wgPT0gbnVsbCkge1xuICAgICAgcmV0dXJuO1xuICAgIH1cbiAgICB0aGlzLlJlY3Vyc2l2ZVRPQ0NyZWF0b3Iocm9vdF9vbCwgMCwgdGhpcy50b2NfaGVhZGVyc19bMF0uaGVhZGVyX3RhZyk7XG5cbiAgICB0aGlzLkluc3RhbGxUT0NFdmVudEhhbmRsZXJzKCk7XG4gIH1cblxuICBwcml2YXRlIEluc3RhbGxUT0NFdmVudEhhbmRsZXJzKCkge1xuICAgIGxldCB0aGF0ID0gdGhpcztcbiAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcignc2Nyb2xsJywgZnVuY3Rpb24oKSB7XG4gICAgICBsZXQgbGFzdF9rbm93bl9zY3JvbGxfcG9zID0gd2luZG93LnNjcm9sbFk7XG4gICAgICBpZiAodGhhdC50aW1lX3RvX3VwZGF0ZV90b2MpIHtcbiAgICAgICAgd2luZG93LnJlcXVlc3RBbmltYXRpb25GcmFtZShmdW5jdGlvbigpIHtcbiAgICAgICAgICB0aGF0LnRpbWVfdG9fdXBkYXRlX3RvYyA9IHRydWU7XG4gICAgICAgICAgbGV0IGhlYWRlcl9udW0gPSB0aGF0LkdldEN1cnJlbnRBY3RpdmVUT0NJdGVtKGxhc3Rfa25vd25fc2Nyb2xsX3Bvcyk7XG4gICAgICAgICAgdGhhdC5IaWdobGlnaHRBY3RpdmVJdGVtKGhlYWRlcl9udW0pO1xuICAgICAgICB9KTtcbiAgICAgICAgdGhhdC50aW1lX3RvX3VwZGF0ZV90b2MgPSBmYWxzZTtcbiAgICAgIH1cbiAgICB9KVxuICB9XG5cbiAgcHJpdmF0ZSBIaWdobGlnaHRBY3RpdmVJdGVtKGl0ZW1fbnVtOiBudW1iZXIpIHtcbiAgICB0aGlzLnRvY19oZWFkZXJzX1t0aGlzLnByZXZfaGlnaGxpZ2h0ZWRdLmhlYWRlcl9lbGVtX2xpbmsuY2xhc3NOYW1lID1cbiAgICAgICAgJ3RvYy1pdGVtLWxpbmsnO1xuICAgIHRoaXMudG9jX2hlYWRlcnNfW2l0ZW1fbnVtXS5oZWFkZXJfZWxlbV9saW5rLmNsYXNzTmFtZSA9XG4gICAgICAgICd0b2MtaXRlbS1saW5rIHRvYy1hY3RpdmUtaXRlbSc7XG4gICAgdGhpcy5wcmV2X2hpZ2hsaWdodGVkID0gaXRlbV9udW07XG4gIH1cblxuICBwdWJsaWMgSW5zdGFsbExpbmtDbGlja0hhbmRsZXIoKSB7XG4gICAgZm9yIChsZXQgaGVhZGVyIG9mIHRoaXMudG9jX2hlYWRlcnNfKSB7XG4gICAgICBoZWFkZXIuaGVhZGVyX2VsZW1fbGluay5vbmNsaWNrID0gKGU6IE1vdXNlRXZlbnQpID0+IHtcbiAgICAgICAgd2luZG93LnNjcm9sbFRvKDAsIGhlYWRlci5oZWFkZXJfcG9zIC0gMTUwKTtcbiAgICAgICAgY29uc29sZS5sb2coaGVhZGVyLmhlYWRlcl9wb3MgLSAxNTApO1xuICAgICAgfTtcbiAgICB9XG4gIH1cblxuICBwcml2YXRlIEdldEN1cnJlbnRBY3RpdmVUT0NJdGVtKHNjcm9sbF9wb3M6IG51bWJlcikge1xuICAgIGlmIChzY3JvbGxfcG9zIDwgdGhpcy50b2NfaGVhZGVyc19bMF0uaGVhZGVyX3Bvcykge1xuICAgICAgcmV0dXJuIDA7XG4gICAgfVxuXG4gICAgbGV0IGkgPSAwO1xuICAgIGZvciAoOyBpIDwgdGhpcy50b2NfaGVhZGVyc18ubGVuZ3RoOyBpKyspIHtcbiAgICAgIGlmIChpID09IHRoaXMudG9jX2hlYWRlcnNfLmxlbmd0aCAtIDEpIHtcbiAgICAgICAgYnJlYWs7XG4gICAgICB9IGVsc2UgaWYgKFxuICAgICAgICAgIHRoaXMudG9jX2hlYWRlcnNfW2ldLmhlYWRlcl9wb3MgPD0gc2Nyb2xsX3BvcyAmJlxuICAgICAgICAgIHNjcm9sbF9wb3MgPCB0aGlzLnRvY19oZWFkZXJzX1tpICsgMV0uaGVhZGVyX3Bvcykge1xuICAgICAgICBpZiAoc2Nyb2xsX3BvcyAtIHRoaXMudG9jX2hlYWRlcnNfW2ldLmhlYWRlcl9wb3MgPlxuICAgICAgICAgICAgICAgIHRoaXMudG9jX2hlYWRlcnNfW2kgKyAxXS5oZWFkZXJfcG9zIC0gc2Nyb2xsX3BvcyAmJlxuICAgICAgICAgICAgVXRpbC5Jc0VsZW1lbnRJblZpZXdQb3J0KFxuICAgICAgICAgICAgICAgIHRoaXMudG9jX2hlYWRlcnNfW2kgKyAxXS5oZWFkZXJfZWxlbV9saW5rKSkge1xuICAgICAgICAgIHJldHVybiBpICsgMTtcbiAgICAgICAgfSBlbHNlIHtcbiAgICAgICAgICByZXR1cm4gaTtcbiAgICAgICAgfVxuICAgICAgfVxuICAgIH1cbiAgICByZXR1cm4gaTtcbiAgfVxuXG4gIHByaXZhdGUgdG9jX2hlYWRlcnNfOiBUT0NIZWFkZXJbXTtcbiAgcHJpdmF0ZSB0aW1lX3RvX3VwZGF0ZV90b2M6IGJvb2xlYW47XG4gIHByaXZhdGUgcHJldl9oaWdobGlnaHRlZDogbnVtYmVyO1xufVxuXG5mdW5jdGlvbiBCdWlsZENhdGVnb3J5TGlzdEVsZW1lbnQoaGVhZGVyOiBUT0NIZWFkZXIpOiBIVE1MTElFbGVtZW50IHtcbiAgbGV0IGVsZW1lbnQgPSBkb2N1bWVudC5jcmVhdGVFbGVtZW50KCdsaScpIGFzIEhUTUxMSUVsZW1lbnQ7XG4gIGVsZW1lbnQuY2xhc3NOYW1lID0gJ3RvYy1saXN0LWl0ZW0nO1xuXG4gIGxldCBsaW5rID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudCgnc3BhbicpIGFzIEhUTUxTcGFuRWxlbWVudDtcbiAgbGluay5jbGFzc05hbWUgPSAndG9jLWl0ZW0tbGluaydcbiAgbGluay50ZXh0Q29udGVudCA9IGhlYWRlci5oZWFkZXJfbmFtZTtcblxuICBlbGVtZW50LmFwcGVuZENoaWxkKGxpbmspO1xuICByZXR1cm4gZWxlbWVudDtcbn1cblxuZXhwb3J0IGZ1bmN0aW9uIEJ1aWxkVGFibGVPZkNvbnRlbnRzKCk6IFRPQyB7XG4gIGxldCB0b2MgPSBuZXcgVE9DKCk7XG4gIHRvYy5DcmVhdGVUT0NMaXN0KCk7XG5cbiAgLy8gSW5zdGFsbCBjbGljayBoYW5kbGVycy5cbiAgdG9jLkluc3RhbGxMaW5rQ2xpY2tIYW5kbGVyKCk7XG4gIHJldHVybiB0b2M7XG59XG4iLCJpbXBvcnQgeyBDcmVhdGVDb21tZW50TWFuYWdlciB9IGZyb20gXCIuL2NvbW1lbnRcIjtcbmltcG9ydCAqIGFzIFNjcm9sbCBmcm9tIFwiLi9zY3JvbGxcIjtcbmltcG9ydCAqIGFzIFRPQyBmcm9tIFwiLi90b2NcIjtcblxuLy8gTWFpbiBlbnRyeSBwb2ludC5cbmFzeW5jIGZ1bmN0aW9uIE1haW4oKSB7XG4gIFRPQy5CdWlsZFRhYmxlT2ZDb250ZW50cygpO1xuXG4gIGxldCBzY3JvbGwgPSBTY3JvbGwuQ3JlYXRlU2Nyb2xsSGFuZGxlcigpO1xuICBzY3JvbGwuUmVnaXN0ZXJTY3JvbGxVcEhhbmRsZXIoKCkgPT4ge1xuICAgIC8qXG4gICAgY29uc29sZS5sb2coZG9jdW1lbnQucXVlcnlTZWxlY3RvcihcIjp0YXJnZXRcIikpO1xuICAgIGxldCBwYWRkZWRfaGVhZGVyID0gZG9jdW1lbnQucXVlcnlTZWxlY3RvcihcIjp0YXJnZXRcIikgYXMgSFRNTEFuY2hvckVsZW1lbnQ7XG4gICAgaWYgKHBhZGRlZF9oZWFkZXIuc3R5bGUucGFkZGluZ1RvcCAhPSBcIjBcIikge1xuICAgICAgcGFkZGVkX2hlYWRlci5zdHlsZS5wYWRkaW5nVG9wID0gXCIwXCI7XG4gICAgfVxuXG4gICAgLy8gUmVtb3ZlICMgZnJvbSB1cmwuXG4gICAgaGlzdG9yeS5yZXBsYWNlU3RhdGUobnVsbCwgbnVsbCwgJyAnKTsqL1xuICB9KTtcblxuICBsZXQgY29tbWVudF9tYW5hZ2VyID0gQ3JlYXRlQ29tbWVudE1hbmFnZXIoKTtcbiAgYXdhaXQgY29tbWVudF9tYW5hZ2VyLkxvYWRDb21tZW50cygpO1xuXG4gIGNvbW1lbnRfbWFuYWdlci5Db21wdXRlUm9vdENvbW1lbnRzKCk7XG4gIGZvciAoY29uc3QgZWxlbSBvZiBjb21tZW50X21hbmFnZXIuQ3JlYXRlQ29tbWVudExpc3QoKSkge1xuICAgIGNvbnNvbGUubG9nKGVsZW0uaW5uZXJIVE1MKTtcbiAgfVxuICBjb25zb2xlLmxvZyhjb21tZW50X21hbmFnZXIuQ3JlYXRlQ29tbWVudExpc3QoKSk7XG59XG5cbndpbmRvdy5vbmxvYWQgPSAoKSA9PiB7XG4gIE1haW4oKTtcbn07XG4iXSwibmFtZXMiOlsidGhpcyIsImxhc3RfY29tbWVudF9pbmRleF8iLCJjb21tZW50c18iLCJNYXAiLCJyb290X2NvbW1lbnRzXyIsIkxvYWRDb21tZW50cyIsInVybCIsIndpbmRvdyIsImxvY2F0aW9uIiwicGF0aG5hbWUiLCJhcnRpY2xlX3VybCIsInN1YnN0ciIsImxhc3RJbmRleE9mIiwiZmV0Y2giLCJtZXRob2QiLCJtb2RlIiwiY2FjaGUiLCJoZWFkZXJzIiwiQWNjZXB0IiwiYm9keSIsIkpTT04iLCJzdHJpbmdpZnkiLCJpbmRleF9zdGFydCIsImpzb24iLCJnZXRfY29tbWVudF9yZXNwb25zZSIsImNvbW1lbnRzIiwiY29tbWVudCIsInNldCIsImNvbW1lbnRfaWQiLCJDb21wdXRlUm9vdENvbW1lbnRzIiwiY29tbWVudF9pZHMiLCJBcnJheSIsImZyb20iLCJrZXlzIiwic29ydCIsImEiLCJiIiwidmlzaXRlZF9jb21tZW50cyIsIlNldCIsImhhcyIsInB1c2giLCJnZXQiLCJWaXNpdEFsbENoaWxkQ29tbWVudHMiLCJyZXZlcnNlIiwiYWRkIiwicmVwbHlfaWRzIiwiY2hpbGRfY29tbWVudF9pZCIsIkNyZWF0ZUNvbW1lbnRMaXN0IiwiQ3JlYXRlQ29tbWVudCIsImZsYXQiLCJjb21tZW50X2VsZW0iLCJkb2N1bWVudCIsImNyZWF0ZUVsZW1lbnQiLCJjbGFzc0xpc3QiLCJjb21tZW50X3Byb2ZpbGUiLCJpbWFnZV9saW5rIiwic3JjIiwiYWx0IiwiYXBwZW5kQ2hpbGQiLCJjb21tZW50X2luZm8iLCJjb21tZW50X2hlYWRlciIsImNyZWF0ZVNpbXBsZVNwYW4iLCJjbGFzc19uYW1lIiwidGV4dCIsImVsZW0iLCJ0ZXh0Q29udGVudCIsImF1dGhvcl9uYW1lIiwiY29tbWVudF9kYXRlIiwiY29tbWVudF9jb250ZW50IiwiY29udGVudCIsImNvbW1lbnRfYWN0aW9uIiwiaWQiLCJsZW5ndGgiLCJjaGlsZF9jb21tZW50cyIsInJlcGx5X2lkIiwiYXBwZW5kIiwibGFzdF9wb3NpdGlvbiIsInNjcm9sbFkiLCJ0aW1lX3RvX3VwZGF0ZV90b2MiLCJzY3JvbGxfZG93bl9ldmVudF9oYW5kbGVycyIsInNjcm9sbF91cF9ldmVudF9oYW5kbGVycyIsIkluc3RhbGxTY3JvbGxFdmVudEhhbmRsZXIiLCJhZGRFdmVudExpc3RlbmVyIiwiZSIsInJlcXVlc3RBbmltYXRpb25GcmFtZSIsImZ1bmMiLCJSZWdpc3RlclNjcm9sbFVwSGFuZGxlciIsIlJlZ2lzdGVyU2Nyb2xsRG93bkhhbmRsZXIiLCJTdHJpcFByZWZpeE5ic3AiLCJzdHIiLCJpIiwic3Vic3RyaW5nIiwidG9jX2hlYWRlcnNfIiwicHJldl9oaWdobGlnaHRlZCIsIkZldGNoSGVhZGVycyIsInF1ZXJ5U2VsZWN0b3JBbGwiLCJoZWFkZXIiLCJoZWFkZXJfbmFtZSIsImlubmVyVGV4dCIsImhlYWRlcl90YWciLCJ0YWdOYW1lIiwicGFyc2VJbnQiLCJoZWFkZXJfaWQiLCJoZWFkZXJfcG9zIiwiZ2V0Qm91bmRpbmdDbGllbnRSZWN0IiwidG9wIiwiaGVhZGVyX2VsZW1fbGluayIsIlJlY3Vyc2l2ZVRPQ0NyZWF0b3IiLCJwYXJlbnRfb2wiLCJjdXJyZW50X2hlYWRlcl9udW0iLCJ0YWdfbnVtYmVyIiwiY3VycmVudF9saSIsImNoaWxkX3BhcmVudF9vbCIsImNsYXNzTmFtZSIsImVsZW1lbnQiLCJCdWlsZENhdGVnb3J5TGlzdEVsZW1lbnQiLCJmaXJzdENoaWxkIiwiQ3JlYXRlVE9DTGlzdCIsInJvb3Rfb2wiLCJxdWVyeVNlbGVjdG9yIiwiSW5zdGFsbFRPQ0V2ZW50SGFuZGxlcnMiLCJ0aGF0IiwibGFzdF9rbm93bl9zY3JvbGxfcG9zIiwiaGVhZGVyX251bSIsIkdldEN1cnJlbnRBY3RpdmVUT0NJdGVtIiwiSGlnaGxpZ2h0QWN0aXZlSXRlbSIsIml0ZW1fbnVtIiwiSW5zdGFsbExpbmtDbGlja0hhbmRsZXIiLCJvbmNsaWNrIiwic2Nyb2xsVG8iLCJjb25zb2xlIiwibG9nIiwic2Nyb2xsX3BvcyIsImJvdW5kaW5nIiwibGVmdCIsInJpZ2h0IiwiaW5uZXJXaWR0aCIsImRvY3VtZW50RWxlbWVudCIsImNsaWVudFdpZHRoIiwiYm90dG9tIiwiaW5uZXJIZWlnaHQiLCJjbGllbnRIZWlnaHQiLCJsaW5rIiwiTWFpbiIsInRvYyIsIlRPQyIsIlNjcm9sbCIsImNvbW1lbnRfbWFuYWdlciIsIkNvbW1lbnRNYW5hZ2VyIiwiaW5uZXJIVE1MIiwib25sb2FkIl0sInNvdXJjZVJvb3QiOiIifQ==