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

static int gcount=0;
void process(shared_ptr<int> ptr)
{
  cout << "gcount: "<<gcount++
       << ", use_count: " << ptr.use_count() << endl << endl;
}

int main()
{
  int* p = new int();
  shared_ptr<int> sp = make_shared<int>();

  process(sp);

  process(shared_ptr<int>(p));

  return 0;
}
