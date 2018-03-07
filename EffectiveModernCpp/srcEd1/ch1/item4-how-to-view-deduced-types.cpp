/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;

#include<boost/type_index.hpp>


template<typename T> // 
class TD;


template<typename T>
void f(const T& param)
{
  using boost::typeindex::type_id_with_cvr;

  // show T
  cout << "T =     "
       << type_id_with_cvr<T>().pretty_name()
       << "\n";

  // show param
  cout << "param = "
       << type_id_with_cvr<decltype(param)>().pretty_name()
       << "\n";

  TD<T> TType;
  TD<decltype(param)> paramType;
}

class Widget
{
  string hello = "";
};

std::vector<Widget> createVec()
{
  vector<Widget> v;
  v.push_back(Widget{});
  v.push_back(Widget{});
  v.push_back(Widget{});
  return v;
}

int main()
{
  // Compiler Diagnostics
//  constexpr int theAnswer = 42;
//  auto x = theAnswer;
//  auto px = &theAnswer;
//  auto& rx = theAnswer;
//
//  TD<decltype(x)> xType;
//  TD<decltype(px)> pxType;
//  TD<decltype(rx)> rxType;


  // Comback and do this with perfect forwarding! And put in rr header,
  // this is quite cool.
  const auto vw = createVec();
  f(&vw[0]);
 
 
  return 0;
}

