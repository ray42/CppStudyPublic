/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<utility> // std::forward

#include<memory> // shared_ptr

#include<string>
using std::string;


template<typename T, typename... Args>
std::shared_ptr<T> my_make_shared(Args&&... args) // unpack Args
{
  // create a shared_ptr to T.
  // Use T's constructor, forward argument to retain all type information
  // about those arguments.
  std::shared_ptr<T> ret(new T(std::forward<Args>(args)...));
  return ret;
}

int main()
{
  std::shared_ptr<string> sp = my_make_shared<string>(4,'a');
  cout << *sp << endl;
  return 0;
}
