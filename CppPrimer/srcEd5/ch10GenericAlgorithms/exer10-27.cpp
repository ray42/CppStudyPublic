/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"./../common/cpp_primer_common.h"

#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<iterator>
using std::back_inserter;

#include<algorithm>
using std::unique_copy;

//Exercise 10.27: In addition to unique (§ 10.2.3 (p. 529)), the library 
//defines function named unique_copy that takes a third iterator denoting a 
//destination into which to copy the unique elements. Write a program that 
//uses unique_copy to copy the unique elements from a vector into an 
//initially empty list.
void ex27()
{
  vector<int> iv={1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,7,7};
  list<int> il;
  unique_copy(iv.begin(),iv.end(),back_inserter(il));

  cppp::print_seq(il);
  cout << endl;
}

//Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
//into three other containers. Use an inserter , a back_inserter , and a 
//front_inserter, respectively to add elements to these containers. Predict
//how the output sequence varies by the kind of inserter and verify your 
//predictions by running your programs.
void ex28()
{
  vector<unsigned> uv{1,2,3,4,5,6,7,8,9};
  list<unsigned> v_inserter;
  list<unsigned> v_back_inserter;
  list<unsigned> v_front_inserter;

  copy(uv.begin(),uv.end(),inserter(v_inserter,v_inserter.begin()));
  copy(uv.begin(),uv.end(),back_inserter(v_back_inserter));
  copy(uv.begin(),uv.end(),front_inserter(v_front_inserter));

  cppp::print_seq(v_inserter);
  cout << endl;
  cppp::print_seq(v_back_inserter);
  cout << endl;
  cppp::print_seq(v_front_inserter);
  cout << endl;
}

int main()
{
  ex27();

  ex28();

  return 0;
}
