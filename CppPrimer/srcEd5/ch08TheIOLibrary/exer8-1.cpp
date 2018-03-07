#include<iostream>
#include<string>

using std::cout; using std::endl; 
using std::cin; using std::istream;

using std::string;

//Exercise 8.1: Write a function that takes and returns an istream&. The
//function should read the stream until it hits end-of-file. The function
//should print what it reads to the standard output. Reset the stream so 
//that it is valid before returning the stream.

istream& foo(istream& is)
{
  string str;
  while(is >> str)
  {
    cout << str << endl;
  }

  is.clear();
  return is;
}

//Exercise 8.2: Test your function by calling it, passing cin as an 
//argument.
int main()
{
  istream& is=foo(cin);
  cout << is.rdstate() << endl;
  return 0;
}
