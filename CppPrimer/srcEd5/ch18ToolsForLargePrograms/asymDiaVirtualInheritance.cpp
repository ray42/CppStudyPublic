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

struct V
{
  V():vstring("defaut vstring")
  {
    cout << "V default constructor" << endl;
  }

  V(const string &s):vstring(s)
  {
    cout << "Hi from V, s: " << s << endl;
  }
  string vstring;
};

struct B1: virtual public V
{
  B1(const string &s):V("B1 init V"), b1string(s)
  {
    cout << "Hi from B1" << endl;
  }

  string b1string;
};

struct B2: virtual public V
{
  B2(const string &s):V("B2 init V"), b2string(s)
  {
    cout << "Hi from B2" << endl;
  }

  string b2string;
};

struct D: public B1, public B2
{
  D(const string &s):V("D init V"),
                     B1("D init B1"), B2("D init B2"), dstring(s)
  {
    cout << "Hi from D" << endl;
  }

  string dstring;
};

int main()
{
  D d("Hello");
//  cout << "Printing out d.vstring: " << d.vstring << endl;
  return 0;
}

