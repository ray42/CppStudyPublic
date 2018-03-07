/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include "Employee.h"

int main()
{
  cout << "Hi from main" << endl;
  Employee e1;
  Employee e2("Ray");
  Employee e3("Johanna");

  cout << e1.print() << endl;
  cout << e2.print() << endl;
  cout << e3.print() << endl;

  return 0;
}
