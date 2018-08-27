#include "json.h"
#include "util.h"

namespace md_parser {
Json::Json(const string& filename) : filename_(filename) { out.open(filename); }

string Json::JsonSerialize(const std::map<string, string>& m) {
  string json;
  json += "{\n";
  size_t cnt = 0;
  for (const auto& kv : m) {
    const string& key = kv.first;
    const string& val = kv.second;
    json += StrCat("\t", "\"", key, "\" : \"", val, "\"",
                   cnt < m.size() - 1 ? "," : "", "\n");
    cnt++;
  }
  json += "}\n";
  return json;
}

string Json::JsonSerialize(
    const std::map<string, std::map<string, string>>& m) {
  string json;
  json += "{\n";
  size_t cnt = 0;
  for (const auto& kv : m) {
    const string& key = kv.first;
    const auto& val = kv.second;
    string val_json = JsonSerialize(val);
    json += StrCat("\t", "\"", key, "\" : ", val_json,
                   cnt < m.size() - 1 ? "," : "", "\n");
    cnt++;
  }
  json += "}\n";
  return json;
}

void Json::DumpJson(const string& s) { out << s << std::endl; }
}
