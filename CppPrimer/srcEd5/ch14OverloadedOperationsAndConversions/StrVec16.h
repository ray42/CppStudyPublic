#ifndef STRVEC_H
#define STRVEC_H

#include<string>
#include<cstddef> // size_t
#include<utility> // pair
#include<memory> // allocator
#include<iostream>
#include<initializer_list>

// simplified implementation of the memory allocation strategy for 
// vector-like class
class StrVec
{
  friend bool operator==(const StrVec&, const StrVec&);
  friend bool operator!=(const StrVec&, const StrVec&);

public:
  static bool raydebug;
  
  StrVec(): // the allocator member is default initialized
    elements(nullptr),first_free(nullptr),cap(nullptr)
  {
    if(raydebug)
    {
      std::cout<<"Hi: "<<this<<", "<< __PRETTY_FUNCTION__ << std::endl;
    }
  }

  // constructor which takes an initializer list so we can use brace list.
  StrVec(std::initializer_list<std::string>);

  StrVec(const StrVec&);           // copy constructor
  StrVec &operator=(const StrVec&);// copy assignment
  ~StrVec();                       // destructor

  // Move constructor!!!!
  StrVec(StrVec &&s) noexcept; // move won't throw any exceptions

  // Move assignment operator!
  StrVec& operator=(StrVec &&rhs) noexcept;

  void push_back(const std::string&); // copy the element

  // the total number of elements (constructed space)
  size_t size() const { return first_free - elements; }

  // total space allocated
  size_t capacity() const {return cap-elements;}

  // return a copy of the pointer to the first element
  std::string *begin() const {return elements;}

  // return a copy of the pointer to the first element (const)
  const std::string *cbegin() const {return elements;}

  // return a copy of the pointer to one past the last element
  std::string *end() const {return first_free;}

  // return a copy of the pointer to one past the last element (const)
  const std::string *cend() const {return first_free;}

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
  void resize (const size_t n, const std::string& val = std::string());
  
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

  std::ostream& printall(std::ostream& os = std::cout);

  // ...
private:
  static std::allocator<std::string> alloc; // allocates the elements

  // used by the functions that add elements to the StrVec
  void chk_n_alloc()
  {
    if(size() == capacity())
      reallocate();
  }

  // utilities used by the copy constructor, assignment operator, 
  // and destructor
  std::pair<std::string*, std::string*> alloc_n_copy
    (const std::string*, const std::string*);

  void free();          // destroy the elements and free the space
  void reallocate();    // get more space and copy the existing elements

  std::string *elements;  // pointer to the first element in the array
  std::string *first_free;// pointer to the first free element in the array
  std::string *cap;       // pointer to one past the end of the array
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);

#endif
