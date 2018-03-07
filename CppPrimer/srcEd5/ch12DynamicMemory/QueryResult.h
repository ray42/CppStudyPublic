#ifndef QUERY_RESULT_HEADER
#define QUERY_RESULT_HEADER

#include<string>
#include<map>
#include<set>
#include<vector>
#include<memory>

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
  using line_no = std::vector<std::string>::size_type;
  QueryResult(std::string s,
              std::shared_ptr<std::set<line_no>> p,
              std::shared_ptr<std::vector<std::string>> f):
    sought(s), lines_spt(p), file_spt(f) {}

  void testfun();
  
  auto begin() -> std::set<line_no>::iterator
  {
    return lines_spt->begin();
  }

  auto end() -> std::set<line_no>::iterator
  {
    return lines_spt->end();
  }

  auto get_file() -> std::shared_ptr<std::vector<std::string>>
  {
    return file_spt;
  }

private:
  std::string sought; // word this query represents
  std::shared_ptr<std::set<line_no>> lines_spt; // lines it's on
  std::shared_ptr<std::vector<std::string>> file_spt; // input file
};
#endif
