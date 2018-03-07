#include<iostream>
using std::cout; using std::endl;

#include<list>
using std::list;

#include<vector>
using std::vector;

#include<string>
using std::string;

//Exercise 9.14: Write a program to assign the elements from a list of
//char* pointers to C-style character strings to a vector of strings.
int main()
{
  // See my notes on why we need const, it's just above the exercise.
  list<const char*> lcp = {"Hello","World","Hi"};

  vector<string> vs;
  vs.assign(lcp.cbegin(),lcp.cend());

  for(const auto& s:vs)
  {
    cout << s << " " << endl;
  }

  return 0;
}
