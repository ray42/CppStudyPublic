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
using std::weak_ptr;
using std::make_shared;

#include<string>
using std::string;

int main()
{
  shared_ptr<string> sp = make_shared<string>("Hello");
  cout << sp.use_count() << endl;
  weak_ptr<string> wp(sp);

  shared_ptr<string> sp2=wp.lock();
  cout << sp2.use_count() << endl;
  cout << sp.use_count() << endl;
  return 0;
}

