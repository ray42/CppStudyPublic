#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

// Exercise 6.25: Write a main function that takes two arguments.
// Concatenate the supplied arguments and print the resulting string.
int main(int argc, char* argv[])
{
  string s;

  for(int i = 1; i!=argc; ++i)
  {
    s+= argv[i];
    s+=" ";
  }
  
  cout << s << endl;

  return 0;
}
