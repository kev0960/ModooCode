#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <unordered_map>

#include "parser.h"

namespace md_parser {
struct DriverConfig {
  bool no_output_parsed;
  bool no_dump_file_info;
  bool no_dump_page_path;
  bool force_parse_all;
  bool create_book;

  DriverConfig(bool no_output_parsed = false, bool no_dump_file_info = false,
               bool no_dump_page_path = false, bool force_parse_all = false,
               bool create_book = false)
      : no_output_parsed(no_output_parsed),
        no_dump_file_info(no_dump_file_info),
        no_dump_page_path(no_dump_page_path),
        force_parse_all(force_parse_all),
        create_book(create_book) {}
};

class Driver {
 public:
  Driver(const DriverConfig& config);
  bool ProcessFiles(const std::vector<string>& filenames);

 private:
  std::vector<std::unique_ptr<MDParser>> parsers_;
  std::unordered_map<string, struct timespec> file_id_to_stat_map_;
  const DriverConfig config_;
};
}  // namespace md_parser
