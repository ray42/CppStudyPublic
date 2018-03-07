#include<iostream>
#include<vector>
#include<string>

#include<set>
using std::set;

#include<memory>
using std::shared_ptr;

#include<fstream>
using std::ifstream;

#include<ostream>
using std::ostream;

#include"TextQuery.h"
#include"QueryResult.h"
#include"./../common/cpp_primer_common.h"

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

ostream& print(ostream& os, const QueryResult &qr)
{
  // if the word was found, print the count and all occurrences
  os << qr.sought << " occurs " << qr.lines_spt->size() << " "
     << cppp::make_plural(qr.lines_spt->size(), "time", "s") << endl;
  // print each line in which the word appeared.
  for(auto num : *qr.lines_spt ) // for every element in the set
    // don't confound the user with text lines starting 0
    os << "\t(line " << num+1 << ")"
       << *(qr.file_spt->begin()+num) << endl;
  return os;
}


void runQueries(ifstream& infile)
{
  // infile is an ifstream that is the file we want to query
  TextQuery tq(infile); // store the file and build the query map
  // iterate with the user: prompt for a word to find and print results
  while(true)
  {
    cout << "enter word to look for, or q to quit: ";
    string s;
    
    // stop if we hit end-of-file on the input or if a 'q' is entered.
    if(!(cin >> s) || s =="q") break;
    
    // run he query and print the results
    print(cout, tq.query(s)) << endl;
  }
}


int main(int argc, char** argv)
{

//  int * arr = new int[10]();

  ifstream ifs("textquerytest.txt");
  runQueries(ifs);

//  TextQuery tqR(ifs);
//  tqR.testfun();
//  using line_no = std::vector<std::string>::size_type;
//  string s;
//  std::shared_ptr<std::set<line_no>> p;
//  std::shared_ptr<std::vector<std::string>> f;
//  QueryResult qrR(s,p,f);
//  qrR.testfun();
//  
//  TextQuery tq(ifs);
//  tq.testfun();
//
//  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
