/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<memory>
using std::shared_ptr;
using std::make_shared;

void process(shared_ptr<int> ptr)
{
  cout << ptr.use_count() << endl;
}

int main()
{
  shared_ptr<int>ipt = make_shared<int>(42);
  cout << ipt.use_count() << endl;
  process(ipt);
  cout << ipt.use_count() << endl;
  return 0;
}
