/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<functional>
using std::bind;
using namespace std::placeholders;

#include<algorithm>
using std::count_if;

//Exercise 10.22: Rewrite the program to count words of size 6 or less using
//functions in place of the lambdas.

// Because I integrated the program to count words less than 6 characters in
// the biggies function, changing it would require extraction of the 
// functionality. Thus, I will do it here instead.
template<typename T>
bool sizeLessThanOrEqualTo(const T &c, typename T::size_type sz)
{
  return c.size() <= sz;
}

int main()
{
  vector<string> str{"q","q","qqqqqqq","qqqqqqq","qqqqqqqq","qqqqqqqq"};

  auto i=count_if(str.begin(),str.end(),
      bind(sizeLessThanOrEqualTo<string>,_1,6));
  cout << i << endl;

  // NOTE:
  // Below does not work, compile error since it cannot resolve the template
  // at compile time
  // auto f=bind(sizeLessThanOrEqualTo,_1,6); // Not working
  //
  // need to pass the template args
  // auto f=bind(sizeLessThanOrEqualTo<string>,_1,6); // Working!

  return 0;
}
