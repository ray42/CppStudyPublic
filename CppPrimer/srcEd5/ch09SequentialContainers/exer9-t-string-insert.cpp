#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main()
{
  string s;
  const char *cp = "Stately, plump Buck";
  s.assign(cp, 7);            //  s == "Stately"
  s.insert(s.size(), cp + 7); //  s == "Stately, plump Buck"

  // where does it insert?
  s.insert(3,1,'X'); // s == "StaXtely, plump Buck"
  cout << s << endl;

//  string ss = "some string", ss2 = "some other string";
//  ss.insert(0, ss2); // insert a copy of s2 before position 0 in s
//  cout << "ss is: "<<ss << endl;
//  // insert s2.size() characters from s2 starting at s2[0] before s[0]
//  ss.insert(0, ss2, 0, ss2.size());


  return 0;
}


