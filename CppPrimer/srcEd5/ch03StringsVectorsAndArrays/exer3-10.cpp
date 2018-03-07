#include<iostream>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  // Write a program that reads a string of characters including
  // punctuation and writes what was read but with the punctuation removed.
  
  // string to store line
  cout << "Enter a string of characters including punctuation" << endl;
  string line;
  while(getline(cin,line))
  {
    for(auto c : line)
    {
      if(!ispunct(c)) cout << c;
    }
    cout << endl;
  }

  return 0;
}
