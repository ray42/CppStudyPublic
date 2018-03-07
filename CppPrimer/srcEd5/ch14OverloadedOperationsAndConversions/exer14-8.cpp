/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"Book8.h"
#include<iostream>
using std::cout; using std::endl;
#include<sstream>
using std::istringstream;

int main()
{
  cout << "Testing default constructor" << endl;
  Book b1;
  b1.printall()<<endl;
  cout << endl;

  cout << "Testing is constructor and >> operator" << endl;
  istringstream iss("42 C++Book Ray 11-11-11");
  Book b2(iss);
  b2.printall() << endl;
  cout << endl;

  cout << "Testing <<" << endl;
  cout << b2 << endl;
  cout << endl;

  cout << "Testing ==, !=" << endl;
  cout << "b2 == b2: " << (b2==b2) << endl;
  cout << "b2 != b2: " << (b2!=b2) << endl;
  cout << "b1 == b2: " << (b1==b2) << endl;
  cout << "b1 != b2: " << (b1!=b2) << endl;
  cout << endl;
  
  return 0;
}
