/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

#include<functional> // function

template<typename T>
class MySharedPtr
{
public:
  MySharedPtr


private:
  T* ptr; // pointer to the object.
  std::size_t* ref_count; // reference count
  
  // the deleter should take a pointer to T and return void.
  // it must destroy T and free the allocated memory.
  // Thus a deleter function is of the form void foo(T*)
  // which gives call signature void (T*)
  std::function<void (T*)> deleter;


};





#endif




