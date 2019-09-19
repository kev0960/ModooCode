import * as Scroll from './scroll';
import * as TOC from './toc';

// Main entry point.
function Main() {
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
  })
}

window.onload = () => {
  Main();
}