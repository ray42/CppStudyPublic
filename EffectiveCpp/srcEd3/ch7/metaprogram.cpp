/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

template<unsigned n>
struct Factorial
{
  enum{value = n*Factorial<n-1>::value};
};

template<>
struct Factorial<0>
{
  enum {value=1};
};

int main()
{
  cout << Factorial<5>::value << endl;
  return 0;
}

