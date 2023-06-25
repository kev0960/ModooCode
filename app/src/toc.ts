import * as Util from './util';

interface TOCHeader {
  header_name: string;
  header_tag: number;
  header_id: string;
  header_pos: number;
  header_elem_link: HTMLAnchorElement;
}

class TOC {
  constructor() {
    this.toc_headers_ = [];
    this.time_to_update_toc = true;
    this.prev_highlighted = 0;

    // Fetch TOC Headers.
    this.FetchHeaders();
  }

  private FetchHeaders() {
    // First identify all the headers.
    let headers: NodeListOf<Element> =
        document.querySelectorAll('.header-general');

    for (let header of headers as any) {
      let header_name: string = Util.StripPrefixNbsp(header.innerText);
      let header_tag: number = Util.GetHeaderNum(header.tagName);
      let header_id: string = header.id;
      let header_pos: number =
          header.getBoundingClientRect().top + window.scrollY;
      this.toc_headers_.push({
        header_name,
        header_tag,
        header_id,
        header_pos,
        header_elem_link: null
      });
    }
  }

  private RecursiveTOCCreator(
      parent_ol: HTMLOListElement, current_header_num: number,
      tag_number: number) {
    let current_li = null;
    let i = current_header_num;
    for (; i < this.toc_headers_.length; i++) {
      let header = this.toc_headers_[i];

      // h3 -> h2
      if (header.header_tag < tag_number) {
        return i;
      }
      // h2 -> h3
      else if (header.header_tag > tag_number) {
        let child_parent_ol = document.createElement('ol') as HTMLOListElement;
        child_parent_ol.className = 'toc-list';
        current_li.appendChild(child_parent_ol);
        i = this.RecursiveTOCCreator(child_parent_ol, i, header.header_tag);
        i--;
      } else {
        let element = BuildCategoryListElement(header);
        header.header_elem_link = element.firstChild as HTMLAnchorElement;
        parent_ol.appendChild(element);
        current_li = element;
      }
    }
    return i;
  }

  public CreateTOCList() {
    let root_ol = document.querySelector('.toc-list') as HTMLOListElement;
    if (root_ol == null) {
      return;
    }
    this.RecursiveTOCCreator(root_ol, 0, this.toc_headers_[0].header_tag);

    this.InstallTOCEventHandlers();
  }

  private InstallTOCEventHandlers() {
    let that = this;
    window.addEventListener('scroll', function() {
      let last_known_scroll_pos = window.scrollY;
      if (that.time_to_update_toc) {
        window.requestAnimationFrame(function() {
          that.time_to_update_toc = true;
          let header_num = that.GetCurrentActiveTOCItem(last_known_scroll_pos);
          that.HighlightActiveItem(header_num);
        });
        that.time_to_update_toc = false;
      }
    })
  }

  private HighlightActiveItem(item_num: number) {
    this.toc_headers_[this.prev_highlighted].header_elem_link.className =
        'toc-item-link';
    this.toc_headers_[item_num].header_elem_link.className =
        'toc-item-link toc-active-item';
    this.prev_highlighted = item_num;
  }

  public InstallLinkClickHandler() {
    for (let header of this.toc_headers_) {
      header.header_elem_link.onclick = (e: MouseEvent) => {
        window.scrollTo(0, header.header_pos - 150);
        console.log(header.header_pos - 150);
      };
    }
  }

  private GetCurrentActiveTOCItem(scroll_pos: number) {
    if (scroll_pos < this.toc_headers_[0].header_pos) {
      return 0;
    }

    let i = 0;
    for (; i < this.toc_headers_.length; i++) {
      if (i == this.toc_headers_.length - 1) {
        break;
      } else if (
          this.toc_headers_[i].header_pos <= scroll_pos &&
          scroll_pos < this.toc_headers_[i + 1].header_pos) {
        if (scroll_pos - this.toc_headers_[i].header_pos >
                this.toc_headers_[i + 1].header_pos - scroll_pos &&
            Util.IsElementInViewPort(
                this.toc_headers_[i + 1].header_elem_link)) {
          return i + 1;
        } else {
          return i;
        }
      }
    }
    return i;
  }

  private toc_headers_: TOCHeader[];
  private time_to_update_toc: boolean;
  private prev_highlighted: number;
}

function BuildCategoryListElement(header: TOCHeader): HTMLLIElement {
  let element = document.createElement('li') as HTMLLIElement;
  element.className = 'toc-list-item';

  let link = document.createElement('span') as HTMLSpanElement;
  link.className = 'toc-item-link'
  link.textContent = header.header_name;

  element.appendChild(link);
  return element;
}

export function BuildTableOfContents(): TOC {
  let toc = new TOC();
  toc.CreateTOCList();

  // Install click handlers.
  toc.InstallLinkClickHandler();
  return toc;
}
