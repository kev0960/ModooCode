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
  document
    .getElementById("root-comment-list")
    .replaceWith(comment_manager.CreateCommentList());

  if (
    comment_manager.GetNumTotalComments() >=
    comment_manager.GetLastCommentIndex()
  ) {
    document.getElementById("button-box").hidden = false;
  }

  document.getElementById("post-comment").onclick = () => {
    let content = (
      document.getElementById("posted-comment") as HTMLTextAreaElement
    ).value;

    let password = "";
    if (document.getElementById("password")) {
      password = (document.getElementById("password") as HTMLInputElement)
        .value;
    }

    let name = "";
    if (document.getElementById("name")) {
      name = (document.getElementById("name") as HTMLInputElement).value;
    }

    comment_manager.PostComment(content, password, name).then((res) => {
      console.log(res);
    });
  };
}

window.onload = () => {
  Main();
};
