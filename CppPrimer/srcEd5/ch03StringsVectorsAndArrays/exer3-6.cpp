#include<iostream>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  // Use a range for to change all the characters in a string to X .
  string str("Hello World!");
  for(auto &c : str)
    c='X';
  cout << str << endl;
  return 0;
}
