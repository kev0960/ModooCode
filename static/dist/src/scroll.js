var Scroll = /** @class */ (function () {
    function Scroll() {
        this.last_position = window.scrollY;
        this.time_to_update_toc = true;
        this.scroll_down_event_handlers = [];
        this.scroll_up_event_handlers = [];
        this.InstallScrollEventHandler();
    }
    Scroll.prototype.InstallScrollEventHandler = function () {
        var _this = this;
        window.addEventListener('scroll', function (e) {
            if (_this.time_to_update_toc) {
                window.requestAnimationFrame(function () {
                    _this.time_to_update_toc = true;
                    if (_this.last_position > window.scrollY) {
                        for (var _i = 0, _a = _this.scroll_up_event_handlers; _i < _a.length; _i++) {
                            var func = _a[_i];
                            func();
                        }
                    }
                    else {
                        for (var _b = 0, _c = _this.scroll_down_event_handlers; _b < _c.length; _b++) {
                            var func = _c[_b];
                            func();
                        }
                    }
                    _this.last_position = window.scrollY;
                });
                _this.time_to_update_toc = false;
            }
        });
    };
    Scroll.prototype.RegisterScrollUpHandler = function (func) {
        this.scroll_up_event_handlers.push(func);
    };
    Scroll.prototype.RegisterScrollDownHandler = function (func) {
        this.scroll_down_event_handlers.push(func);
    };
    return Scroll;
}());
export function CreateScrollHandler() {
    var scroll = new Scroll();
    return scroll;
}
//# sourceMappingURL=scroll.js.map