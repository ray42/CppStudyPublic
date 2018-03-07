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
#include<vector>
using std::vector;
#include<algorithm>

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
  istringstream iss("Hello this is a string\nAnother one,\nand another one");
  ReadString rs(iss);
  vector<string> vs;
  string s = rs();
  while(!s.empty())
  {
    vs.push_back(s);
    // get next line
    s=rs();
  }

  std::for_each(vs.begin(),vs.end(),
      [](const string& s)
      { 
        cout << s << "\n";
      });

  return 0;
}
