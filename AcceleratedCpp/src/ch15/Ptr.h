#ifndef HEADER_PTR_H
#define HEADER_PTR_H

#include<stdexcept>
#include<iostream>

// Global clone function
template <typename T> T * clone(const T* tp)
{
  return tp->clone();
}

// the key to making Ptr< Vec<char> > work
// template specailization
//template<>
//Vec<char>* clone(const Vec<char>* vp)
//{
//  return new Vec<char>(*vp);
//}

// ClassPtrStart //
template<typename T> class Ptr{
public:
  
  // new member to copy the object conditionally when needed:
  // if there is more than one handle attached to the object, we
  // detach this one an make a clone the object for this handle.
  // Note: This doesn't stop another handle from attaching to this object 
  // later on, and then it is no longer unique.
  void make_unique(){
    std::cerr << "Hi from: Ptr::make_unique()" << std::endl;
    if(*refptr != 1){
      --*refptr;
      refptr = new size_t(1);
      p=p? ::clone(p):0;
    }
  }

  // The rest of the class looks like Ref_handle except for its name

  // Default constructor
  Ptr(): refptr(new size_t(1)),p(0)
  {
    std::cerr << "Hi from: Ptr()" << std::endl;
  }
  
  // Pointer to T constructor
  Ptr(T* t): refptr(new size_t(1)), p(t)
  {
    std::cerr << "Hi from: Ptr(T*)" << std::endl;
  }
  
  // copy constructor
  Ptr(const Ptr& h):refptr(h.refptr),p(h.p)
  {
    std::cerr << "Hi from: Ptr(const Ptr&)" << std::endl;
    ++*refptr;
  }

  // Assignment operator declaration
  Ptr& operator=(const Ptr&); // Analogous to before

  // Destructor declaration
  ~Ptr(); // Analogous to before

  // bool declaration
  operator bool() const
  {
    std::cerr << "Hi from: bool()" << std::endl;
    return p;
  }

  // operator* declaration
  T& operator*() const; // Analogous to before

  // operator-> declaration
  T* operator->() const; // Analogous to before

  size_t ref_count() const
  {
    return *refptr;
  }

  T* get_ptr()
  {
    return p;
  }



private:

  T* p;// Pointer to the object
  size_t* refptr; // Pointer to the ref count
}; // ClassPtrEnd //

// OperatorAssignStart //
template<typename T> 
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
  std::cerr << "Hi from: Ptr<T>::operator=()" << std::endl;

  // increment the ref counter. It is important to increment the rhs refptr
  // before we decrement this one, since they may point to the same refptr.
  ++*rhs.refptr;

  // free the lhs, destroying pointers if appropriate
  if(--*refptr == 0){
    delete refptr; refptr = 0; // delete and null
    delete p; p=0; // delete and null
  }

  // copy the value from the rhs
  refptr = rhs.refptr;
  p = rhs.p;

  return *this;
} // OperatorAssignEnd //

// DestructorStart //
// Decrement the ref count,
//   if it is zero (i.e. this is the last handle pointing to the object)
//     then delete both the object and the pointer.
template<typename T> Ptr<T>::~Ptr()
{
  std::cerr << "Hi from: Ptr<T>::~Ptr()" << std::endl;
  
  if(--*refptr == 0){
    delete refptr;
    delete p;
  }
} // DestructorEnd //


// DereferenceStart //
template<typename T> T& Ptr<T>::operator*() const
{
  std::cerr << "Hi from: Ptr<T>::operator*()" << std::endl;

  if(p)
    return *p;
  throw std::runtime_error("unbound Ptr");
} // DereferenceEnd //

// ArrowStart //
template<typename T> T* Ptr<T>::operator->() const
{
  std::cerr << "Hi from: Ptr<T>::operator->()" << std::endl;
  
  if(p)
    return p;
  throw std::runtime_error("unbound Ptr");
} // ArrowEnd //
#endif
