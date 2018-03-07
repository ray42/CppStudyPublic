/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"StrVec26.h"
#include"./../common/rr.h"

#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<memory>
using std::allocator;
using std::uninitialized_copy;

#include<utility>
using std::pair;
using std::move;

#include<algorithm>
using std::copy;
using std::lexicographical_compare;

#include<iterator>
using std::ostream_iterator;

#include<initializer_list>
using std::initializer_list;

// This is declared as static in the header file.
allocator<string> StrVec::alloc;

// copy constructor
StrVec::StrVec(const StrVec& s):
  elements(nullptr), first_free(nullptr), cap(nullptr)
{
  rr::greet(__PRETTY_FUNCTION__,this);

  auto newdata = alloc_n_copy(s.begin(),s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<string>lst):
  elements(nullptr),first_free(nullptr),cap(nullptr)
{
  auto newdata = alloc_n_copy(lst.begin(),lst.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
  rr::greet(__PRETTY_FUNCTION__,this);
  
  // call alloc_n_copy to allocate exactly as many elements as in rhs
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free(); // free THIS.

  // copy the pointers from above call to alloc_n_copy
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

// destructor
StrVec::~StrVec()
{
  rr::greet(__PRETTY_FUNCTION__,this);

  free();
}

// Move constructor!!!!
StrVec::StrVec(StrVec &&s) noexcept // move won't throw any exceptions
  : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
  // leave s in a state in which it is safe to run the destructor
  s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
  // direct test for self-assignment
  if(this!=&rhs)
  {
    free(); // free existing elements
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    // leave rhs in a destructible  state
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }

  return *this;
}

StrVec& StrVec::operator=(initializer_list<string>il)
{
  // free
  free();
  auto newdata = alloc_n_copy(il.begin(),il.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

string& StrVec::operator[](size_t n)
{
  return elements[n];
}

const string& StrVec::operator[](size_t n) const
{
  return elements[n];
}

////////////////////////////////////////////////////////////////////////////
void StrVec::push_back(const string& s)
{
  chk_n_alloc(); // ensure that there is room for another element
  // construct a copy of s in the element to which first_free points
  alloc.construct(first_free++,s);
}

// Allocates just enough space for e-b elements.
// returns a pair to the first and one past the last element.
pair<string*,string*> 
StrVec::alloc_n_copy(const string *b, const string* e)
{
  // allocate space to hold as many elements as are in the range
  auto data = alloc.allocate(e-b);
  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
  return {data,uninitialized_copy(b,e,data)};
}

// Destroys all elements in THIS StrVec
// deallocate the space taken by this StrVec
void StrVec::free()
{
  // may not pass deallocate a 0 pointer; 
  // if elements is 0, there's no work to do
  if(elements)
  {
//    // destroy the old elements in reverse order
//    for(auto p = first_free; p!=elements; /* empty */)
//      alloc.destroy(--p);
    
    // Ex43 - using foreach
    for_each(elements,first_free,
        [](string &s)
        {
         alloc.destroy(&s);
        });

    alloc.deallocate(elements,cap-elements);
  }
}

// allocates new mem to be 2* current size()
// copies current elements into the new space
// free old space
// resets the points to the new space.
void StrVec::reallocate()
{
  // we'll allocate space for twice as many elements as the current size
  auto newcapacity = size()?2*size():1;

  // allocate new memory
  auto newdata = alloc.allocate(newcapacity);

  // move the data from the old memory to the new
  auto dest = newdata; // points to the next free position in the new array
  auto elem = elements; // points to the next element in the old array

  for (size_t i = 0; i != size(); ++i)
  {
    alloc.construct(dest++,std::move(*elem++));
  }

  free(); // free the old space once we've moved the lements

  elements = newdata;
  first_free = dest;
  cap = elements+newcapacity;
}

std::ostream& StrVec::printall(std::ostream& os) const
{
  os << "p: "<< this
       << ", size: " << size() << ", capacity: " << capacity() << endl;
  os << "contents: ";
  copy(begin(),end(),ostream_iterator<string>(os," "));
  return os;
}

// Request a change in capacity
// Requests that the vector capacity be at least enough to contain n 
// elements.
//
// If n is greater than the current vector capacity, the function causes 
// the container to reallocate its storage increasing its capacity to n 
// (or greater).
//
// In all other cases, the function call does not cause a reallocation and
// the vector capacity is not affected.
//
// This function has no effect on the vector size and cannot alter its
// elements.
void StrVec::reserve(size_t n)
{
  if(n>capacity())
  {
    size_t newcapacity = n;

    // allocate new memory
    string* newdata = alloc.allocate(newcapacity);

    // move the data from the old memory to the new:
    string* dest = newdata; //points to the next free position in the new array
    string* elem = elements;//points to the next element in the old array

    for(size_t i = 0; i != size(); ++i)
    {
      alloc.construct(dest++,std::move(*elem++));
    }

    free();

    elements = newdata;
    first_free = dest;
    cap = elements+newcapacity;
  }
}

// Change size
// Resizes the container so that it contains n elements.
//
// If n is smaller than the current container size, the content is reduced
// to its first n elements, removing those beyond (and destroying them).
//
// If n is greater than the current container size, the content is 
// expanded by inserting at the end as many elements as needed to reach a
// size of n. If val is specified, the new elements are initialized as
// copies of val, otherwise, they are value-initialized.
//
// If n is also greater than the current container capacity, an automatic
// reallocation of the allocated storage space takes place.
void StrVec::resize(const size_t n, const string& val)
{
  if(n < size())
  {
    auto newfirst_free = elements+n;
    while(first_free != newfirst_free)
    {
      alloc.destroy(--first_free);
    }
  }
  else if(n > size())
  {
    for(auto i=size(); i < n; ++i)
    {
      push_back(val);
    }
  }
}

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
  if (lhs.size() == rhs.size())
  {
    for(const string *lhsit = lhs.cbegin(), *rhsit = rhs.cbegin(); 
        lhsit != lhs.cend(); ++lhsit, ++rhsit)
    {
      if(*lhsit != *rhsit)
        return false;
    }
    return true;
  }
  else
  {
    return false;
  }
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
  return !(lhs == rhs);
}

// exer14-18 inequality
bool operator<(const StrVec&lhs, const StrVec&rhs)
{
  return lexicographical_compare(lhs.cbegin(),lhs.cend(),
                                 rhs.cbegin(),rhs.cend());
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
  return rhs < lhs;
}
bool operator<=(const StrVec&lhs, const StrVec&rhs)
{
  // lhs <= rhs == !(lhs>rhs) == !(rhs<lhs)
  return !(rhs<lhs);
}

bool operator>=(const StrVec&lhs, const StrVec&rhs)
{
  // lhs >= rhs == !(lhs<rhs)
  return !(lhs<rhs);
}


