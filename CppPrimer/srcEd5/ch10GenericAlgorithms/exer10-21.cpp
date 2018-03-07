/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
//Write a lambda that captures a local int variable and decrements that
//variable until it reaches 0. Once the variable is 0 additional calls 
//should no longer decrement the variable. The lambda should return a bool 
//that indicates whether the captured variable is 0.
int main()
{
  int val=7;
  auto f=[&val]()->bool
  {
    if(val)
    {
      return --val?false:true;
    }
    return true;
  };

  while(!f())
  {
    cout << val << endl;
  }

  // call it a few more times to see that it no longer decrements.
  f();f();f();
  cout <<"Called 3 more times, val: "<< val << endl;

  return 0;
}
