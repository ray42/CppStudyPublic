#ifndef GUARD_RAYHEADER_H
#define GUARD_RAYHEADER_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>

// rayheader.h header file
namespace ray
{

  template<class T> std::string print_vec(std::vector<T> vec)
  {
    std::ostringstream ss;
    for(typename std::vector<T>::const_iterator it = vec.begin();
        it != vec.end(); ++it)
    {
      ss << *it << " ";
    }

    return ss.str();
  }

  template<class T> std::string print_container(T begin, T end)
  {
    std::ostringstream ss;

    while (begin != end) 
    {
      ss << *(begin++) << std::endl;
    }
    return ss.str();
  }

//  template<class H, class S> std::string print_map()

//  template<template <class> class H, class S > 
//  void print_container(const H<S>& container)
//                       std::string print_ele = printvecele)
//  {
//    H<S>::const_iterator begin_it = container.begin();
//    H<S>::const_iterator end_it = container.end();

//    for(typename H<S>::const_iterator it = container.begin();
//        it != container.end(); ++it)
//    {
//      std::cout << (*it) << " ";
//    }
//
//  }
}

#endif


