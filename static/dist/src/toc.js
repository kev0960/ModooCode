import * as Util from "./util";
var TOC = /** @class */ (function () {
    function TOC() {
        this.toc_headers_ = [];
        this.time_to_update_toc = true;
        this.prev_highlighted = 0;
        // Fetch TOC Headers.
        this.FetchHeaders();
    }
    TOC.prototype.FetchHeaders = function () {
        // First identify all the headers.
        var headers = document.querySelectorAll(".header-general");
        for (var _i = 0, _a = headers; _i < _a.length; _i++) {
            var header = _a[_i];
            var header_name = Util.StripPrefixNbsp(header.innerText);
            var header_tag = Util.GetHeaderNum(header.tagName);
            var header_id = header.id;
            var header_pos = header.getBoundingClientRect().top + window.scrollY;
            this.toc_headers_.push({
                header_name: header_name,
                header_tag: header_tag,
                header_id: header_id,
                header_pos: header_pos,
                header_elem_link: null,
            });
        }
    };
    TOC.prototype.RecursiveTOCCreator = function (parent_ol, current_header_num, tag_number) {
        var current_li = null;
        var i = current_header_num;
        for (; i < this.toc_headers_.length; i++) {
            var header = this.toc_headers_[i];
            // h3 -> h2
            if (header.header_tag < tag_number) {
                return i;
            }
            // h2 -> h3
            else if (header.header_tag > tag_number) {
                var child_parent_ol = document.createElement("ol");
                child_parent_ol.className = "toc-list";
                current_li.appendChild(child_parent_ol);
                i = this.RecursiveTOCCreator(child_parent_ol, i, header.header_tag);
                i--;
            }
            else {
                var element = BuildCategoryListElement(header);
                header.header_elem_link = element.firstChild;
                parent_ol.appendChild(element);
                current_li = element;
            }
        }
        return i;
    };
    TOC.prototype.CreateTOCList = function () {
        var root_ol = document.querySelector(".toc-list");
        if (root_ol == null) {
            return;
        }
        if (this.toc_headers_.length != 0) {
            this.RecursiveTOCCreator(root_ol, 0, this.toc_headers_[0].header_tag);
        }
        this.InstallTOCEventHandlers();
    };
    TOC.prototype.InstallTOCEventHandlers = function () {
        var that = this;
        window.addEventListener("scroll", function () {
            var last_known_scroll_pos = window.scrollY;
            if (that.time_to_update_toc) {
                window.requestAnimationFrame(function () {
                    that.time_to_update_toc = true;
                    var header_num = that.GetCurrentActiveTOCItem(last_known_scroll_pos);
                    that.HighlightActiveItem(header_num);
                });
                that.time_to_update_toc = false;
            }
        });
    };
    TOC.prototype.HighlightActiveItem = function (item_num) {
        this.toc_headers_[this.prev_highlighted].header_elem_link.className =
            "toc-item-link";
        this.toc_headers_[item_num].header_elem_link.className =
            "toc-item-link toc-active-item";
        this.prev_highlighted = item_num;
    };
    TOC.prototype.InstallLinkClickHandler = function () {
        var _loop_1 = function (header) {
            header.header_elem_link.onclick = function (e) {
                window.scrollTo(0, header.header_pos - 150);
                console.log(header.header_pos - 150);
            };
        };
        for (var _i = 0, _a = this.toc_headers_; _i < _a.length; _i++) {
            var header = _a[_i];
            _loop_1(header);
        }
    };
    TOC.prototype.GetCurrentActiveTOCItem = function (scroll_pos) {
        if (scroll_pos < this.toc_headers_[0].header_pos) {
            return 0;
        }
        var i = 0;
        for (; i < this.toc_headers_.length; i++) {
            if (i == this.toc_headers_.length - 1) {
                break;
            }
            else if (this.toc_headers_[i].header_pos <= scroll_pos &&
                scroll_pos < this.toc_headers_[i + 1].header_pos) {
                if (scroll_pos - this.toc_headers_[i].header_pos >
                    this.toc_headers_[i + 1].header_pos - scroll_pos &&
                    Util.IsElementInViewPort(this.toc_headers_[i + 1].header_elem_link)) {
                    return i + 1;
                }
                else {
                    return i;
                }
            }
        }
        return i;
    };
    return TOC;
}());
function BuildCategoryListElement(header) {
    var element = document.createElement("li");
    element.className = "toc-list-item";
    var link = document.createElement("span");
    link.className = "toc-item-link";
    link.textContent = header.header_name;
    element.appendChild(link);
    return element;
}
export function BuildTableOfContents() {
    var toc = new TOC();
    toc.CreateTOCList();
    // Install click handlers.
    toc.InstallLinkClickHandler();
    return toc;
}
//# sourceMappingURL=toc.js.map