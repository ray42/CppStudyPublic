/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::istream; using std::cin;
#include<string>
using std::string;
#include<sstream>
using std::istringstream;

class ReadString
{
public:
  ReadString(istream& i = cin):is(i)
  { /* empty */ }

  string operator()()
  {
    string s;
    if(getline(is,s))
    {
      return s;
    }
    else
    {
      return string();
    }
  }

private:
  istream& is; // reference to which to read the string from.
};

int main()
{
  istringstream iss("Hello this is a string\nAnother one.");
  ReadString rs(iss);
  cout << rs() << endl;
  cout << rs() << endl;
  return 0;
}
