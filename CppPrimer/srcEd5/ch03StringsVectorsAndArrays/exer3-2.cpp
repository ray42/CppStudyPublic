#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;

int main(int argc, char** argv)
{
  // Exercise 3.2: Write a program to read the standard input a line at a 
  // time. Modify your program to read a word at a time.

  string str;
  if(argc>1)
  {
    while(getline(cin,str))
    {
      cout << "Line: " << str << endl;
    }
  }
  else
  {
    while(cin >> str)
    {
      cout << "Word: " << str << endl;
    }
  }

  return 0;
}
