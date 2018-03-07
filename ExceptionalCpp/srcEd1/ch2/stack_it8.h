/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from Exceptional C++
 *==========================================================================
 */

#ifndef STACK_IT8_H
#define STACK_IT8_H
#include<cstddef>// size_t


template<typename T>
class Stack
{
public:
  Stack();  // default constructor
  ~Stack() noexcept; // destructor
  /* ... */
private:
  T*          v_;     // ptr to a memory area big
  std::size_t vsize_; // enough for 'vsize_' T's
  std::size_t vused_; // # of T's actually in use
};

template<typename T>
Stack<T>::Stack()
  :v_(new T[10]), // default allocation
  vsize_(10),
  vused_(0) // nothing used yet.
{}

template<typename T>
Stack<T>::~Stack() noexcept
{
  delete [] v_; // this can't throw
}
#endif
