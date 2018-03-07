/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */


#include <iostream>
#include <array>

template<int N>
  std::array<int,N> arr{};  // array with N elements, zero-initialized

template<auto N>
constexpr decltype(N) dval = N; // type of dval depends on passed value

int main() 
{
  std::cout << dval<'c'> << '\n'; // N has value 'c' of type char
  arr<10>[0] = 42;                // sets first element of global arr
  
  arr<11>[2]=11;
//  for (std::size_t i=0; i<arr<10>.size(); ++i) { // uses values set in arr
//    std::cout << arr<10>[i] << '\n';
//  }
}


