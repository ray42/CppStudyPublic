#ifndef HEADER_HANDLE_H
#define HEADER_HANDLE_H
#include<stdexcept>

#include<iostream>

// p355 Acpp:
// Properties of the Handle class:
// * A Handle is a value that refers to an object.
// * We can copy a Handle object.
// * We can test a Handle object to determine whether it is bound to another
//   object.
// * We can use a Handle to trigger polymorphic behaviour when it points to
//   an object of a class that belongs to an inheritance hierarchy. That is,
//   if we call a virtual function through our class, we want the 
//   implementation to choose the function to run dynamically, just as if 
//   we'd called the function through a real pointer.
//

template<typename T> class Handle
{
public:
  // Default constructor
  Handle():p(0)
  {
    std::cerr << "Handle::Handle()" << std::endl;
  }

  // Copy constructor
  Handle(const Handle& s):p(0)
  {
    // Note: if the clone in the object pointed to by p is
    // protected, then Handle must be a friend.
    // i.e. we have to put this:
    // template<typename T> friend class Handle;
    if(s.p)
    {
      p = s.p->clone();
    }
    std::cerr << "Handle copy constructor" << std::endl;
  }

  // Assignment operator
  Handle& operator=(const Handle&);

  // Destructor
  ~Handle(){delete p;}

  // constructor which takes a pointer of type T
  Handle(T *t):p(t){}

  // convert to bool? // wtf is this new format?
  // what is the return type, and what's the operator?
  //
  // From the book, p356: operator bool() lets users test the value of a 
  // Handle in a condition. The operation returns true if the Handle is
  // bound to an object, and false otherwise. This still doesn't explain
  // why we do not have a return type.
  operator bool() const
  {
    return p;
  }

  // Okay, these are the operator format I recognise. These give access to
  // the object bound to the Handle
  T& operator *() const;
  T* operator->() const;

  static bool compare_Core_handles(const Handle<Core>& h1,
                                   const Handle<Core>& h2);

private:
  T* p;

};


template<typename T> Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
  if(&rhs != this)
  {
    delete p;

    // Okay, this works by the conditional operator.
    // Recall that it's: expression?expression1:expression2
    // so, if rhs.p is 0, it goes to expression 2, otherwise, it'll do
    // expression1. Then, the whole thing is assigned to p.
    p = rhs.p?rhs.p->clone():0;
  }
  return *this;
}

// Okay, remember that function definitions goes like this:
// templates<typename T> return-type class-type::function-name modifier
//
// From book: Applying the built-in unary * operator to a pointer yields the
// object to which the pointer points. Here we define our own *, so that * 
// of a Handle object yields the value that results from applying the 
// built-in * operator to the pointer member of that Handle object.
//
// HOWEVER, applying * to a pointer to a Handle yields the Handle object.
//
// Given our student object: Handle<Core> student(new Grad);
// *student will yield the results of applying * to student.p (assuming we
// could access the p member).
//
// In other words, the result of *student will be a reference to the Grad 
// object that we created when we initialized students
template<typename T> T& Handle<T>::operator *() const
{
  if(p) return *p;

  throw std::runtime_error("unbound Handle");
}

template<typename T> T* Handle<T>::operator->() const
{
  if(p) return p;

  throw std::runtime_error("unbound Handle");
}

// TEST THIS // Note: Apparently I do not need the second static here.
// Just once in the 
template<typename T> bool Handle<T>::compare_Core_handles(
    const Handle<Core>& h1, const Handle<Core>& h2)
{
  return h1->name()<h2->name();
}


#endif

























