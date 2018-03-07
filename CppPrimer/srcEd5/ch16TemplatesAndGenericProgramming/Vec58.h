#ifndef STRVEC_H
#define STRVEC_H
#include"./../common/rr.h"
#include<cstddef> // size_t
#include<utility> // pair
#include<memory>  // allocator
#include<iostream>
#include<initializer_list>
#include<algorithm>
#include<iterator>

template<typename> class Vec;

// forward declaration for friends
template<typename T> bool operator==(const Vec<T>&,const Vec<T>&);
template<typename T> bool operator!=(const Vec<T>&,const Vec<T>&);
template<typename T> bool operator<(const Vec<T>&,const Vec<T>&);
template<typename T> bool operator>(const Vec<T>&,const Vec<T>&);
template<typename T> bool operator<=(const Vec<T>&,const Vec<T>&);
template<typename T> bool operator>=(const Vec<T>&,const Vec<T>&);

// simplified implementation of the memory allocation strategy for 
// vector-like class
template<typename T>
class Vec
{
  friend bool operator==<T>(const Vec<T>&, const Vec<T>&);
  friend bool operator!=<T>(const Vec<T>&, const Vec<T>&);
  friend bool operator< <T>(const Vec<T>&, const Vec<T>&);
  friend bool operator> <T>(const Vec<T>&, const Vec<T>&);
  friend bool operator<= <T>(const Vec<T>&, const Vec<T>&);
  friend bool operator>= <T>(const Vec<T>&, const Vec<T>&);

public:
  
  Vec(): // the allocator member is default initialized
    elements(nullptr),first_free(nullptr),cap(nullptr)
  {
    rr::greet(__PRETTY_FUNCTION__,this);
  }

  // constructor which takes an initializer list so we can use brace list.
  Vec(std::initializer_list<T>);

  Vec(const Vec&);           // copy constructor
  Vec &operator=(const Vec&);// copy assignment
  ~Vec();                       // destructor    

  // Move constructor!!!!
  Vec(Vec &&s) noexcept; // move won't throw any exceptions

  // Move assignment operator!
  Vec& operator=(Vec &&rhs) noexcept;

  //////////////////////////////////////////////////////////////////////////
  // Other operators ///////////////////////////////////////////////////////

  // initializer_list assignment operator.
  Vec& operator=(std::initializer_list<T> il);

  // exer26: subscript operator
  T& operator[](size_t n);
  // const version
  const T& operator[](size_t n) const;


  template<typename... Args>
  void emplace_back(Args&&...);

  //////////////////////////////////////////////////////////////////////////
  // Methods ///////////////////////////////////////////////////////////////
  void push_back(const T&); // copy the element

  // the total number of elements (constructed space)
  size_t size() const { return first_free - elements; }

  // total space allocated
  size_t capacity() const {return cap-elements;}

  // return a copy of the pointer to the first element
  T * begin() const {return elements;}

  // return a copy of the pointer to the first element (const)
  const T * cbegin() const {return elements;}

  // return a copy of the pointer to one past the last element
  T *end() const {return first_free;}

  // return a copy of the pointer to one past the last element (const)
  const T *cend() const {return first_free;}

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
  void resize (const size_t n, const T& val = T());
  
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
  void reserve (size_t n);

  std::ostream& printall(std::ostream& os = std::cout) const;

  // ...
private:
  static std::allocator<T> alloc; // allocates the elements

  // used by the functions that add elements to the Vec<T>
  void chk_n_alloc()
  {
    if(size() == capacity())
      reallocate();
  }

  // utilities used by the copy constructor, assignment operator, 
  // and destructor
  std::pair<T*, T*> alloc_n_copy(const T*, const T*);

  void free();          // destroy the elements and free the space
  void reallocate();    // get more space and copy the existing elements

  T *elements;  // pointer to the first element in the array
  T *first_free;// pointer to the first free element in the array
  T *cap;       // pointer to one past the end of the array
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// data member initialization
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
template<typename T> std::allocator<T> Vec<T>::alloc;


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// alloc_n_copy(), free() and  reallocate() members. These are used
// everywhere:
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// Allocates just enough space for e-b elements.
// returns a pair to the first and one past the last element.
template<typename T>
std::pair<T*,T*> Vec<T>::alloc_n_copy(const T *b, const T* e)
{
  // allocate space to hold as many elements as are in the range
  auto data = alloc.allocate(e-b);
  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
  return {data,uninitialized_copy(b,e,data)};
}

// Destroys all elements in THIS Vec<T>
// deallocate the space taken by this Vec<T>
template<typename T>
void Vec<T>::free()
{
  // may not pass deallocate a 0 pointer; 
  // if elements is 0, there's no work to do
  if(elements)
  {
//    // destroy the old elements in reverse order
//    for(auto p = first_free; p!=elements; /* empty */)
//      alloc.destroy(--p);
    
    // Ex43 - using foreach
    std::for_each(elements,first_free,
                  [](T &t)
                  {
                    alloc.destroy(&t);
                  });

    alloc.deallocate(elements,cap-elements);
  }
}

// allocates new mem to be 2* current size()
// copies current elements into the new space
// free old space
// resets the points to the new space.
template<typename T>
void Vec<T>::reallocate()
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

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// constructors and copy control: 
// copy c-tor, copy assign op, move c-tor, move assign op, destructor
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// Initializiser list constructor
template<typename T>
Vec<T>::Vec(std::initializer_list<T>lst):
  elements(nullptr),first_free(nullptr),cap(nullptr)
{
  auto newdata = alloc_n_copy(lst.begin(),lst.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

// copy constructor
template<typename T>
Vec<T>::Vec(const Vec<T>& v):
  elements(nullptr), first_free(nullptr), cap(nullptr)
{
  rr::greet(__PRETTY_FUNCTION__,this);

  auto newdata = alloc_n_copy(v.begin(),v.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

// copy assignment operator
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
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

// Move constructor!!!!
template<typename T>
Vec<T>::Vec(Vec<T> &&s) noexcept // move won't throw any exceptions
  : elements(std::move(s.elements)), 
  first_free(std::move(s.first_free)), cap(std::move(s.cap))
{
  // leave s in a state in which it is safe to run the destructor
  s.elements = s.first_free = s.cap = nullptr;
}

// move assignment operator
template<typename T>
Vec<T>& Vec<T>::operator=(Vec<T> &&rhs) noexcept
{
  // direct test for self-assignment
  if(this!=&rhs)
  {
    free(); // free existing elements
    elements = std::move(rhs.elements);
    first_free = std::move(rhs.first_free);
    cap = std::move(rhs.cap);

    // leave rhs in a destructible  state
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }

  return *this;
}

// Destructor
template<typename T>
Vec<T>::~Vec()
{
  rr::greet(__PRETTY_FUNCTION__,this);
  free();
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// Other operators
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template<typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T>il)
{
  // free
  free();
  auto newdata = alloc_n_copy(il.begin(),il.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

template<typename T>
T& Vec<T>::operator[](size_t n)
{
  return elements[n];
}

template<typename T>
const T& Vec<T>::operator[](size_t n) const
{
  return elements[n];
}


template<typename T>
template<typename... Args>
void Vec<T>::emplace_back(Args&&... args)
{
  chk_n_alloc(); // ensure that there is room for another element
  alloc.construct(first_free++, std::forward<Args>(args)...);
}

////////////////////////////////////////////////////////////////////////////
template<typename T>
void Vec<T>::push_back(const T& s)
{
  chk_n_alloc(); // ensure that there is room for another element
  // construct a copy of s in the element to which first_free points
  alloc.construct(first_free++,s);
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
template<typename T>
void Vec<T>::reserve(size_t n)
{
  if(n>capacity())
  {
    size_t newcapacity = n;

    // allocate new memory
    T* newdata = alloc.allocate(newcapacity);

    // move the data from the old memory to the new:
    T* dest = newdata; //points to the next free position in the new array
    T* elem = elements;//points to the next element in the old array

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
template<typename T>
void Vec<T>::resize(const size_t n, const T& val)
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



////////////////////////////////////////////////////////////////////////////
//debug, printall
template<typename T> 
std::ostream& Vec<T>::printall(std::ostream& os) const
{
  os << "p: "<< this
       << ", size: " << size() << ", capacity: " << capacity() << std::endl;
  os << "contents: ";
  std::copy(begin(),end(),std::ostream_iterator<T>(os," "));

  return os;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// Equality and relationals.
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template<typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs)
{
  return std::equal(lhs.cbegin(),lhs.cend(),rhs.cbegin());
}

template<typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs)
{
  return !(lhs == rhs);
}

template<typename T>
bool operator<(const Vec<T>&lhs, const Vec<T>&rhs)
{
  return std::lexicographical_compare(lhs.cbegin(),lhs.cend(),
                                      rhs.cbegin(),rhs.cend());
}

template<typename T>
bool operator>(const Vec<T>& lhs, const Vec<T>& rhs)
{
  return rhs < lhs;
}

template<typename T>
bool operator<=(const Vec<T>&lhs, const Vec<T>&rhs)
{
  // lhs <= rhs == !(lhs>rhs) == !(rhs<lhs)
  return !(rhs<lhs);
}

template<typename T>
bool operator>=(const Vec<T>&lhs, const Vec<T>&rhs)
{
  // lhs >= rhs == !(lhs<rhs)
  return !(lhs<rhs);
}







#endif
