/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<utility> // std::forward

void f(int v1,int &v2) // note v2 is a reference
{
  cout << v1 << " " << ++v2 << endl;
}

void g(int &&v1, int &v2)
{
  cout << v1 << " " << ++v2 << endl;
}

// template that takes a callable and two parameters
// and calls the given callable with the parameters ``flipped''
// flip1 is an incomplete implementation: top-level and const and references
// are lost
template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
  f(t2,t1);
}

template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
  f(t2,t1);
}

template<typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2)
{
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

//template<typename Type> intermediary(Type &&arg)
//{
//  finalFcn(std::forward<Type>(arg));
//  // ...
//}

int main()
{
  int i = 3;
  f(42,i);
  cout << "i: " << i << endl;
  flip1(f,i,42);
  cout << "i: " << i << endl;

//  flip1(g,i,42); // cause error
//  flip2(g,i,42); // cause error
  flip3(g,i,42);

  return 0;
}
