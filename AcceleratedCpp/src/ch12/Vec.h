#ifndef GUARD_VEC_H
#define GUARD_VEC_H

#include<iostream>
#include<memory> // std::allocator unintialized_copy uninitialized_fill
#include<cstddef> // std::ptrdiff_t
#include<algorithm> // std::max



template<class T> class Vec
{
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec()
    {
      // when we return from create(), we intend for both data and limit to 
      // be set to zero.
      create();
    }

    explicit Vec(size_type n, const T& t = T()) 
    {
      create(n,t);
    }

    // copy constructor, note that this is called when we use = to 
    // initialise. This is different from the assignment operator=
    Vec (const Vec& v)
    {
      create(v.begin(),v.end());
    }

    // assignment
    Vec& operator=(const Vec&);

    // destructor
    ~Vec()
    {
      uncreate();
    }

    // return a non-const reference
    T& operator[] (size_type i)
    {
      return data[i];
    }

    // return a const reference
    const T& operator[](size_type i) const
    {
      return data[i];
    }

    void push_back(const T& val)
    {
      if(avail == limit) // get space if needed
      {
        grow();
      }
      unchecked_append(val); // append the new element
    }

    size_type size() const
    {
      // subtracting two pointers yields the number of elements apart the 
      // locations are to which the pointers refer (a value of type 
      // ptrdiff_t). Returning that value from the size function converts it
      // to size_type, the functions return type, which is a synonym for
      // size_t.
      return avail - data;
    }


    // functions to return iterators
    iterator begin() 
    {
      return data;
    }
    
    const_iterator begin() const
    {
      return data;
    }

    iterator end()
    {
      return avail;
    }

    const_iterator end() const
    {
      return avail;
    }

    // Removes from the Vec a single element at position and reduces the
    // container size by one. The removed element is destroyed.
    // Return: An iterator pointing to the new location of the element that
    // followed the last element erased by the function call. This is the
    // container end if the operation erased the last element in the 
    // sequence.
    iterator erase(iterator position)
    {
      // empty Vec
      if((position == avail) || this->size() == 0)
      {
        return position;
      }
      else
      {
        return erase(position,position+1);
      }
    }

    // Removes from Vec the elements in the range [first,last) and reduces
    // the container size by the number of elements removed, which are
    // destroyed.
    // Return: An iterator pointing to the new location of the element that
    // followed the last element erased by the function call. This is the
    // container end if the operation erased the last element in the 
    // sequence.
    iterator erase(iterator first, iterator last)
    {
      if(this->size() == 0)
      {
        return data;
      }
      else
      {
        std::ptrdiff_t pos_diff = first - data;

        iterator new_data = alloc.allocate(this->size()-1);
        
        iterator new_avail
          = std::uninitialized_copy(data,first,new_data);
        iterator new_avail2
          = std::uninitialized_copy(last,avail,new_avail);

        // return the old space
        uncreate();

        data = new_data;
        avail = new_avail2;
        size_type newsize = avail-data;
        limit = data+newsize;

        return data+pos_diff;
      }
    }

    void clear()
    {
      uncreate();
    }

  private:
    iterator data; // first element in the Vec
    iterator avail; // pointer to (one past) the last constructed element
    iterator limit; // points to (one past) the last available element

    // facilities for memory allocation
    std::allocator<T> alloc; // object to handle memory allocation

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator,const_iterator);

    // destroy the elements in the array and fee the memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T&);


};




template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
  // check for self-assignment
  if(&rhs != this)
  {
    // free the array in the left-hand side
    uncreate();

    // copy elements from the right-hand to the left-hand side
    create(rhs.begin(),rhs.end());
  }

  return *this;
}


template<class T> void Vec<T>::create()
{
  data = avail = limit = 0;
}

template<class T> void Vec<T>::create(size_type n, const T&val)
{
  data = alloc.allocate(n);
  limit = avail = data+n;
  std::uninitialized_fill(data,limit,val);
}

template<class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
  data = alloc.allocate(j-i);
  limit = avail = std::uninitialized_copy(i,j,data);
}

template<class T> void Vec<T>::uncreate()
{
  if(data)
  {
    // destroy (in reverse order) the elements that were constructed
    iterator it = avail;
    while(it!=data)
    {
      alloc.destroy(--it);
    }

    // return all the space that was allocated
    alloc.deallocate(data,limit-data);
  }
  // reset pointers to indicate that the Vec is empty
  data = limit = avail = 0;
}

template <class T> void Vec<T>::grow()
{
  // when growing, allocate twice as much space as currently in use.
  // Vec might currently be empty, so we cater for this possibility by
  // allocating the max of one element and twice the existing space. Recall 
  // that max must have exactly the same type, we explicitly construct an
  // object with value 1 of type ptrdiff_t, which we know is the type of
  // limit - data.
  size_type new_size = std::max(2*(limit - data),std::ptrdiff_t(1));
  
  // allocate new space and copy existing elements to the new space
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = std::uninitialized_copy(data,avail,new_data);

  // return the old space
  uncreate();

  // reset pointers to point to the newly allocated space
  data = new_data;
  avail = new_avail;
  limit = data+new_size;
}


// assumes avail points to allocated, but uninitialized space
template<class T> void Vec<T>::unchecked_append(const T& val)
{
  alloc.construct(avail++,val);
}

































#endif



















