/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is
// defined
template<typename T>
ostream &print(ostream &os, const T &t)
{
  return os << t; // no separator after the last element in the pack
}

// this version of print will be called for all but he last element in the 
// pack
template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest)
{
  os << t << ", "; // print the first argument
  return print(os, rest...); // recursive call; print the other arguments
}

int main()
{
  int i = -220;
  unsigned u = 284;
  double d = 4.2;
  string s("string");


  cout << "print with 1 argument" << endl;
  print(cout,i) << endl;
  cout << "\nprint with 2 argument" << endl;
  print(cout,i,u) << endl;
  cout << "\nprint with 5 argument" << endl;
  print(cout,i,u,d,s,"char") << endl;


  return 0;
}

