/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include"stack_it9.h"


int main()
{
  Stack<int> s1;
  auto s2(s1);
  auto s3 = s1;
  return 0;
}

