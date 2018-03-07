/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from Exceptional C++
 *==========================================================================
 */

#ifndef STACK_IT10_H
#define STACK_IT10_H
#include<cstddef>// size_t
#include<algorithm> // copy
#include<iterator> // begin
#include<cassert> // assert
#include<iostream>



template<typename T>
class Stack
{
public:
  Stack();  // default constructor
  ~Stack() noexcept; // destructor

  Stack(const Stack&);
  Stack& operator=(const Stack&);

  std::size_t Count() const;
  void Push(const T&);

  T& Top(); // if empty, throws exception
  const T& Top() const;

  void Pop(); // if empty, throws exception
  bool Empty() const;

  // debugging
  // strange, I have to put default arguments here.
  // since it's a template function.... hmm!
  std::ostream& rrdebug(std::ostream& = std::cout);


private:
  T*          v_;     // ptr to a memory area big
  std::size_t vsize_; // enough for 'vsize_' T's
  std::size_t vused_; // # of T's actually in use
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template<typename T>
std::ostream& Stack<T>::rrdebug(std::ostream& os)
{
  os << "Hi from: " << this << "\n";
  os << "vsize_: " << vsize_ << ", vused_: " << vused_ << endl;
  for(decltype(vused_) i = 0; i != vused_; ++i)
  {
    os << v_[i] <<", ";
  }
  os << "\n";
  return os;
}


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

// Count
template<typename T>
std::size_t Stack<T>::Count() const
{
  return vused_;
}

// Push
template<typename T>
void Stack<T>::Push(const T& t)
{
  if(vused_ == vsize_) // grow if necessary by some growth factor.
  {
    size_t vsize_new = vsize_*2+1; // this takes care of 0 initial size.
    T* v_new = NewCopy(v_, vsize_, vsize_new); // exception safe and 
                                               // exception neutral
    // At this take, the risky stuff is over, we do things which
    // is exception safe and exception neutral, like clean up.
    delete[] v_; // this can't throw
    v_ = v_new;
    vsize_ = vsize_new;
  }

  // do the actual work
  // T::operator=() might throw anything.
  v_[vused_] = t;
  ++vused_;
}

// Pop, the problem with this is that it modifies the state of the object
// and tries to return by value. Thus it's doing two things. Let's make
// them do one thing only, Pop - popping the top-most value off the stack
// Top - querying the top-most value.
//template<typename T>
//T Stack<T>::Pop()
//{
//  if(vused_ == 0)
//  {
//    throw "pop from empty stack";
//  }
//  else
//  {
//    // Note that we shouldn't do T result = v_[vused_--]; since if
//    // the assignment failed, we would have changed the state. This is
//    // not true!
//    T result = v_[vused_-1];
//    --vused_;
//    return result;
//  }
//}

template<typename T>
T& Stack<T>::Top()
{
  if(vused_ == 0)
  {
    throw "Top on empty stack";
  }
  else
  {
    return v_[vused_-1];
  }
}

template<typename T>
const T& Stack<T>::Top() const
{
  if(vused_ == 0)
  {
    throw "Top on empty const stack";
  }
  else
  {
    return v_[vused_-1];
  }
}

template<typename T>
void Stack<T>::Pop()
{
  if(vused_==0)
  {
    throw "pop from empty stack";
  }
  else
  {
    --vused_;
  }
}

template<typename T>
bool Stack<T>::Empty() const
{
  return (vused_ == 0);
}


#endif
