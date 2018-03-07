/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

#include"./../common/rr.h"

#include<iostream>
using std::cout; using std::endl;

int main()
{
  rr::greet(__PRETTY_FUNCTION__);
  cout << "Hello from testrr" << endl;
  return 0;
}

