/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

class B
{
public:
  B() = default;
  virtual ~B()=default;

//  virtual void f()
//  {
//    cout << "B::f" << endl;
//  }
};

class D: private B
{
public:
  D()=default;
  virtual ~D()=default;
//  virtual void f()
//  {
//    cout << "D::f" << endl;
//  }
};

int main()
{
//  D *pd = new D;
//  pd->f(); // D::f
  B *pb = new D; // doesn't compile: error: ‘B’ is an inaccessible base of ‘D’
//  pb->f();

  return 0;
}

