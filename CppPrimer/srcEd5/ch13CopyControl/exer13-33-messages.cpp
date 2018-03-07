/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<set>
using std::set;

#include "Message.h"

int main()
{
  Message msg1("message1");
  set<Message*> msgset;
  msgset.insert(&msg1);
  msgset.erase(&msg1);

  return 0;
}
