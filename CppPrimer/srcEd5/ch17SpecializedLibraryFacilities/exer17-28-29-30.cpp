/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
//Exercise 17.28:
//Write a function that generates and returns a uniformly distributed random
//unsigned int each time it is called.
//
//Exercise 17.29:
//Allow the user to supply a seed as an optional argument to the function you
//wrote in the previous exercise.
//
//Exercise 17.30:
//Revise your function again this time to take a minimum and maximum value 
//for the numbers that the function should return.
#include<iostream>
using std::cout; using std::endl;

#include<random> // default_random_engine, random_int_distribution
#include<ctime> // time();

//Exercise 17.28:
//unsigned gen_random()
//{
//  static std::default_random_engine e;
//  static std::uniform_int_distribution<unsigned> u_dist;
//  return u_dist(e);
//}

////Exercise 17.29:
//unsigned gen_random(unsigned seed = 0)
//{
//  static std::default_random_engine e(seed);
//  static std::uniform_int_distribution<unsigned> u_dist(0,9);
//  return u_dist(e);
//}

//Exercise 17.30:
unsigned gen_random(unsigned seed = 0, unsigned min = 0, unsigned max=9)
{
  static std::default_random_engine e(seed);
  static std::uniform_int_distribution<unsigned> u_dist(min,max);
  return u_dist(e);
}

int main()
{
  cout << gen_random(std::random_device{}()) << endl;
//  cout << gen_random(std::time(nullptr), 0, 10) << endl;
  return 0;
}

















