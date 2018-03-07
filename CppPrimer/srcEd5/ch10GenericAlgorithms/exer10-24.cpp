/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<functional>
using std::bind; using namespace std::placeholders;

#include<algorithm>
using std::find_if;

template<typename T>
bool check_size(const T &s, typename T::size_type sz)
{
  return s.size() >= sz;
}

// Exercise 10.24: Use bind and check_size (in listing 10.3 (p. 545)) to 
// find the first element in a vector of ints that has a value greater than
// the length of a specified string value.
int main()
{
  vector<int> iv{9,9,9,4,5,6,7,8,9};

  string str("hello");
  auto it = find_if(iv.begin(), iv.end(),
                    bind(check_size<string>,str,_1));
  if(it != iv.end())
    cout << *it << endl;
  else
    cout << "Not found" << endl;

  return 0;
}
