/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<typeinfo>

class A
{
public:
  A() = default;
  virtual ~A() = default;
};
class B: public A
{
public:
  B() = default;
  virtual ~B() = default;
};
class C : public B
{
public:
  C() = default;
  virtual ~C() = default;
};


int main()
{
  A *pa =new C;
  cout <<typeid(pa).name() << endl;//prints pointer to A
  C cobj;
  A& ra =cobj; // recall this is sliced down.
  cout <<typeid(&ra).name() << endl;// prints type of object C
  B *px =new B;

  A& ra2 =*px;
  cout <<typeid(ra2).name() << endl; // prints type of B.

  return 0;
}

