#include <iostream>
#include <string>
#include <vector>
#include <cctype> // std::isspace
#include "ray_string.h"

// p131 ch5.6: Taking string apart.


using std::cout; using std::endl; using std::cin;
using std::string; 
using std::vector;
using std::isspace;



int main(int argc, char** argv)
{
  string s;
  // read and split each line of input
  while(getline(cin,s))
  {
    vector<string> v = split(s);

    // write each word in v
    for(vector<string>::size_type i=0; i!=v.size();++i)
    {
      cout << v[i] << endl;
    }
  }

  cout << "Hello" << endl;
  return 0;
}


