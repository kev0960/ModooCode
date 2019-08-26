
class PagePath {
  constructor(files, name) {
    this.files = new Set();
    this.name = name;

    for (let i = 0; i < files.length; i++) {
      this.files.add(files[i]);
    }

    this.directories = []
  }

  addDirectory(directory) {
    this.directories.push(directory);
  }

  findPage(page) {
    if (this.files.has(page)) {
      return [page];
    }
    for (let i = 0; i < this.directories.length; i++) {
      let result = this.directories[i].findPage(page);
      if (result.length != 0) {
        return [this.directories[i].name].concat(result);
      }
    }
    return [];
  }
};

class PathHierarchy {
  constructor(path_json) {
    this.root_path = new PagePath([], '');
    this.recursiveAddPath(this.root_path, path_json['']);
    this.cached_search_result = new Map();
  }

  recursiveAddPath(current_page_path, path_json) {
    for (let dir_name in path_json) {
      if (dir_name == 'files') {
        continue;
      }
      let child_page_path = new PagePath(path_json[dir_name].files, dir_name);
      this.recursiveAddPath(child_page_path, path_json[dir_name]);
      current_page_path.addDirectory(child_page_path);
    }
  }

  searchPagePath(page_id) {
    if (typeof page_id !== 'string') {
      page_id = page_id.toString();
    }
    if (!this.cached_search_result.get(page_id)) {
      let result = this.root_path.findPage(page_id);
      this.cached_search_result.set(page_id, result);
      return result;
    }
    return this.cached_search_result.get(page_id);
  }
}

module.exports = {
  PathHierarchy
};