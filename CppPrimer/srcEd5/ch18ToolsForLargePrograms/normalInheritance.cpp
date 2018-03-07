/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

struct A{
  A(){cout << "A Default constructor" << endl;}
  A(const string &s) {cout << "A(string), s: " << s << endl;}
};

struct B:public A{
  B(const string &s): A(s)
  {
//    this->A(s);
  }
};

int main()
{
  B b("String passed to B");
  return 0;
}

