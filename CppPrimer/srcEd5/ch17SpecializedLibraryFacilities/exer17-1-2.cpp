/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include<tuple>
using std::tuple;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;

//Exercise 17.1: Define a tuple that holds three int values and initialize the
//members to 10, 20, and 30.
//
//Exercise 17.2: Define a tuple that holds a string, a vector<string>,
//and a pair<string, int>.
#include<iostream>
using std::cout; using std::endl;

int main()
{
  tuple<int,int,int> t1(10,20,30);
  tuple<string,vector<string>,pair<string,int>> 
    t2{string(),vector<string>(),make_pair(string(),int())};

  return 0;
}
