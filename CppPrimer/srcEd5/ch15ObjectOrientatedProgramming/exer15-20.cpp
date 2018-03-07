/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

////////////////////////////////////////////////////////////////////////////
//Base
class Base
{
public:
  Base()=default;
  virtual ~Base()=default;
  void pub_mem(){cout << "B: pub_mem" << endl;}
protected:
  int prot_mem = 42;
private:
  char priv_mem = 'R';
};
////////////////////////////////////////////////////////////////////////////
//First derived
class Pub_Derv : public Base
{
public:
  void memfcn(Base &b) { b = *this; }
};
class Prot_Derv : protected Base
{
public:
  void memfcn(Base &b) { b = *this; }
};
class Priv_Derv : private Base
{
public:
  void memfcn(Base &b) { b = *this; }
};
////////////////////////////////////////////////////////////////////////////
//Second derived
class Derived_from_Public : public Pub_Derv
{
public:
  void memfcn(Base &b) { b = *this; }
};
class Derived_from_Protected : public Prot_Derv
{
public:
  void memfcn(Base &b) { b = *this; }
};
class Derived_from_Private : public Priv_Derv
{
public:
//  void memfcn(Base &b) { b = *this; }
};


int main()
{
  Base b;
  b.pub_mem();
 

//  Base *p = &d1;//d1 has type Pub_Derv - legal
//  p = &d2;      //d2 has type Priv_Derv - illegal
//  p = &d3;      //d3 has type Prot_Derv - illegal
//  p = &dd1;     //dd1 has type Derived_from_Public - legal
//  p = &dd2;     //dd2 has type Derived_from_Private - illegal
//  p = &dd3;     //dd3 has type Derived_from_Protected - illegal

  return 0;
}

