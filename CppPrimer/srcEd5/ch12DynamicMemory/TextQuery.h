#ifndef TEXT_QUERY_HEADER
#define TEXT_QUERY_HEADER

#include<vector>
#include<string>
#include<fstream>
#include<memory>
#include<set>
#include<map>

class QueryResult; // declaration needed for return type in query function

class TextQuery
{
public:
  using line_no = std::vector<std::string>::size_type;

  TextQuery(std::ifstream&);

  // in: word to query
  // out: Result of query
  QueryResult query(const std::string&) const;

  void testfun();


private:
  std::shared_ptr<std::vector<std::string>> file_spt; // input file

  // map of each word to the set of the lines in which that word appears
  std::map<std::string,
           std::shared_ptr<std::set<line_no>>> word_map;
};
#endif
