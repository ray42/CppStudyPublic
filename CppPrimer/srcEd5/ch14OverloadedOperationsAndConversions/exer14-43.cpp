/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<functional>
using std::modulus;
#include<algorithm>
using std::any_of;

#include<vector>
using std::vector;

int main()
{
  // Using library function objects, determine whether a given int value is
  // divisible by any element in a container of ints.
  vector<int> vi{2,3,5,7,11,13};

  modulus<int> mod;
  int number = 17;
  auto pred = [number,mod](int i)->bool
              {
                return mod(i,number) == 0;
              };
  bool anydivis = any_of(vi.begin(),vi.end(),pred);

  cout << (anydivis?"yes":"no") << endl;

  return 0;
}
