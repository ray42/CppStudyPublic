/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<map>
using std::map;

#include<functional>
using std::function;
using std::minus;

#include<string>
using std::string;

// ordinary function
int add(int i, int j) {return i+j;}

// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j){ return i%j;};

// function-object class
struct divide
{
  int operator()(int denominator, int divisor)
  {
    return denominator/divisor;
  }
};

int main()
{
  map<string, function<int(int,int)> > binops=
  {
    {"+", add},   // function pointer
    {"-", std::minus<int>()},// library function object
    {"/", divide()},  // user-defined function object
    {"*",[](int i, int j){return i*j;}}, // unnamed lambda
    {"%", mod} // named lambda object
  };
  cout << binops["+"](10, 5) << endl; // calls add(10, 5)
  cout << binops["-"](10, 5) << endl; // uses the call operator of the minus<int> object
  cout << binops["/"](10, 5) << endl; // uses the call operator of the div object
  cout << binops["*"](10, 5) << endl; // calls the lambda function object
  cout << binops["%"](10, 5) << endl; // calls the lambda function object

  return 0;
}
