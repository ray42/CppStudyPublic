/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

template<typename T, typename U>
auto sum(T a, U b)->decltype(a+b)
{
  return a+b;
}

int main()
{
  cout << sum(1234566,1343.343243) << endl;
  return 0;
}
