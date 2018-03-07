/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

//Exercise 10.14: Write a lambda that takes two ints and returns their sum.
int main()
{
  auto f=[](int i, int j)->int
         {
           return i+j;
         };
  cout << f(1,1) << endl;
  cout << f(2,4) << endl;
  cout << f(5,3) << endl;
  return 0;
}
