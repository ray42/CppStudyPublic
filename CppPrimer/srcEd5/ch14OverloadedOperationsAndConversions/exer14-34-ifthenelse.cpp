/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

struct
{
  int operator()(bool cond, int a,int b)
  {
    return cond?a:b;
  }
};


int main()
{
  return 0;
}

