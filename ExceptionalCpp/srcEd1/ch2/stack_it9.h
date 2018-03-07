/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from Exceptional C++
 *==========================================================================
 */

#ifndef STACK_IT9_H
#define STACK_IT9_H
#include<cstddef>// size_t
#include<algorithm> // copy
#include<iterator> // begin
#include<cassert> // assert


template<typename T>
class Stack
{
public:
  Stack();  // default constructor
  ~Stack() noexcept; // destructor

  Stack(const Stack&);
  Stack& operator=(const Stack&);

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
////////////////////////////////////////////////////////////////////////////

// Helper function, returns a pointer to a new array of size destsize
// containing src to srcsize.
template<typename T>
T* NewCopy(const T*    src,
           std::size_t srcsize,
           std::size_t destsize)
{
  assert(destsize>=srcsize);

  // 1) the allocation might throw bad_alloc
  // 2) The T::T default constructor might throw anything.
  // In either case, nothing is allocated an we simply allow the exception
  // to propagate. This is both leak-free and exception-neutral.
  T* dest = new T[destsize];
  try
  {
    std::copy(src, src+srcsize, dest);
  }
  catch(...)
  {
    delete[] dest; // this can't throw
    throw;         // rethrow
  }

  return dest;
}

// copy constructor
template<typename T>
Stack<T>::Stack(const Stack<T>& other)
  : v_(NewCopy(other.v_,
               other.vsize_,
               other.vsize_)),
  vsize_(other.vsize_),
  vused_(other.vused_)
{
}

// copy assignment
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
  if(this != other)
  {
    T* v_new = NewCopy(other.v_,
                       other.vsize_,  // srcsize
                       other.vsize_); // destsize
    delete[] v_; // this can't throw
    v_ = v_new; // take ownership
    vsize_ = other.vsize_;
    vused_ = other.vused_;
  }
  return *this; // safe, no copy involved
}



#endif
