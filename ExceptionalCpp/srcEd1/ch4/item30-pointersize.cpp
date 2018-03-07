/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

struct X
{
  char c;
  struct XImpl;
  XImpl* pimpl_;
};



int main()
{
  cout << sizeof(X::pimpl_) << endl;
  cout << sizeof(X) << endl;
  return 0;
}

