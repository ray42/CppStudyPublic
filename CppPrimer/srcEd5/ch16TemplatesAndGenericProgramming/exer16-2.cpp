/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<functional> // less


template<typename T> int compare(const T &v1, const T &v2)
{
  if(std::less<T>()(v1,v2)) return -1;
  if(std::less<T>()(v2,v1)) return 1;
  return 0;
}

int main()
{
  cout << compare(1,2)<< endl;
  cout << compare(2,1)<< endl;
  cout << compare(2,2)<< endl;
  return 0;
}
