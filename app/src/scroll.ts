class Scroll {
  public constructor() {
    this.last_position = window.scrollY;
    this.time_to_update_toc = true;

    this.scroll_down_event_handlers = [];
    this.scroll_up_event_handlers = [];

    this.InstallScrollEventHandler();
  }

  private InstallScrollEventHandler() {
    window.addEventListener('scroll', (e) => {
      if (this.time_to_update_toc) {
        window.requestAnimationFrame(() => {
          this.time_to_update_toc = true;
          if (this.last_position > window.scrollY) {
            for (let func of this.scroll_up_event_handlers) {
              func();
            }
          } else {
            for (let func of this.scroll_down_event_handlers) {
              func();
            }
          }
          this.last_position = window.scrollY;
        });
        this.time_to_update_toc = false;
      }
    });
  }

  public RegisterScrollUpHandler(func: ()=>void) {
    this.scroll_up_event_handlers.push(func);
  }

  public RegisterScrollDownHandler(func: ()=>void) {
    this.scroll_down_event_handlers.push(func);
  }

  private last_position: number;

  // Make sure not to handle scroll event too often.
  private time_to_update_toc: boolean;

  private scroll_down_event_handlers: (()=> void)[];
  private scroll_up_event_handlers: (()=> void)[];
}

export function CreateScrollHandler() : Scroll {
  let scroll = new Scroll();
  return scroll;
}
