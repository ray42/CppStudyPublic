/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

template<typename T, typename ... Args>
void foo(const T &t, const Args& ... rest)
{
  cout << sizeof... (Args) << endl; // number of parameter types
  cout << sizeof... (rest) << endl; // number of function parameters
}

int main()
{
  int i = 0; double d = 3.14; string s = "how now brown cow";
  foo(i, s, 42, d);    // three parameters in the pack
  cout << endl;
  foo(s, s, s, s);    // three parameters in the pack 
  cout << endl;
  foo(s, 42, "hi");    // two parameters in the pack
  cout << endl;
  foo(d, s);           // one parameter in the pack
  cout << endl;
  foo("hi");           // empty pack
  cout << endl;

  return 0;
}
