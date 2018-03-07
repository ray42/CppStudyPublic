/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef BLOB_H
#define BLOB_H

#include"./../common/rr.h"

#include<memory> // shared_ptr, make_shared
#include<initializer_list> // initializer_list
#include<vector> // vector
#include<iostream> // ostream
#include<algorithm> // transform, lexicographical_compare
#include<iterator>

// Forward declarations, needed for friend declaration in BlobPtr.
template<typename> class BlobPtr;
//template<typename> class ConstBlobPtr;

// Needed for operator forward declarations
template<typename> class Blob;

/*==========================================================================
 * Provides interface to a shared_ptr<vector<T>>.
 * Can be treated as a custom vector<T>
 *==========================================================================
 */

// same with these functions.
template<typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template<typename T> class Blob
{
  // friend declarations
  friend class BlobPtr<T>; // instantiate with T
//  friend class ConstBlobPtr<T>;
  friend bool operator== <T>(const Blob<T>&, const Blob<T>&);
  friend bool operator!= <T>(const Blob<T>&, const Blob<T>&);
  friend bool operator<  <T>(const Blob<T>&, const Blob<T>&);
  friend bool operator>  <T>(const Blob<T>&, const Blob<T>&);
  friend bool operator<= <T>(const Blob<T>&, const Blob<T>&);
  friend bool operator>= <T>(const Blob<T>&, const Blob<T>&);

public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  //////////////////////////////////////////////////////////////////////////
  // constructors and copy control

  // default constructor
  Blob();

  // braced list constructor
  Blob(std::initializer_list<T>il);

  // copy constructor - valuelike behaviour, so that this data_spt
  // does NOT point to the same object as in sb.
  Blob(const Blob<T> &b);

  // copy assignment operator
  Blob<T>& operator=(const Blob<T>& rhs);

  // move constructor
  Blob(Blob<T>&& b) noexcept;

  // move assignment constructor
  Blob<T>& operator=(Blob<T>&& rhs) noexcept;

  // destructor
  ~Blob() = default;


  //////////////////////////////////////////////////////////////////////////
  // number of elements in the Blob
  size_type size() const {return data_spt->size();}
  bool empty() const {return data_spt->empty();}

  //////////////////////////////////////////////////////////////////////////
  // add and remove elements
  void push_back(const T &t){data_spt->push_back(t);}
  // move version
  void push_back(T &&t){data_spt->push_back(std::move(t));}

  void pop_back();

  //////////////////////////////////////////////////////////////////////////
  // element access

  // access element at the front
  T& front(); // TODO
  const T& front() const; // TODO
  
  // access element at the back
  T& back(); // TODO
  const T& back() const; // TODO

  // subscript operator
  T& operator[](size_type i); // TODO
  const T& operator[](size_type i) const; //TODO

  //////////////////////////////////////////////////////////////////////////
  //interface to BlobPtr and ConstBlobPtr
  BlobPtr<T> begin(); // can't be defined until BlobPtr is.
  BlobPtr<T> end(); // can't be defined until BlobPtr is.
//  ConstBlobPtr<T> cbegin(); // can't be defined until ConstBlobPtr is.
//  ConstBlobPtr<T> cend(); // can't be defined until ConstBlobPtr is.

  //////////////////////////////////////////////////////////////////////////
  //debugging
  std::ostream& printall(std::ostream& os=std::cout) const
  {
    os << "emp " << empty() << ", size " << size() << ": ";
    std::transform(data_spt->begin(),data_spt->end(),
                   std::ostream_iterator<T>(os," "),
                   [](const T& t)->T
                   {return t;});
    return os;
  }


private:
  //////////////////////////////////////////////////////////////////////////
  //private data members

  // underlying data structure
  std::shared_ptr<std::vector<T>> data_spt;

  //////////////////////////////////////////////////////////////////////////
  //private function members

  // throws msg if data_spt[i] if i is not in [0,size)
  void check(size_type i, const std::string& msg) const; // TODO done
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// member functions

////////////////////////////////////////////////////////////////////////////
// constructors and copy control

// default constructor
template<typename T>
Blob<T>::Blob():data_spt(std::make_shared<std::vector<T>>())
{rr::greet(__PRETTY_FUNCTION__, this);}

// braced list constructor
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il):
  data_spt(std::make_shared<std::vector<T>>(il))
{rr::greet(__PRETTY_FUNCTION__, this);}

// copy constructor - value-like behaviour, so that this data_spt
// does NOT point to the same object as in b.
template<typename T>
Blob<T>::Blob(const Blob<T>& b):
  data_spt(std::make_shared<std::vector<T>>(*b.data_spt))
{rr::greet(__PRETTY_FUNCTION__, this);}

// copy assignment operator
template<typename T>
Blob<T>& Blob<T>::operator=(const Blob<T>& rhs)
{
  rr::greet(__PRETTY_FUNCTION__, this);
  data_spt = std::make_shared<std::vector<T>>(*rhs.data_spt);
  return *this;
}

// move constructor
template<typename T>
Blob<T>::Blob(Blob<T> &&b) noexcept:
data_spt(std::move(b.data_spt))
{
  rr::greet(__PRETTY_FUNCTION__, this);
  b.data_spt = nullptr;
}

// move assignment operator
template<typename T>
Blob<T>& Blob<T>::operator=(Blob<T> &&rhs) noexcept
{
  rr::greet(__PRETTY_FUNCTION__, this);
  if(this != &rhs)
  {
    data_spt = std::move(rhs.data_spt);
    rhs.data_spt = nullptr;
  }
  return *this;
}


////////////////////////////////////////////////////////////////////////////
// add and remove elements

// first we define the private member function
template<typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
  if(i >= data_spt->size())
    throw std::out_of_range(msg);
}

template<typename T>
void Blob<T>::pop_back()
{
  check(0,"pop_back on empty Blob");
  data_spt->pop_back();
}

////////////////////////////////////////////////////////////////////////////
// element access


// access element at the front
template<typename T>
T& Blob<T>::front()
{
  check(0,"front on empty Blob");
  return data_spt->front();
}
template<typename T>
const T& Blob<T>::front() const
{
  check(0,"front on empty Blob");
  return data_spt->front();
}

// access the element at the back
template<typename T>
T& Blob<T>::back()
{
  check(0,"back on empty Blob");
  return data_spt->back();
}
template<typename T>
const T& Blob<T>::back() const
{
  check(0,"back on empty Blob");
  return data_spt->back();
}

// subscript operator
template<typename T>
T& Blob<T>::operator[](size_type i)
{
  // if i is too big, check will throw, preventing access to nonexistent 
  // element
  check(i,"subscript out of range");
  return (*data_spt)[i];
}
template<typename T>
const T& Blob<T>::operator[](size_type i) const
{
  // if i is too big, check will throw, preventing access to nonexistent 
  // element
  check(i,"subscript out of range");
  return (*data_spt)[i];
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// Blob's friends
template<typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
  return *lhs.data_spt == *rhs.data_spt;
}


template<typename T> bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs)
{
  return !(lhs == rhs);
}

template<typename T> bool operator< (const Blob<T>& lhs, const Blob<T>& rhs)
{
  return std::lexicographical_compare(
      lhs.data_spt->cbegin(),lhs.data_spt->cend(),
      rhs.data_spt->cbegin(),rhs.data_spt->cend());
}

template<typename T> bool operator> (const Blob<T>& lhs, const Blob<T>& rhs)
{
  // lhs>rhs == rhs<lhs
  return rhs < lhs;
}

template<typename T> bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs)
{
  // lhs<=rhs == !(lhs>rhs) == !(rhs<lhs)
  return !(rhs < lhs);
}

template<typename T> bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs)
{
  // lhs>=rhs == !(lhs<rhs)
  return !(lhs < rhs);
}


/*==========================================================================
 * BlobPtr - custom iterator for StrBlob
 * BlobPtr throws an exception on attempts to access a nonexistent element
 *==========================================================================
 */

// forward declarations needed for friendship
// Note: These assume that the iterators are pointing to the same underlying
// array. Otherwise the behaviour is undefined.
template<typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T> class BlobPtr
{
  //////////////////////////////////////////////////////////////////////////
  // friend declarations
  friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&); // done
  friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&); // done
  friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&); // done
  friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&); // done
  friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&); // done
  friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&); // done

public:
  //////////////////////////////////////////////////////////////////////////
  //constructors
  BlobPtr():wptr(std::weak_ptr<std::vector<T>>()),curr(0)
  { /* empty */}
  BlobPtr(Blob<T>& a, size_t pos = 0):
    wptr(a.data_spt),curr(pos)
  { /* empty */}

  //////////////////////////////////////////////////////////////////////////
  //subscript operators
  //this is the absolute position, i.e. the position is not related to curr.
  //even if curr is at the last element, blobptr[0] will always fetch the 
  //first element
  T& operator[](size_t); // TODO done
  const T& operator[](size_t) const; // TODO done

  //////////////////////////////////////////////////////////////////////////
  // some more functions

  // dereference
  T& deref() const; // TODO done

  // prefix increment
  BlobPtr& incr(); // TODO done

  //////////////////////////////////////////////////////////////////////////
  // rest of the operators
  
  // dereference - we will return a reference to the T currently pointed to 
  // by curr.
  T& operator*() const; // TODO done

  // We will return a pointer to the underlying T pointed to by curr.
  // That way, we can access all the T member functions.
  // Recall that when we call sbpt->mem, we are actually calling
  // sbpt.operator->()->mem, so if we return a pointer, we are calling ->mem
  // on a pointer.
  //
  // We can only return a reference to a class if that class implements the
  // operator->(), which allows for chaining until we finally get a pointer
  // where we can fetch the member mem.
  T* operator->() const; // TODO done

  // increment and decrement
  BlobPtr& operator++(); // prefix operators // TODO
  BlobPtr& operator--(); // TODO done
  BlobPtr operator++(int); // TODO done
  BlobPtr operator--(int); // TODO done
  BlobPtr& operator+=(size_t); // TODO  done
  BlobPtr& operator-=(size_t); // TODO  done
  BlobPtr operator+(size_t); // TODO  done
  BlobPtr operator-(size_t); // TODO  done


private:
  // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string&) const; // done
  
  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<T>>wptr;
  std::size_t curr; // current position within the array
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// BlobPtr's member functions

// check - private member, returns a shared_ptr to the vector if the check
// succeeds
template<typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
  // is the pointer still around?
  auto ret = wptr.lock();
  // if ret is null, then conditions will be false. We check if it is null
  // by negating it.
  if(!ret)
  {
    throw std::runtime_error("unbound wptr");
  }

  // Now check for out of range.
  if(i>=ret->size())
    throw std::out_of_range(msg);

  return ret;
}


// subscript operators
template<typename T>
T& BlobPtr<T>::operator[](size_t i)
{
  auto p = check(i, "operator[] out of range");
  return (*p)[i];
}
template<typename T>
const T& BlobPtr<T>::operator[](size_t i) const
{
  auto p = check(i, "operator[] out of range");
  return (*p)[i];
}

// some more functions
template<typename T>
T& BlobPtr<T>::deref() const
{
  auto p = check(curr,"deref out of range");
  return (*p)[curr];
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::incr()
{
  // if curr already points past the end of the container, cannot increment.
  check(curr,"incr beyond past end of container");
  ++curr;
  return *this;
}

template<typename T>
T& BlobPtr<T>::operator*() const
{
  auto p=check(curr,"op* out of range");
  return (*p)[curr];
}

template<typename T>
T* BlobPtr<T>::operator->() const
{
  // this works because we want to return a pointer to the string
  // curr is pointing at.
  return &this->operator*();
}

////////////////////////////////////////////////////////////////////////////
// BlobPtr's operators
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
  // check if we can increment it.

  // check if curr is in the range [0,size), if it's less than size, we can
  // still increment it, since if it's currently size-1, incrementing it 
  // will still be okay (although we cannot dereference it, it'll cause
  // undefined behaviour), i.e. we cannot get arr[size], since it'll be the
  // off-the-end iterator.
  //
  // if curr already points past the end of the container, can't increment 
  // it.
  check(curr, "op++ past end of BlobPtr");
  ++curr;
  return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
  // we check if curr is zero by decrementing it and passing that value to
  // check(). If it is zero, then decrementing the (unsigned) curr will make
  // it very large.
  //
  // if curr is zero, decrementing it will yield an invalid subscript
  --curr;
  check(curr, "op-- past begin end of BlobPtr");
  return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
  // save current state
  BlobPtr<T> tmp = *this;
  // do the increment
  ++*this;
  return tmp;
}
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
  BlobPtr<T> tmp = *this;
  --*this;
  return tmp;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
  curr+=n;
  check(curr,"op+= out of range");
  return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
  curr-=n;
  check(curr, "op-= out of range");
  return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator+(size_t n)
{
  BlobPtr<T> sum = *this;
  sum += n;
  return sum;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator-(size_t n)
{
  BlobPtr<T> sum = *this;
  sum -= n;
  return sum;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// BlobPtr's friend functions
template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  return lhs.curr == rhs.curr;
}
template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  return !(lhs==rhs);
}

template<typename T>
bool operator< (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
  return lhs.curr < rhs.curr;
}

template<typename T>
bool operator> (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  // lhs>rhs == rhs<lhs
  return rhs<lhs;
}

template<typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  // l<=r == !(l>r) == !(r<l)
  return !(rhs<lhs);
}

template<typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  // l>=r == !(l<r)
  return !(lhs<rhs);
}






////////////////////////////////////////////////////////////////////////////
//Finally we define the functions which we could not define before.
//
template<typename T>
BlobPtr<T> Blob<T>::begin()
{
  return BlobPtr<T>(*this,0);
}
template<typename T>
BlobPtr<T> Blob<T>::end()
{
  return BlobPtr<T>(*this,size());
}








#endif


