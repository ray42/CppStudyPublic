#include<iostream>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  string str("Hello World!");
  
  // while
  decltype(str.size()) i = 0;
  while(i < str.size())
  {
    str[i++]='X';
  }

  cout << str << endl;
  
  // reset str
  str="Hello World!";

  // traditional for
  for(decltype(str.size()) i = 0; i < str.size(); ++i)
  {
    str[i]='X';
  }
  cout << str << endl;
  
  return 0;
}
