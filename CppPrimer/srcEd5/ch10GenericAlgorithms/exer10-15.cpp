/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

//Exercise 10.15: Write a lambda that captures an int from its enclosing
//function and takes an int parameter. The lambda should return the sum of
//the captured int and the int parameter.
int main()
{
  int i=1;
  auto f=[i](int j)->int
  {
    return i+j;
  };
  cout << f(1) << endl;
  cout << f(4) << endl;
  return 0;
}
