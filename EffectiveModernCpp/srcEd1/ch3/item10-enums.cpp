/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<tuple> // tuple, make_tuple, get
#include<string>
#include<type_traits>
using std::underlying_type;
using std::underlying_type_t;

// Trying to convert scoped enums to its underlying type for use in
// // tuple get.
enum class UserInfoFields{ uiName, uiEmail, uiReputation};

using UserInfo =           // type alias; see Item 9
  std::tuple<std::string,  // name
             std::string,  // email
             std::size_t>; // reputation


// Let's write a function template that takes an enum and return its
// underlying type. C++11 version.
template<typename E>
constexpr typename std::underlying_type<E>::type
  toUType11(E enumerator) noexcept
{
  return
    static_cast<typename 
                std::underlying_type<E>::type >(enumerator);
}

template<typename E>
constexpr underlying_type_t<E>
  toUType14(E enumerator) noexcept
{
  return static_cast<underlying_type_t<E>>(enumerator);
}

// C++14 with auto SLEEEEEEK
template<typename E>
constexpr auto toUType14auto(E enumerator) noexcept
{
  return static_cast<underlying_type_t<E>>(enumerator);
}

int main()
{
  UserInfo uInfo(std::make_tuple("Ray","ray@gmail.com",42));
  
  {// This works but it's very verbose.
  auto val = // std::get<number>(tuplevar)
    std::get<static_cast<std::size_t>(UserInfoFields::uiEmail) >
      (uInfo);
  cout << val << endl;
  }
  { // using toUType11
  auto val = std::get<toUType11(UserInfoFields::uiName)>(uInfo);
  cout << val << endl;
  }
  { // using toType14
  auto val = std::get<toUType14(UserInfoFields::uiName)>(uInfo);
  cout << val << endl;
  }
  { // SLEEEEEK
  auto val = std::get<toUType14auto(UserInfoFields::uiName)>(uInfo);
  cout << val << endl;
  }

  return 0;
}
