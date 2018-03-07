template<typename T> class Ref_handle{
public:
  // manage reference count as well as pointer
  Ref_handle():refptr(new size_t(1)), p(0){}
  Ref_handle(T* t):refptr(new size_t(1)), p(t){}
  Ref_handle(const Ref_handle& h):refptr(h.refptr),p(h.p)
  {
    // dereference and increment the ref count.
    // since we are attaching a handle to an existing object.
    ++*refptr;
  }

  Ref_handle& operator=(const Ref_handle&);
  ~Ref_handle();

  // as before
  operator bool() const{return p;}
  T& operator*() const
  {
    if(p)
      return *p;
    throw std::runtime_error("unbound Ref_handle");
  }

  T* operator->() const
  {
    if(p)
      return p;
    throw std::runtime_error("unbound Ref_handle");
  }

private
  T* p;
  // This is a reference to the reference count.
  size_t* refptr; // added
}; // class Ref_handle

// operatorassignstart //
// Equivalent switching this handle to point to a different object.
// First, we increment the pointer of the rhs. Since we will attach THIS 
// handle to the rhs.
//
// Next we need to think about detaching this handle from the object. 
// This is simply switching the two pointers T* p and size_t* refptr. But to
// so this, we have the first decrement the refptr of this handle. And if it
// is zero, we need to delete both the object and the ref count.
//
// Finally, doing the switching, we simply copy the pointers from the rhs
// over to refptr and p.
//
// Finally, we return this object, this is what we usually do.
template<typename>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
  // increment the ref counter, since we are attaching a handle to the rhs
  ++*rhs.refptr;

  // free the left-hand side, destroying pointers if appropriate
  if(--*refptr == 0){
    delete refptr; refptr=0; // delete and null
    delete p; p=0; // delete and null
  }

  // copy the values from the right-hand side
  refptr = rhs.refptr;
  p = rhs.p;

  return *this;
} // operatorassignend //


// RefHandleDestructorStart //
// Decrement the ref count,
//   if it is zero (i.e. this is the last handle pointing to the object)
//     then delete both the object and the pointer.
template<typename T> Ref_handle<T>::~Ref_handle()
{
  if(--*refptr == 0){
    delete refptr;
    delete p;
  }
} // RefHandleDestructorEnd //
