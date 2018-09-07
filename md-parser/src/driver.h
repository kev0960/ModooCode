#include "parser.h"

namespace md_parser {
struct DriverConfig {
  bool no_output_parsed;
  bool no_dump_file_info;
  bool no_dump_page_path;

  DriverConfig(bool no_output_parsed = false, bool no_dump_file_info = false,
               bool no_dump_page_path = false)
      : no_output_parsed(no_output_parsed),
        no_dump_file_info(no_dump_file_info),
        no_dump_page_path(no_dump_page_path) {}
};

class Driver {
 public:
  Driver(const DriverConfig& config) : config_(config){};
  bool ProcessFiles(const std::vector<string>& filenames);

 private:
  std::vector<std::unique_ptr<MDParser>> parsers_;
  const DriverConfig config_;
};
}  // namespace md_parser
