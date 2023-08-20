import { CreateCommentManager } from "./comment";
import * as Scroll from "./scroll";
import * as TOC from "./toc";
import "./login";

// Main entry point.
async function Main() {
  TOC.BuildTableOfContents();

  let scroll = Scroll.CreateScrollHandler();
  scroll.RegisterScrollUpHandler(() => {
    /*
    console.log(document.querySelector(":target"));
    let padded_header = document.querySelector(":target") as HTMLAnchorElement;
    if (padded_header.style.paddingTop != "0") {
      padded_header.style.paddingTop = "0";
    }

    // Remove # from url.
    history.replaceState(null, null, ' ');*/
  });

  let comment_manager = CreateCommentManager();
  await comment_manager.LoadComments();

  comment_manager.ComputeRootComments();
  console.log("html ", comment_manager.CreateCommentList());

  if (
    comment_manager.GetNumTotalComments() >=
    comment_manager.GetLastCommentIndex()
  ) {
    console.log("not hidden");
    document.getElementById("button-box").hidden = false;
  }

  /*
  document.getElementById("comment-list-section").innerHTML = comment_manager
    .CreateCommentList()
    .map((e) => e.outerHTML)
    .join("");
    */
}

window.onload = () => {
  Main();
};
