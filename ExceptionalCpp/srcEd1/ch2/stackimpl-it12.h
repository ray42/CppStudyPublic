/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from Exceptional C++
 *==========================================================================
 */

#include<cstddef> // size_t


template<typename T> class StackImpl
{
  /* ???? */
  StackImpl(std::size_t size = 0);
  ~StackImpl();
  
  void Swap(StackImpl& other) throw();

  T*          v_;    // ptr to a memory area big
  std::size_t vsize_;// enough for 'vsize_' T's
  std::size_t vused_;// # of T's actually in use
private:
  // private and undefined: no copying allowed (in C++11, we should use delete)
  StackImpl(const StackImpl&);
  StackImpl& operator=(const StackImpl&);
};

// constructor: only allocate memory, does not call the constructors of T's.
template<typename T>
StackImpl<T>::StackImpl(std::size_t size)
  :v_(static_cast<T*>(size == 0
                      ?0
                      :operator new(sizeof(T)*size))),
   vsize_(size),
   vused_(0)
{}

template<typename T>
StackImpl<T>::~StackImpl()
{
  // Calls the destructors
  destroy(v_, v_+vused_); // this can't throw

  // RRR why is this not operator delete[]()?
  operator delete(v_);
}



