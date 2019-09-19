!function(e){var t={};function r(n){if(t[n])return t[n].exports;var o=t[n]={i:n,l:!1,exports:{}};return e[n].call(o.exports,o,o.exports,r),o.l=!0,o.exports}r.m=e,r.c=t,r.d=function(e,t,n){r.o(e,t)||Object.defineProperty(e,t,{enumerable:!0,get:n})},r.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},r.t=function(e,t){if(1&t&&(e=r(e)),8&t)return e;if(4&t&&"object"==typeof e&&e&&e.__esModule)return e;var n=Object.create(null);if(r.r(n),Object.defineProperty(n,"default",{enumerable:!0,value:e}),2&t&&"string"!=typeof e)for(var o in e)r.d(n,o,function(t){return e[t]}.bind(null,o));return n},r.n=function(e){var t=e&&e.__esModule?function(){return e.default}:function(){return e};return r.d(t,"a",t),t},r.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},r.p="",r(r.s=0)}([function(e,t,r){"use strict";r.r(t);var n=function(){function e(){this.last_position=window.scrollY,this.time_to_update_toc=!0,this.scroll_down_event_handlers=[],this.scroll_up_event_handlers=[],this.InstallScrollEventHandler()}return e.prototype.InstallScrollEventHandler=function(){var e=this;window.addEventListener("scroll",function(t){e.time_to_update_toc&&(window.requestAnimationFrame(function(){if(e.time_to_update_toc=!0,e.last_position>window.scrollY)for(var t=0,r=e.scroll_up_event_handlers;t<r.length;t++){(0,r[t])()}else for(var n=0,o=e.scroll_down_event_handlers;n<o.length;n++){(0,o[n])()}e.last_position=window.scrollY}),e.time_to_update_toc=!1)})},e.prototype.RegisterScrollUpHandler=function(e){this.scroll_up_event_handlers.push(e)},e.prototype.RegisterScrollDownHandler=function(e){this.scroll_down_event_handlers.push(e)},e}();function o(e){for(var t=0;t<e.length&&" "==e[t];t++);return e.substring(t)}var i=function(){function e(){this.toc_headers_=[],this.time_to_update_toc=!0,this.prev_highlighted=0,this.FetchHeaders()}return e.prototype.FetchHeaders=function(){for(var e,t=0,r=document.querySelectorAll(".header-general");t<r.length;t++){var n=r[t],i=o(n.innerText),l="h"!=(e=n.tagName)[0]&&"H"!=e[0]?-1:parseInt(e.substring(1)),a=n.id,s=n.getBoundingClientRect().top+window.scrollY;this.toc_headers_.push({header_name:i,header_tag:l,header_id:a,header_pos:s,header_elem_link:null})}},e.prototype.RecursiveTOCCreator=function(e,t,r){for(var n=null,o=t;o<this.toc_headers_.length;o++){var i=this.toc_headers_[o];if(i.header_tag<r)return o;if(i.header_tag>r){var a=document.createElement("ol");a.className="toc-list",n.appendChild(a),o=this.RecursiveTOCCreator(a,o,i.header_tag),o--}else{var s=l(i);i.header_elem_link=s.firstChild,e.appendChild(s),n=s}}return o},e.prototype.CreateTOCList=function(){var e=document.querySelector(".toc-list");null!=e&&(this.RecursiveTOCCreator(e,0,this.toc_headers_[0].header_tag),this.InstallTOCEventHandlers())},e.prototype.InstallTOCEventHandlers=function(){var e=this;window.addEventListener("scroll",function(t){var r=window.scrollY;e.time_to_update_toc&&(window.requestAnimationFrame(function(){e.time_to_update_toc=!0;var t=e.GetCurrentActiveTOCItem(r);e.HighlightActiveItem(t)}),e.time_to_update_toc=!1)})},e.prototype.HighlightActiveItem=function(e){this.toc_headers_[this.prev_highlighted].header_elem_link.className="toc-item-link",this.toc_headers_[e].header_elem_link.className="toc-item-link toc-active-item",this.prev_highlighted=e},e.prototype.InstallLinkClickHandler=function(){for(var e=function(e){e.header_elem_link.onclick=function(t){window.scrollTo(0,e.header_pos-150),console.log(e.header_pos-150)}},t=0,r=this.toc_headers_;t<r.length;t++){e(r[t])}},e.prototype.GetCurrentActiveTOCItem=function(e){if(e<this.toc_headers_[0].header_pos)return 0;for(var t=0;t<this.toc_headers_.length&&t!=this.toc_headers_.length-1;t++)if(this.toc_headers_[t].header_pos<=e&&e<this.toc_headers_[t+1].header_pos)return e-this.toc_headers_[t].header_pos<this.toc_headers_[t+1].header_pos-e?t:t+1;return t},e}();function l(e){var t=document.createElement("li");t.className="toc-list-item";var r=document.createElement("span");return r.className="toc-item-link",r.textContent=e.header_name,t.appendChild(r),t}function a(){var e;(e=new i).CreateTOCList(),e.InstallLinkClickHandler(),(new n).RegisterScrollUpHandler(function(){})}window.onload=function(){a()}}]);
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIndlYnBhY2s6Ly8vd2VicGFjay9ib290c3RyYXAiLCJ3ZWJwYWNrOi8vLy4vc3JjL3Njcm9sbC50cyIsIndlYnBhY2s6Ly8vLi9zcmMvdXRpbC50cyIsIndlYnBhY2s6Ly8vLi9zcmMvdG9jLnRzIiwid2VicGFjazovLy8uL3NyYy9pbmRleC50cyJdLCJuYW1lcyI6WyJpbnN0YWxsZWRNb2R1bGVzIiwiX193ZWJwYWNrX3JlcXVpcmVfXyIsIm1vZHVsZUlkIiwiZXhwb3J0cyIsIm1vZHVsZSIsImkiLCJsIiwibW9kdWxlcyIsImNhbGwiLCJtIiwiYyIsImQiLCJuYW1lIiwiZ2V0dGVyIiwibyIsIk9iamVjdCIsImRlZmluZVByb3BlcnR5IiwiZW51bWVyYWJsZSIsImdldCIsInIiLCJTeW1ib2wiLCJ0b1N0cmluZ1RhZyIsInZhbHVlIiwidCIsIm1vZGUiLCJfX2VzTW9kdWxlIiwibnMiLCJjcmVhdGUiLCJrZXkiLCJiaW5kIiwibiIsIm9iamVjdCIsInByb3BlcnR5IiwicHJvdG90eXBlIiwiaGFzT3duUHJvcGVydHkiLCJwIiwicyIsIlNjcm9sbCIsInRoaXMiLCJsYXN0X3Bvc2l0aW9uIiwid2luZG93Iiwic2Nyb2xsWSIsInRpbWVfdG9fdXBkYXRlX3RvYyIsInNjcm9sbF9kb3duX2V2ZW50X2hhbmRsZXJzIiwic2Nyb2xsX3VwX2V2ZW50X2hhbmRsZXJzIiwiSW5zdGFsbFNjcm9sbEV2ZW50SGFuZGxlciIsIl90aGlzIiwiYWRkRXZlbnRMaXN0ZW5lciIsImUiLCJyZXF1ZXN0QW5pbWF0aW9uRnJhbWUiLCJfaSIsIl9hIiwibGVuZ3RoIiwiZnVuYyIsIl9iIiwiX2MiLCJSZWdpc3RlclNjcm9sbFVwSGFuZGxlciIsInB1c2giLCJSZWdpc3RlclNjcm9sbERvd25IYW5kbGVyIiwiU3RyaXBQcmVmaXhOYnNwIiwic3RyIiwic3Vic3RyaW5nIiwidG9jX1RPQyIsIlRPQyIsInRvY19oZWFkZXJzXyIsInByZXZfaGlnaGxpZ2h0ZWQiLCJGZXRjaEhlYWRlcnMiLCJkb2N1bWVudCIsInF1ZXJ5U2VsZWN0b3JBbGwiLCJoZWFkZXIiLCJoZWFkZXJfbmFtZSIsImlubmVyVGV4dCIsImhlYWRlcl90YWciLCJ0YWdOYW1lIiwicGFyc2VJbnQiLCJoZWFkZXJfaWQiLCJpZCIsImhlYWRlcl9wb3MiLCJnZXRCb3VuZGluZ0NsaWVudFJlY3QiLCJ0b3AiLCJoZWFkZXJfZWxlbV9saW5rIiwiUmVjdXJzaXZlVE9DQ3JlYXRvciIsInBhcmVudF9vbCIsImN1cnJlbnRfaGVhZGVyX251bSIsInRhZ19udW1iZXIiLCJjdXJyZW50X2xpIiwiY2hpbGRfcGFyZW50X29sIiwiY3JlYXRlRWxlbWVudCIsImNsYXNzTmFtZSIsImFwcGVuZENoaWxkIiwiZWxlbWVudCIsIkJ1aWxkQ2F0ZWdvcnlMaXN0RWxlbWVudCIsImZpcnN0Q2hpbGQiLCJDcmVhdGVUT0NMaXN0Iiwicm9vdF9vbCIsInF1ZXJ5U2VsZWN0b3IiLCJJbnN0YWxsVE9DRXZlbnRIYW5kbGVycyIsInRoYXQiLCJsYXN0X2tub3duX3Njcm9sbF9wb3MiLCJoZWFkZXJfbnVtIiwiR2V0Q3VycmVudEFjdGl2ZVRPQ0l0ZW0iLCJIaWdobGlnaHRBY3RpdmVJdGVtIiwiaXRlbV9udW0iLCJJbnN0YWxsTGlua0NsaWNrSGFuZGxlciIsIm9uY2xpY2siLCJzY3JvbGxUbyIsImNvbnNvbGUiLCJsb2ciLCJzY3JvbGxfcG9zIiwibGluayIsInRleHRDb250ZW50IiwiTWFpbiIsInRvYyIsIm9ubG9hZCJdLCJtYXBwaW5ncyI6ImFBQ0EsSUFBQUEsRUFBQSxHQUdBLFNBQUFDLEVBQUFDLEdBR0EsR0FBQUYsRUFBQUUsR0FDQSxPQUFBRixFQUFBRSxHQUFBQyxRQUdBLElBQUFDLEVBQUFKLEVBQUFFLEdBQUEsQ0FDQUcsRUFBQUgsRUFDQUksR0FBQSxFQUNBSCxRQUFBLElBVUEsT0FOQUksRUFBQUwsR0FBQU0sS0FBQUosRUFBQUQsUUFBQUMsSUFBQUQsUUFBQUYsR0FHQUcsRUFBQUUsR0FBQSxFQUdBRixFQUFBRCxRQUtBRixF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MEIsYUFBYTNELEdBQUd3RSxXQUNsQ3ZDLEtBQUswQixhQUFhM0QsRUFBSSxHQUFHd0UsV0FBYStCLEVBQ2pDdkcsRUFFQUEsRUFBSSxFQUlqQixPQUFPQSxHQU1YMEQsRUFoSUEsR0FrSUEsU0FBUzRCLEVBQXlCdEIsR0FDaEMsSUFBSXFCLEVBQVV2QixTQUFTb0IsY0FBYyxNQUNyQ0csRUFBUUYsVUFBWSxnQkFFcEIsSUFBSXFCLEVBQU8xQyxTQUFTb0IsY0FBYyxRQUtsQyxPQUpBc0IsRUFBS3JCLFVBQVksZ0JBQ2pCcUIsRUFBS0MsWUFBY3pDLEVBQU9DLFlBRTFCb0IsRUFBUUQsWUFBWW9CLEdBQ2JuQixFQ2pKVCxTQUFTcUIsSURvSkYsSUFDREMsS0FBTSxJQUFJbEQsR0FDVitCLGdCQUdKbUIsRUFBSVQsMkJGM0dTLElBQUlsRSxHRzFDVm1CLHdCQUF3QixjQWFqQ2hCLE9BQU95RSxPQUFTLFdBQ2RGIiwiZmlsZSI6Im5ld19wYWdlLmJ1bmRsZS5qcyIsInNvdXJjZXNDb250ZW50IjpbIiBcdC8vIFRoZSBtb2R1bGUgY2FjaGVcbiBcdHZhciBpbnN0YWxsZWRNb2R1bGVzID0ge307XG5cbiBcdC8vIFRoZSByZXF1aXJlIGZ1bmN0aW9uXG4gXHRmdW5jdGlvbiBfX3dlYnBhY2tfcmVxdWlyZV9fKG1vZHVsZUlkKSB7XG5cbiBcdFx0Ly8gQ2hlY2sgaWYgbW9kdWxlIGlzIGluIGNhY2hlXG4gXHRcdGlmKGluc3RhbGxlZE1vZHVsZXNbbW9kdWxlSWRdKSB7XG4gXHRcdFx0cmV0dXJuIGluc3RhbGxlZE1vZHVsZXNbbW9kdWxlSWRdLmV4cG9ydHM7XG4gXHRcdH1cbiBcdFx0Ly8gQ3JlYXRlIGEgbmV3IG1vZHVsZSAoYW5kIHB1dCBpdCBpbnRvIHRoZSBjYWNoZSlcbiBcdFx0dmFyIG1vZHVsZSA9IGluc3RhbGxlZE1vZHVsZXNbbW9kdWxlSWRdID0ge1xuIFx0XHRcdGk6IG1vZHVsZUlkLFxuIFx0XHRcdGw6IGZhbHNlLFxuIFx0XHRcdGV4cG9ydHM6IHt9XG4gXHRcdH07XG5cbiBcdFx0Ly8gRXhlY3V0ZSB0aGUgbW9kdWxlIGZ1bmN0aW9uXG4gXHRcdG1vZHVsZXNbbW9kdWxlSWRdLmNhbGwobW9kdWxlLmV4cG9ydHMsIG1vZHVsZSwgbW9kdWxlLmV4cG9ydHMsIF9fd2VicGFja19yZXF1aXJlX18pO1xuXG4gXHRcdC8vIEZsYWcgdGhlIG1vZHVsZSBhcyBsb2FkZWRcbiBcdFx0bW9kdWxlLmwgPSB0cnVlO1xuXG4gXHRcdC8vIFJldHVybiB0aGUgZXhwb3J0cyBvZiB0aGUgbW9kdWxlXG4gXHRcdHJldHVybiBtb2R1bGUuZXhwb3J0cztcbiBcdH1cblxuXG4gXHQvLyBleHBvc2UgdGhlIG1vZHVsZXMgb2JqZWN0IChfX3dlYnBhY2tfbW9kdWxlc19fKVxuIFx0X193ZWJwYWNrX3JlcXVpcmVfXy5tID0gbW9kdWxlcztcblxuIFx0Ly8gZXhwb3NlIHRoZSBtb2R1bGUgY2FjaGVcbiBcdF9fd2VicGFja19yZXF1aXJlX18uYyA9IGluc3RhbGxlZE1vZHVsZXM7XG5cbiBcdC8vIGRlZmluZSBnZXR0ZXIgZnVuY3Rpb24gZm9yIGhhcm1vbnkgZXhwb3J0c1xuIFx0X193ZWJwYWNrX3JlcXVpcmVfXy5kID0gZnVuY3Rpb24oZXhwb3J0cywgbmFtZSwgZ2V0dGVyKSB7XG4gXHRcdGlmKCFfX3dlYnBhY2tfcmVxdWlyZV9fLm8oZXhwb3J0cywgbmFtZSkpIHtcbiBcdFx0XHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgbmFtZSwgeyBlbnVtZXJhYmxlOiB0cnVlLCBnZXQ6IGdldHRlciB9KTtcbiBcdFx0fVxuIFx0fTtcblxuIFx0Ly8gZGVmaW5lIF9fZXNNb2R1bGUgb24gZXhwb3J0c1xuIFx0X193ZWJwYWNrX3JlcXVpcmVfXy5yID0gZnVuY3Rpb24oZXhwb3J0cykge1xuIFx0XHRpZih0eXBlb2YgU3ltYm9sICE9PSAndW5kZWZpbmVkJyAmJiBTeW1ib2wudG9TdHJpbmdUYWcpIHtcbiBcdFx0XHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgU3ltYm9sLnRvU3RyaW5nVGFnLCB7IHZhbHVlOiAnTW9kdWxlJyB9KTtcbiBcdFx0fVxuIFx0XHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgJ19fZXNNb2R1bGUnLCB7IHZhbHVlOiB0cnVlIH0pO1xuIFx0fTtcblxuIFx0Ly8gY3JlYXRlIGEgZmFrZSBuYW1lc3BhY2Ugb2JqZWN0XG4gXHQvLyBtb2RlICYgMTogdmFsdWUgaXMgYSBtb2R1bGUgaWQsIHJlcXVpcmUgaXRcbiBcdC8vIG1vZGUgJiAyOiBtZXJnZSBhbGwgcHJvcGVydGllcyBvZiB2YWx1ZSBpbnRvIHRoZSBuc1xuIFx0Ly8gbW9kZSAmIDQ6IHJldHVybiB2YWx1ZSB3aGVuIGFscmVhZHkgbnMgb2JqZWN0XG4gXHQvLyBtb2RlICYgOHwxOiBiZWhhdmUgbGlrZSByZXF1aXJlXG4gXHRfX3dlYnBhY2tfcmVxdWlyZV9fLnQgPSBmdW5jdGlvbih2YWx1ZSwgbW9kZSkge1xuIFx0XHRpZihtb2RlICYgMSkgdmFsdWUgPSBfX3dlYnBhY2tfcmVxdWlyZV9fKHZhbHVlKTtcbiBcdFx0aWYobW9kZSAmIDgpIHJldHVybiB2YWx1ZTtcbiBcdFx0aWYoKG1vZGUgJiA0KSAmJiB0eXBlb2YgdmFsdWUgPT09ICdvYmplY3QnICYmIHZhbHVlICYmIHZhbHVlLl9fZXNNb2R1bGUpIHJldHVybiB2YWx1ZTtcbiBcdFx0dmFyIG5zID0gT2JqZWN0LmNyZWF0ZShudWxsKTtcbiBcdFx0X193ZWJwYWNrX3JlcXVpcmVfXy5yKG5zKTtcbiBcdFx0T2JqZWN0LmRlZmluZVByb3BlcnR5KG5zLCAnZGVmYXVsdCcsIHsgZW51bWVyYWJsZTogdHJ1ZSwgdmFsdWU6IHZhbHVlIH0pO1xuIFx0XHRpZihtb2RlICYgMiAmJiB0eXBlb2YgdmFsdWUgIT0gJ3N0cmluZycpIGZvcih2YXIga2V5IGluIHZhbHVlKSBfX3dlYnBhY2tfcmVxdWlyZV9fLmQobnMsIGtleSwgZnVuY3Rpb24oa2V5KSB7IHJldHVybiB2YWx1ZVtrZXldOyB9LmJpbmQobnVsbCwga2V5KSk7XG4gXHRcdHJldHVybiBucztcbiBcdH07XG5cbiBcdC8vIGdldERlZmF1bHRFeHBvcnQgZnVuY3Rpb24gZm9yIGNvbXBhdGliaWxpdHkgd2l0aCBub24taGFybW9ueSBtb2R1bGVzXG4gXHRfX3dlYnBhY2tfcmVxdWlyZV9fLm4gPSBmdW5jdGlvbihtb2R1bGUpIHtcbiBcdFx0dmFyIGdldHRlciA9IG1vZHVsZSAmJiBtb2R1bGUuX19lc01vZHVsZSA/XG4gXHRcdFx0ZnVuY3Rpb24gZ2V0RGVmYXVsdCgpIHsgcmV0dXJuIG1vZHVsZVsnZGVmYXVsdCddOyB9IDpcbiBcdFx0XHRmdW5jdGlvbiBnZXRNb2R1bGVFeHBvcnRzKCkgeyByZXR1cm4gbW9kdWxlOyB9O1xuIFx0XHRfX3dlYnBhY2tfcmVxdWlyZV9fLmQoZ2V0dGVyLCAnYScsIGdldHRlcik7XG4gXHRcdHJldHVybiBnZXR0ZXI7XG4gXHR9O1xuXG4gXHQvLyBPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGxcbiBcdF9fd2VicGFja19yZXF1aXJlX18ubyA9IGZ1bmN0aW9uKG9iamVjdCwgcHJvcGVydHkpIHsgcmV0dXJuIE9iamVjdC5wcm90b3R5cGUuaGFzT3duUHJvcGVydHkuY2FsbChvYmplY3QsIHByb3BlcnR5KTsgfTtcblxuIFx0Ly8gX193ZWJwYWNrX3B1YmxpY19wYXRoX19cbiBcdF9fd2VicGFja19yZXF1aXJlX18ucCA9IFwiXCI7XG5cblxuIFx0Ly8gTG9hZCBlbnRyeSBtb2R1bGUgYW5kIHJldHVybiBleHBvcnRzXG4gXHRyZXR1cm4gX193ZWJwYWNrX3JlcXVpcmVfXyhfX3dlYnBhY2tfcmVxdWlyZV9fLnMgPSAwKTtcbiIsImNsYXNzIFNjcm9sbCB7XG4gIHB1YmxpYyBjb25zdHJ1Y3RvcigpIHtcbiAgICB0aGlzLmxhc3RfcG9zaXRpb24gPSB3aW5kb3cuc2Nyb2xsWTtcbiAgICB0aGlzLnRpbWVfdG9fdXBkYXRlX3RvYyA9IHRydWU7XG5cbiAgICB0aGlzLnNjcm9sbF9kb3duX2V2ZW50X2hhbmRsZXJzID0gW107XG4gICAgdGhpcy5zY3JvbGxfdXBfZXZlbnRfaGFuZGxlcnMgPSBbXTtcblxuICAgIHRoaXMuSW5zdGFsbFNjcm9sbEV2ZW50SGFuZGxlcigpO1xuICB9XG5cbiAgcHJpdmF0ZSBJbnN0YWxsU2Nyb2xsRXZlbnRIYW5kbGVyKCkge1xuICAgIHdpbmRvdy5hZGRFdmVudExpc3RlbmVyKCdzY3JvbGwnLCAoZSkgPT4ge1xuICAgICAgaWYgKHRoaXMudGltZV90b191cGRhdGVfdG9jKSB7XG4gICAgICAgIHdpbmRvdy5yZXF1ZXN0QW5pbWF0aW9uRnJhbWUoKCkgPT4ge1xuICAgICAgICAgIHRoaXMudGltZV90b191cGRhdGVfdG9jID0gdHJ1ZTtcbiAgICAgICAgICBpZiAodGhpcy5sYXN0X3Bvc2l0aW9uID4gd2luZG93LnNjcm9sbFkpIHtcbiAgICAgICAgICAgIGZvciAobGV0IGZ1bmMgb2YgdGhpcy5zY3JvbGxfdXBfZXZlbnRfaGFuZGxlcnMpIHtcbiAgICAgICAgICAgICAgZnVuYygpO1xuICAgICAgICAgICAgfVxuICAgICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICBmb3IgKGxldCBmdW5jIG9mIHRoaXMuc2Nyb2xsX2Rvd25fZXZlbnRfaGFuZGxlcnMpIHtcbiAgICAgICAgICAgICAgZnVuYygpO1xuICAgICAgICAgICAgfVxuICAgICAgICAgIH1cbiAgICAgICAgICB0aGlzLmxhc3RfcG9zaXRpb24gPSB3aW5kb3cuc2Nyb2xsWTtcbiAgICAgICAgfSk7XG4gICAgICAgIHRoaXMudGltZV90b191cGRhdGVfdG9jID0gZmFsc2U7XG4gICAgICB9XG4gICAgfSk7XG4gIH1cblxuICBwdWJsaWMgUmVnaXN0ZXJTY3JvbGxVcEhhbmRsZXIoZnVuYzogKCk9PnZvaWQpIHtcbiAgICB0aGlzLnNjcm9sbF91cF9ldmVudF9oYW5kbGVycy5wdXNoKGZ1bmMpOyAgICAgIFxuICB9XG5cbiAgcHVibGljIFJlZ2lzdGVyU2Nyb2xsRG93bkhhbmRsZXIoZnVuYzogKCk9PnZvaWQpIHtcbiAgICB0aGlzLnNjcm9sbF9kb3duX2V2ZW50X2hhbmRsZXJzLnB1c2goZnVuYyk7ICAgICAgXG4gIH1cblxuICBwcml2YXRlIGxhc3RfcG9zaXRpb246IG51bWJlcjtcblxuICAvLyBNYWtlIHN1cmUgbm90IHRvIGhhbmRsZSBzY3JvbGwgZXZlbnQgdG9vIG9mdGVuLlxuICBwcml2YXRlIHRpbWVfdG9fdXBkYXRlX3RvYzogYm9vbGVhbjtcblxuICBwcml2YXRlIHNjcm9sbF9kb3duX2V2ZW50X2hhbmRsZXJzOiAoKCk9PiB2b2lkKVtdO1xuICBwcml2YXRlIHNjcm9sbF91cF9ldmVudF9oYW5kbGVyczogKCgpPT4gdm9pZClbXTtcbn1cblxuZXhwb3J0IGZ1bmN0aW9uIENyZWF0ZVNjcm9sbEhhbmRsZXIoKSA6IFNjcm9sbCB7XG4gIGxldCBzY3JvbGwgPSBuZXcgU2Nyb2xsKCk7XG4gIHJldHVybiBzY3JvbGw7XG59IiwiZXhwb3J0IGZ1bmN0aW9uIFN0cmlwUHJlZml4TmJzcChzdHI6IHN0cmluZyk6IHN0cmluZyB7XG4gIGxldCBpID0gMDtcbiAgZm9yICg7IGkgPCBzdHIubGVuZ3RoOyBpICsrKSB7XG4gICAgaWYgKHN0cltpXSA9PSAnwqAnKSB7IC8vIFRoaXMgaXMgbm90IHNwYWNlLiBUaGlzIGlzIHVuaWNvZGUgTkJTUCAoVSswMEEwKVxuICAgICAgY29udGludWU7XG4gICAgfSBlbHNlIHtcbiAgICAgIGJyZWFrO1xuICAgIH1cbiAgfVxuICByZXR1cm4gc3RyLnN1YnN0cmluZyhpKTtcbn1cblxuZXhwb3J0IGZ1bmN0aW9uIEdldEhlYWRlck51bShzdHI6IHN0cmluZyk6IG51bWJlciB7XG4gIGlmICghKHN0clswXSA9PSAnaCcgfHwgc3RyWzBdID09ICdIJykpIHtcbiAgICByZXR1cm4gLTE7XG4gIH1cblxuICByZXR1cm4gcGFyc2VJbnQoc3RyLnN1YnN0cmluZygxKSk7XG59IiwiaW1wb3J0ICogYXMgVXRpbCBmcm9tICcuL3V0aWwnO1xuXG5pbnRlcmZhY2UgVE9DSGVhZGVyIHtcbiAgaGVhZGVyX25hbWU6IHN0cmluZztcbiAgaGVhZGVyX3RhZzogbnVtYmVyO1xuICBoZWFkZXJfaWQ6IHN0cmluZztcbiAgaGVhZGVyX3BvczogbnVtYmVyO1xuICBoZWFkZXJfZWxlbV9saW5rOiBIVE1MQW5jaG9yRWxlbWVudDtcbn1cblxuY2xhc3MgVE9DIHtcbiAgY29uc3RydWN0b3IoKSB7XG4gICAgdGhpcy50b2NfaGVhZGVyc18gPSBbXTtcbiAgICB0aGlzLnRpbWVfdG9fdXBkYXRlX3RvYyA9IHRydWU7XG4gICAgdGhpcy5wcmV2X2hpZ2hsaWdodGVkID0gMDtcblxuICAgIC8vIEZldGNoIFRPQyBIZWFkZXJzLlxuICAgIHRoaXMuRmV0Y2hIZWFkZXJzKCk7XG4gIH1cblxuICBwcml2YXRlIEZldGNoSGVhZGVycygpIHtcbiAgICAvLyBGaXJzdCBpZGVudGlmeSBhbGwgdGhlIGhlYWRlcnMuXG4gICAgbGV0IGhlYWRlcnM6IE5vZGVMaXN0T2Y8RWxlbWVudD4gPVxuICAgICAgICBkb2N1bWVudC5xdWVyeVNlbGVjdG9yQWxsKCcuaGVhZGVyLWdlbmVyYWwnKTtcblxuICAgIGZvciAobGV0IGhlYWRlciBvZiBoZWFkZXJzIGFzIGFueSkge1xuICAgICAgbGV0IGhlYWRlcl9uYW1lOiBzdHJpbmcgPSBVdGlsLlN0cmlwUHJlZml4TmJzcChoZWFkZXIuaW5uZXJUZXh0KTtcbiAgICAgIGxldCBoZWFkZXJfdGFnOiBudW1iZXIgPSBVdGlsLkdldEhlYWRlck51bShoZWFkZXIudGFnTmFtZSk7XG4gICAgICBsZXQgaGVhZGVyX2lkOiBzdHJpbmcgPSBoZWFkZXIuaWQ7XG4gICAgICBsZXQgaGVhZGVyX3BvczogbnVtYmVyID1cbiAgICAgICAgICBoZWFkZXIuZ2V0Qm91bmRpbmdDbGllbnRSZWN0KCkudG9wICsgd2luZG93LnNjcm9sbFk7XG4gICAgICB0aGlzLnRvY19oZWFkZXJzXy5wdXNoKHtcbiAgICAgICAgaGVhZGVyX25hbWUsXG4gICAgICAgIGhlYWRlcl90YWcsXG4gICAgICAgIGhlYWRlcl9pZCxcbiAgICAgICAgaGVhZGVyX3BvcyxcbiAgICAgICAgaGVhZGVyX2VsZW1fbGluazogbnVsbFxuICAgICAgfSk7XG4gICAgfVxuICB9XG5cbiAgcHJpdmF0ZSBSZWN1cnNpdmVUT0NDcmVhdG9yKFxuICAgICAgcGFyZW50X29sOiBIVE1MT0xpc3RFbGVtZW50LCBjdXJyZW50X2hlYWRlcl9udW06IG51bWJlcixcbiAgICAgIHRhZ19udW1iZXI6IG51bWJlcikge1xuICAgIGxldCBjdXJyZW50X2xpID0gbnVsbDtcbiAgICBsZXQgaSA9IGN1cnJlbnRfaGVhZGVyX251bTtcbiAgICBmb3IgKDsgaSA8IHRoaXMudG9jX2hlYWRlcnNfLmxlbmd0aDsgaSsrKSB7XG4gICAgICBsZXQgaGVhZGVyID0gdGhpcy50b2NfaGVhZGVyc19baV07XG5cbiAgICAgIC8vIGgzIC0+IGgyXG4gICAgICBpZiAoaGVhZGVyLmhlYWRlcl90YWcgPCB0YWdfbnVtYmVyKSB7XG4gICAgICAgIHJldHVybiBpO1xuICAgICAgfVxuICAgICAgLy8gaDIgLT4gaDNcbiAgICAgIGVsc2UgaWYgKGhlYWRlci5oZWFkZXJfdGFnID4gdGFnX251bWJlcikge1xuICAgICAgICBsZXQgY2hpbGRfcGFyZW50X29sID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudCgnb2wnKSBhcyBIVE1MT0xpc3RFbGVtZW50O1xuICAgICAgICBjaGlsZF9wYXJlbnRfb2wuY2xhc3NOYW1lID0gJ3RvYy1saXN0JztcbiAgICAgICAgY3VycmVudF9saS5hcHBlbmRDaGlsZChjaGlsZF9wYXJlbnRfb2wpO1xuICAgICAgICBpID0gdGhpcy5SZWN1cnNpdmVUT0NDcmVhdG9yKGNoaWxkX3BhcmVudF9vbCwgaSwgaGVhZGVyLmhlYWRlcl90YWcpO1xuICAgICAgICBpLS07XG4gICAgICB9IGVsc2Uge1xuICAgICAgICBsZXQgZWxlbWVudCA9IEJ1aWxkQ2F0ZWdvcnlMaXN0RWxlbWVudChoZWFkZXIpO1xuICAgICAgICBoZWFkZXIuaGVhZGVyX2VsZW1fbGluayA9IGVsZW1lbnQuZmlyc3RDaGlsZCBhcyBIVE1MQW5jaG9yRWxlbWVudDtcbiAgICAgICAgcGFyZW50X29sLmFwcGVuZENoaWxkKGVsZW1lbnQpO1xuICAgICAgICBjdXJyZW50X2xpID0gZWxlbWVudDtcbiAgICAgIH1cbiAgICB9XG4gICAgcmV0dXJuIGk7XG4gIH1cblxuICBwdWJsaWMgQ3JlYXRlVE9DTGlzdCgpIHtcbiAgICBsZXQgcm9vdF9vbCA9IGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoJy50b2MtbGlzdCcpIGFzIEhUTUxPTGlzdEVsZW1lbnQ7XG4gICAgaWYgKHJvb3Rfb2wgPT0gbnVsbCkge1xuICAgICAgcmV0dXJuO1xuICAgIH1cbiAgICB0aGlzLlJlY3Vyc2l2ZVRPQ0NyZWF0b3Iocm9vdF9vbCwgMCwgdGhpcy50b2NfaGVhZGVyc19bMF0uaGVhZGVyX3RhZyk7XG5cbiAgICB0aGlzLkluc3RhbGxUT0NFdmVudEhhbmRsZXJzKCk7XG4gIH1cblxuICBwcml2YXRlIEluc3RhbGxUT0NFdmVudEhhbmRsZXJzKCkge1xuICAgIGxldCB0aGF0ID0gdGhpcztcbiAgICB3aW5kb3cuYWRkRXZlbnRMaXN0ZW5lcignc2Nyb2xsJywgZnVuY3Rpb24oZSkge1xuICAgICAgbGV0IGxhc3Rfa25vd25fc2Nyb2xsX3BvcyA9IHdpbmRvdy5zY3JvbGxZO1xuICAgICAgaWYgKHRoYXQudGltZV90b191cGRhdGVfdG9jKSB7XG4gICAgICAgIHdpbmRvdy5yZXF1ZXN0QW5pbWF0aW9uRnJhbWUoZnVuY3Rpb24oKSB7XG4gICAgICAgICAgdGhhdC50aW1lX3RvX3VwZGF0ZV90b2MgPSB0cnVlO1xuICAgICAgICAgIGxldCBoZWFkZXJfbnVtID0gdGhhdC5HZXRDdXJyZW50QWN0aXZlVE9DSXRlbShsYXN0X2tub3duX3Njcm9sbF9wb3MpO1xuICAgICAgICAgIHRoYXQuSGlnaGxpZ2h0QWN0aXZlSXRlbShoZWFkZXJfbnVtKTtcbiAgICAgICAgfSk7XG4gICAgICAgIHRoYXQudGltZV90b191cGRhdGVfdG9jID0gZmFsc2U7XG4gICAgICB9XG4gICAgfSlcbiAgfVxuXG4gIHByaXZhdGUgSGlnaGxpZ2h0QWN0aXZlSXRlbShpdGVtX251bTogbnVtYmVyKSB7XG4gICAgdGhpcy50b2NfaGVhZGVyc19bdGhpcy5wcmV2X2hpZ2hsaWdodGVkXS5oZWFkZXJfZWxlbV9saW5rLmNsYXNzTmFtZSA9XG4gICAgICAgICd0b2MtaXRlbS1saW5rJztcbiAgICB0aGlzLnRvY19oZWFkZXJzX1tpdGVtX251bV0uaGVhZGVyX2VsZW1fbGluay5jbGFzc05hbWUgPVxuICAgICAgICAndG9jLWl0ZW0tbGluayB0b2MtYWN0aXZlLWl0ZW0nO1xuICAgIHRoaXMucHJldl9oaWdobGlnaHRlZCA9IGl0ZW1fbnVtO1xuICB9XG5cbiAgcHVibGljIEluc3RhbGxMaW5rQ2xpY2tIYW5kbGVyKCkge1xuICAgIGZvciAobGV0IGhlYWRlciBvZiB0aGlzLnRvY19oZWFkZXJzXykge1xuICAgICAgaGVhZGVyLmhlYWRlcl9lbGVtX2xpbmsub25jbGljayA9IChlOiBNb3VzZUV2ZW50KSA9PiB7XG4gICAgICAgIHdpbmRvdy5zY3JvbGxUbygwLCBoZWFkZXIuaGVhZGVyX3BvcyAtIDE1MCk7XG4gICAgICAgIGNvbnNvbGUubG9nKGhlYWRlci5oZWFkZXJfcG9zIC0gMTUwKTtcbiAgICAgIH07XG4gICAgfVxuICB9XG5cbiAgcHJpdmF0ZSBHZXRDdXJyZW50QWN0aXZlVE9DSXRlbShzY3JvbGxfcG9zOiBudW1iZXIpIHtcbiAgICBpZiAoc2Nyb2xsX3BvcyA8IHRoaXMudG9jX2hlYWRlcnNfWzBdLmhlYWRlcl9wb3MpIHtcbiAgICAgIHJldHVybiAwO1xuICAgIH1cblxuICAgIGxldCBpID0gMDtcbiAgICBmb3IgKDsgaSA8IHRoaXMudG9jX2hlYWRlcnNfLmxlbmd0aDsgaSsrKSB7XG4gICAgICBpZiAoaSA9PSB0aGlzLnRvY19oZWFkZXJzXy5sZW5ndGggLSAxKSB7XG4gICAgICAgIGJyZWFrO1xuICAgICAgfSBlbHNlIGlmIChcbiAgICAgICAgICB0aGlzLnRvY19oZWFkZXJzX1tpXS5oZWFkZXJfcG9zIDw9IHNjcm9sbF9wb3MgJiZcbiAgICAgICAgICBzY3JvbGxfcG9zIDwgdGhpcy50b2NfaGVhZGVyc19baSArIDFdLmhlYWRlcl9wb3MpIHtcbiAgICAgICAgaWYgKHNjcm9sbF9wb3MgLSB0aGlzLnRvY19oZWFkZXJzX1tpXS5oZWFkZXJfcG9zIDxcbiAgICAgICAgICAgIHRoaXMudG9jX2hlYWRlcnNfW2kgKyAxXS5oZWFkZXJfcG9zIC0gc2Nyb2xsX3Bvcykge1xuICAgICAgICAgIHJldHVybiBpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgIHJldHVybiBpICsgMTtcbiAgICAgICAgfVxuICAgICAgfVxuICAgIH1cbiAgICByZXR1cm4gaTtcbiAgfVxuXG4gIHByaXZhdGUgdG9jX2hlYWRlcnNfOiBUT0NIZWFkZXJbXTtcbiAgcHJpdmF0ZSB0aW1lX3RvX3VwZGF0ZV90b2M6IGJvb2xlYW47XG4gIHByaXZhdGUgcHJldl9oaWdobGlnaHRlZDogbnVtYmVyO1xufVxuXG5mdW5jdGlvbiBCdWlsZENhdGVnb3J5TGlzdEVsZW1lbnQoaGVhZGVyOiBUT0NIZWFkZXIpOiBIVE1MTElFbGVtZW50IHtcbiAgbGV0IGVsZW1lbnQgPSBkb2N1bWVudC5jcmVhdGVFbGVtZW50KCdsaScpIGFzIEhUTUxMSUVsZW1lbnQ7XG4gIGVsZW1lbnQuY2xhc3NOYW1lID0gJ3RvYy1saXN0LWl0ZW0nO1xuXG4gIGxldCBsaW5rID0gZG9jdW1lbnQuY3JlYXRlRWxlbWVudCgnc3BhbicpIGFzIEhUTUxTcGFuRWxlbWVudDtcbiAgbGluay5jbGFzc05hbWUgPSAndG9jLWl0ZW0tbGluaydcbiAgbGluay50ZXh0Q29udGVudCA9IGhlYWRlci5oZWFkZXJfbmFtZTtcblxuICBlbGVtZW50LmFwcGVuZENoaWxkKGxpbmspO1xuICByZXR1cm4gZWxlbWVudDtcbn1cblxuZXhwb3J0IGZ1bmN0aW9uIEJ1aWxkVGFibGVPZkNvbnRlbnRzKCk6IFRPQyB7XG4gIGxldCB0b2MgPSBuZXcgVE9DKCk7XG4gIHRvYy5DcmVhdGVUT0NMaXN0KCk7XG5cbiAgLy8gSW5zdGFsbCBjbGljayBoYW5kbGVycy5cbiAgdG9jLkluc3RhbGxMaW5rQ2xpY2tIYW5kbGVyKCk7XG4gIHJldHVybiB0b2M7XG59IiwiaW1wb3J0ICogYXMgU2Nyb2xsIGZyb20gJy4vc2Nyb2xsJztcbmltcG9ydCAqIGFzIFRPQyBmcm9tICcuL3RvYyc7XG5cbi8vIE1haW4gZW50cnkgcG9pbnQuXG5mdW5jdGlvbiBNYWluKCkge1xuICBUT0MuQnVpbGRUYWJsZU9mQ29udGVudHMoKTtcblxuICBsZXQgc2Nyb2xsID0gU2Nyb2xsLkNyZWF0ZVNjcm9sbEhhbmRsZXIoKTtcbiAgc2Nyb2xsLlJlZ2lzdGVyU2Nyb2xsVXBIYW5kbGVyKCgpID0+IHtcbiAgICAvKlxuICAgIGNvbnNvbGUubG9nKGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoXCI6dGFyZ2V0XCIpKTtcbiAgICBsZXQgcGFkZGVkX2hlYWRlciA9IGRvY3VtZW50LnF1ZXJ5U2VsZWN0b3IoXCI6dGFyZ2V0XCIpIGFzIEhUTUxBbmNob3JFbGVtZW50O1xuICAgIGlmIChwYWRkZWRfaGVhZGVyLnN0eWxlLnBhZGRpbmdUb3AgIT0gXCIwXCIpIHtcbiAgICAgIHBhZGRlZF9oZWFkZXIuc3R5bGUucGFkZGluZ1RvcCA9IFwiMFwiO1xuICAgIH1cblxuICAgIC8vIFJlbW92ZSAjIGZyb20gdXJsLlxuICAgIGhpc3RvcnkucmVwbGFjZVN0YXRlKG51bGwsIG51bGwsICcgJyk7Ki9cbiAgfSlcbn1cblxud2luZG93Lm9ubG9hZCA9ICgpID0+IHtcbiAgTWFpbigpO1xufSJdLCJzb3VyY2VSb290IjoiIn0=