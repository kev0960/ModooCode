module.exports = class HeaderCategory {
  constructor(root_page) {
    this.root_page = root_page;
  }

  GetHeaderCategoryName(name) {
    if (name == 'C') {
      return 'C 언어'
    } else if (name == 'C++') {
      return 'C++'
    } else if (name == 'C Reference') {
      return 'C 레퍼런스'
    } else if (name == 'C++ Reference') {
      return 'C++ 레퍼런스'
    }
    return name;
  }

  GetCategoryLink(category) {
    return '/category/' + category.name;
  }

  BuildPageHeader() {
    let html = '<ul class="header-category-list">\n';
    for (let i = 0; i < this.root_page.directories.length; i++) {
      let current_category = this.root_page.directories[i];

      html += '<li class="category-item"><a class="category-item-link" href="' +
          this.GetCategoryLink(current_category) + '">' +
          this.GetHeaderCategoryName(current_category.name) + '</a>';

      if (current_category.directories.length > 0 &&
          current_category.files.size == 0) {
        html += '<ul class="header-category-dropdown">';
        for (let j = 0; j < current_category.directories.length; j++) {
          html +=
              '<li class="header-category-dropdown-item"><a class="category-item-link" href="/category/' +
              current_category.name + '/' +
              current_category.directories[j].name + '">' +
              current_category.directories[j].name + '</a></li>';
        }
        html += '</ul>';
      }
      html += '</li>\n';
    }
    html += '</ul>';

    return html;
  }
};