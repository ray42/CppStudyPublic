/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

// my attempt at move, see EMC+ p158
template<typename T>
typename std::remove_reference<T>::type&&
move(T&& param)
{
  using ReturnType = typename std::remove_reference<T>::type&&;
  return static_cast<ReturnType>(param);
}

template<typename T>
decltype(auto) move(T&& param)
{
  using RetType = std::remove_reference_t<T>&&;
  return static_cast<RetType>(param);
}

int main()
{
  return 0;
}

