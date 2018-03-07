/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<exception>
using std::exception;

#include<vector>
using std::vector;
#include<fstream>
using std::ifstream;
#include<stdexcept>
using std::range_error;
#include<memory>
using std::shared_ptr;
using std::unique_ptr;
using std::default_delete;

struct intArray{

  intArray():sz(0),p(nullptr){}

  explicit intArray(size_t s):sz(s),p(new int[s])
  {}

  ~intArray()
  {
    delete[] p;
  }

  // data member
  size_t sz;
  int *p;
};

////////////////////////////////////////////////////////////////////////////
// Approach 1, use own class.
void exercise_useintArray(int *b, int *e)
{
  vector<int> v(b,e);
  intArray ip(v.size());

  ifstream in("ints");
  // exception occurs here
  if(ip.p)
    throw range_error("OMG a range error exception!");
}

////////////////////////////////////////////////////////////////////////////
// Approach 2, use shared_ptr and unique_ptr
template<typename T>
struct array_deleter
{
  void operator()(T const*p)
  {
    delete[] p;
  }
};

void exercise_use_shared_ptr(int *b, int*e)
{
  vector<int> v(b,e);

  // old version
//  int *p = new int[v.size()];
  
  // using shared_ptr with custom deleter
  shared_ptr<int> sp1(new int[v.size()],array_deleter<int>());

  // use shared_ptr with default_delete
  shared_ptr<int> sp2(new int[v.size()], default_delete<int[]>());

  // use shared_ptr with lambda
  shared_ptr<int> sp3(new int[v.size()], [](int * p)
                                         {
                                           delete[] p;
                                         });

  // use unique_ptr
  // Unless you actually need to share the managed object, a unique_ptr is 
  // better suited for this task, since it has a partial specialization for 
  // array types.
  unique_ptr<int[]> up(new int[v.size()]); // this will correctly call delete[]

  ifstream in("ints");

//  // exception occurs here
//  if(p)
//    throw range_error("OMG a range error exception!");
}


void exercise(int *b, int *e)
{
  vector<int> v(b,e);
  int *p = new int[v.size()];
  ifstream in("ints");
  // exception occurs here
  if(p)
    throw range_error("OMG a range error exception!");
}

int main()
{
  int arr[6] = {0,1,2,3,4,5};
  exercise(&arr[0],&arr[5]);

  // testing what happens if I throw a pointer.
//  try{
//    exception *p = new exception();
//    if(1)
//      throw p;
//  }catch(exception *e)
//  {
//    cout << "Hello" << endl;
//
//  }
  return 0;
}

