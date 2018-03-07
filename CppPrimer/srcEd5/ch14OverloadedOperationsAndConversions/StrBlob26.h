/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 * This file contains code for StrBlob StrBlobPtr and ConstStrBlobPtr
 * Adapted from 
 * https://github.com/Mooophy/Cpp-Primer/blob/master/ch14/ex14_16_StrBlob.h
 */

#ifndef STRBLOB16_H
#define STRBLOB16_H

#include"../common/cpp_primer_common.h"
#include"../common/rr.h"

#include<vector> // vector
using std::vector;
#include<string> // string
using std::string;
#include<initializer_list> // initializer_list
using std::initializer_list;
#include<memory> // make_shared shared_ptr
using std::make_shared; using std::shared_ptr; using std::weak_ptr;
#include<stdexcept>
#include<iostream>


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



// This file is split into 3 parts, StrBlob, StrBlobPtr and ConstStrBlobPtr
// First we need forward declarations
// Forward declarations needed for friend declaration in StrBlob
class StrBlobPtr;
class ConstStrBlobPtr;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//==========================================================================
// StrBlob - custom (shared pointer to) vector<string>
//==========================================================================
class StrBlob
{
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob&, const StrBlob&);
  friend bool operator!=(const StrBlob&, const StrBlob&);

  // exer14-18
  friend bool operator<(const StrBlob&, const StrBlob&);
  friend bool operator>(const StrBlob&, const StrBlob&);
  friend bool operator<=(const StrBlob&, const StrBlob&);
  friend bool operator>=(const StrBlob&, const StrBlob&);

public:

  //////////////////////////////////////////////////////////////////////////
  //Types

  // Size of the vector
  using size_type = vector<string>::size_type;
  // or we can do:
  // typedef std::vector<string>::size_type size_type;

  //////////////////////////////////////////////////////////////////////////
  //  constructors

  // default constructor
  StrBlob()
    :data_spt(std::make_shared<vector<string>>())
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }

  // braced list constructor
  StrBlob(std::initializer_list<string> il)
    :data_spt(std::make_shared<vector<string>>(il))
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }

  // copy constructor - valuelike behaviour, so that this data_spt
  // does NOT point to the same object as in sb.
  StrBlob(const StrBlob &sb)
    :data_spt(std::make_shared<vector<string>>(*sb.data_spt))
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }

  // copy assignment operator
  StrBlob& operator=(const StrBlob&);

  // Move constructor
  StrBlob(StrBlob &&rhs) noexcept
    : data_spt(std::move(rhs.data_spt))
  {
    rr::greet(__PRETTY_FUNCTION__,this);
    
    // remember this! Important to leave rhs in valid state
    rhs.data_spt = nullptr; 
  }

  // Move assignment operator
  StrBlob& operator=(StrBlob &&) noexcept;

  // No need for destructor, the shared_pt will automatically destroy and
  // free the vector when it's the last one pointing to it.

  //////////////////////////////////////////////////////////////////////////
  // operators
  std::string& operator[](size_type);
  const std::string& operator[](size_type) const;

  //////////////////////////////////////////////////////////////////////////
  // size operations
  
  // returns the number of elements
  size_type size() const {return data_spt->size();}

  // checks whether the container is empty
  bool empty() const {return data_spt->empty();}

  //////////////////////////////////////////////////////////////////////////
  // add and remove elements
  
  // adds an element to the end
  void push_back(const std::string& s){ data_spt->push_back(s);}

  // removes the last element
  void pop_back();

  //////////////////////////////////////////////////////////////////////////
  // element access
  
  // access the element at the front
  std::string& front();
  const std::string& front() const;

  // access the element at the back
  std::string& back();
  const std::string& back() const;

  //////////////////////////////////////////////////////////////////////////
  // interface to StrBlob and ConstStrBlobPtr

  StrBlobPtr begin(); // can't be defined until StrBlobPtr is.
  StrBlobPtr end();   // can't be defined until StrBlobPtr is.
  ConstStrBlobPtr cbegin(); // can't be defined until ConstStrBlobPtr is.
  ConstStrBlobPtr cend();   // can't be defined until ConstStrBlobPtr is.

  //////////////////////////////////////////////////////////////////////////
  //Debugging

  std::ostream& printall(std::ostream& os = std::cout) const;

  //////////////////////////////////////////////////////////////////////////
  //Private functions
private:

  // throws mgs if data_pt[i] isn't within range.
  void check(size_type i, const std::string& msg) const;


  //////////////////////////////////////////////////////////////////////////
  //Private variables
private:
  
  // shared pointer to vector of strings
  std::shared_ptr<std::vector<std::string>> data_spt;
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);

bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//==========================================================================
// StrBlobPtr - custom iterator for StrBlob
//==========================================================================
class StrBlobPtr
{
  friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
  
  // exer14-18 inequality operators
  friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
  friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

public:

  //////////////////////////////////////////////////////////////////////////
  // constructors///////////////////////////////////////////////////////////
  StrBlobPtr():wptr(weak_ptr<vector<string>>()),curr(0)
  { /* empty */}
  StrBlobPtr(StrBlob&sb, size_t pos = 0):wptr(sb.data_spt), curr(pos)
  { /* empty */}

  //////////////////////////////////////////////////////////////////////////
  //subscript operators
  std::string& operator[](size_t);
  const std::string& operator[](size_t) const;

  //////////////////////////////////////////////////////////////////////////
  //public functions
  
  // dereference
  string& deref() const;
  // prefix increment
  StrBlobPtr& incr();

private:
  //////////////////////////////////////////////////////////////////////////
  //private functions

  // check returns a shared_ptr to the vecor if the check succeeds.
  shared_ptr<vector<string>> check(size_t, const string&) const;

private:
  // store a weak_ptr, which means the underlying vector might be destroyed.
  weak_ptr<vector<string>> wptr;
  
  // current position within he array.
  size_t curr;
};

bool operator==(const StrBlobPtr&, StrBlobPtr&);
bool operator!=(const StrBlobPtr&, StrBlobPtr&);

// exer14-18 inequality operators
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);



// check returns a shared_ptr to the vector if the check succeeds.
inline shared_ptr<vector<string>> 
StrBlobPtr::check(size_t i, const string& msg) const
{
  // is the vector still around?
  auto ret = wptr.lock();
  if(!ret)
    throw std::runtime_error("unbound StrBlobPtr");

  // check for out of range
  if(i >= ret->size())
    throw std::out_of_range(msg);

  // otherwise, return a shared_ptr to the vector
  return ret;
}

// dereference
inline string& StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

// prefix: return a reference to the incremented object
inline StrBlobPtr& StrBlobPtr::incr()
{
  // if curr already points past the end of the container, can't incr it.
  check(curr, "increment poast end of StrBlobPtr");
  ++curr; // advance the current state
  return *this;
}

//==========================================================================
// StrBlobPtr - custom iterator for StrBlob
//==========================================================================
class ConstStrBlobPtr
{
  friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

  // exer14-18 inequality operators
  friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
 

public:
  //////////////////////////////////////////////////////////////////////////
  // constructors///////////////////////////////////////////////////////////
  ConstStrBlobPtr():wptr(weak_ptr<vector<string>>()),curr(0)
  { /* empty */}
  ConstStrBlobPtr(const StrBlob&sb, size_t pos = 0)
    :wptr(sb.data_spt), curr(pos)
  { /* empty */}

  //////////////////////////////////////////////////////////////////////////
  //subscript operators
  const std::string& operator[](size_t) const;

  //////////////////////////////////////////////////////////////////////////
  //public functions
  
  // dereference
  const string& deref() const;
  // prefix increment
  ConstStrBlobPtr& incr();

private:
  //////////////////////////////////////////////////////////////////////////
  //private functions

  // check returns a shared_ptr to the vecor if the check succeeds.
  shared_ptr<vector<string>> check(size_t, const string&) const;

private:
  // store a weak_ptr, which means the underlying vector might be destroyed.
  weak_ptr<vector<string>> wptr;
  
  // current position within he array.
  size_t curr;
};

bool operator==(const ConstStrBlobPtr&, ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, ConstStrBlobPtr&);

// exer14-18 inequality operators
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);


// check returns a shared_ptr to the vecor if the check succeeds.
inline shared_ptr<vector<string>> 
ConstStrBlobPtr::check(size_t i, const string& msg) const
{
  // is the vector still around?
  auto ret = wptr.lock();
  if(!ret)
    throw std::runtime_error("unbound StrBlobPtr");

  // check for out of range
  if(i >= ret->size())
    throw std::out_of_range(msg);

  // otherwise, return a shared_ptr to the vector
  return ret;
}

// dereference
inline const string& ConstStrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

// prefix: return a reference to the incremented object
inline ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
  // if curr already points past the end of the container, can't incr it.
  check(curr, "increment poast end of StrBlobPtr");
  ++curr; // advance the current state
  return *this;
}

#endif
