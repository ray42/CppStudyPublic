/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

struct A1{
};
struct A2:public A1{
};
struct A3: public A2{
  int i = 42;
};

struct B1{
  int i = 220;
};
struct B2:public B1{
};

struct C: public A3, public B2{
};

int main()
{
  C c;
  cout << c.i << endl; 
  return 0;
}

