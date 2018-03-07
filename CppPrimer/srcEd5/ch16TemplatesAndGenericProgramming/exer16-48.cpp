/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<sstream>
using std::ostringstream;

#include<string>
using std::string;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
template<typename T> T sayhello(T i)
{
  cout << "template sayhello: " << i << endl;
  return i;
}
int sayhello(int i)
{
  cout << "no template sayhello: " << i << endl;
  return i;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template<typename T> string debug_rep(const T &t)
{
  ostringstream ret; // 8.3
  ret << t; // uses T's output operator to print a representation of t
  return ret.str();
}

// print pointers as their pointer value, followed by the object to which 
// the pointer points. NB: this function will not work properly with char*
template<typename T> string debug_rep(T *p)
{
  ostringstream ret;
  ret << "pointer: " << p;      // print the pointer's own value
  if(p)
    ret << " " << debug_rep(*p);// print the value to which p points.
  else
    ret << " null pointer";     // or indicate that the p is null

  return ret.str(); // return a copy of the string to which ret is bound.
}

// print strings inside double quotes
string debug_rep(const string& s)
{
  return '"' + s + '"';
}

// convert the character pointers to string and call the string version of
// debug_rep
string debug_rep(char * p)
{return debug_rep(string(p));}
string debug_rep(const char* p)
{return debug_rep(string(p));}

int main()
{
//  sayhello(284);
//  sayhello<int>(220);

  string s("hi");
  cout << debug_rep(s)<<endl;
  cout << debug_rep(&s)<<endl;

  const string *sp = &s;
  cout << debug_rep(sp) << endl;



  return 0;
}













