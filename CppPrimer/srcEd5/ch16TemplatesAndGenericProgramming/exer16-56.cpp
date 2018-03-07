/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */

#include<iostream>
using std::cout; using std::endl; using std::ostream;

#include<sstream>
using std::ostringstream;

#include<string>
using std::string;

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

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template<typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
  // print(os, debug_rep(a1), debug_rep(a2),...,debug_rep(an));
  return print(os,debug_rep(rest)...);
}

int main()
{
  //errorMsg(cout,"H1","H2","H3","H4","H5","H6");
  return 0;
}
