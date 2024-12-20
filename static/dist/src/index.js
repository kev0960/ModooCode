var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
import { CreateCommentManager } from "./comment";
import * as Scroll from "./scroll";
import * as TOC from "./toc";
import "./login";
// Main entry point.
function Main() {
    return __awaiter(this, void 0, void 0, function () {
        var scroll, comment_manager;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    TOC.BuildTableOfContents();
                    scroll = Scroll.CreateScrollHandler();
                    scroll.RegisterScrollUpHandler(function () {
                        /*
                        console.log(document.querySelector(":target"));
                        let padded_header = document.querySelector(":target") as HTMLAnchorElement;
                        if (padded_header.style.paddingTop != "0") {
                          padded_header.style.paddingTop = "0";
                        }
                    
                        // Remove # from url.
                        history.replaceState(null, null, ' ');*/
                    });
                    comment_manager = CreateCommentManager();
                    return [4 /*yield*/, comment_manager.LoadComments()];
                case 1:
                    _a.sent();
                    comment_manager.ComputeRootComments();
                    document
                        .getElementById("root-comment-list")
                        .replaceWith(comment_manager.CreateCommentList());
                    if (comment_manager.GetNumTotalComments() >=
                        comment_manager.GetLastCommentIndex()) {
                        document.getElementById("button-box").hidden = false;
                    }
                    document.getElementById("post-comment").onclick = function () {
                        var content = document.getElementById("posted-comment").value;
                        var password = "";
                        if (document.getElementById("password")) {
                            password = document.getElementById("password")
                                .value;
                        }
                        var name = "";
                        if (document.getElementById("name")) {
                            name = document.getElementById("name").value;
                        }
                        comment_manager.PostComment(content, password, name).then(function (res) {
                            console.log(res);
                        });
                    };
                    return [2 /*return*/];
            }
        });
    });
}
window.onload = function () {
    Main();
};
//# sourceMappingURL=index.js.map