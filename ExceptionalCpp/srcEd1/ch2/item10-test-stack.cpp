/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include"stack_it10.h"


int main()
{
  Stack<int> s1;
  auto s2(s1);
  auto s3 = s1;

  s1.rrdebug();
  s1.Push(42);
  s1.rrdebug();

  
  return 0;
}

