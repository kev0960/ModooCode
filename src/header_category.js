module.exports = class HeaderCategory {
  constructor(root_page) {
    this.root_page = root_page;
  }

  GetHeaderCategoryName(name) {
    if (name == 'C') {
      return 'C 언어 강좌'
    } else if (name == 'C++') {
      return 'C++ 강좌'
    } else if (name == 'C Reference') {
      return 'C 레퍼런스'
    } else if (name == 'C++ Reference') {
      return 'C++ 레퍼런스'
    }
    return name;
  }

  GetCategoryLink(category) {
    let name = category.name;
    if (name == 'C') {
      return '/new-page/231'
    } else if (name == 'C++') {
      return '/new-page/135'
    } else if (name == '알고리즘') {
      return '/new-page/235';
    }
    return '/';
  }

  BuildPageHeader() {
    let html = '<ul class="header-category-list">\n';
    for (let i = 0; i < this.root_page.directories.length; i++) {
      let current_category = this.root_page.directories[i];

      if (current_category.files.size > 0) {
        html +=
            '<li class="category-item"><a class="category-item-link" href="' +
            this.GetCategoryLink(current_category) + '">' +
            this.GetHeaderCategoryName(current_category.name) + '</a>';
      } else {
        html += '<li class="category-item">' +
            this.GetHeaderCategoryName(current_category.name);
      }

      if (current_category.directories.length > 0 &&
          current_category.files.size == 0) {
        html += '<ul class="header-category-dropdown">';
        for (let j = 0; j < current_category.directories.length; j++) {
          html += '<li class="header-category-dropdown-item">' +
              current_category.directories[j].name + '</li>';
        }
        html += '</ul>';
      }
      html += '</li>\n';
    }
    html += '</ul>';

    return html;
  }
};