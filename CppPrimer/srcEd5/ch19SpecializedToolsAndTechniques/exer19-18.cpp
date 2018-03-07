/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<functional>
using std::function;
using std::mem_fn;
using std::placeholders::_1;
#include<algorithm>
using std::count_if;
#include<iterator>
using std::ostream_iterator;

// Write a function that uses count_if to count how many empty
// strings there are in a given vector.

// I will use function, mem_fn and bind.


void countemptystrings()
{
  vector<string> svecobj{"x","","x","","x","","x"};
  vector<string*> svecpt{new string("x"),new string(""),new string("x"),
                         new string(""),new string("x"),new string(""),
                         new string("x")};

  // first check
  size_t obj0 = count_if(svecobj.begin(),svecobj.end(),
                       [](const string& s)->bool
                         {
                         return s.empty();
                         });

  size_t pt0 = count_if(svecpt.begin(),svecpt.end(),
                         [](const string * sp)->bool
                         {
                           return sp->empty();
                         });
  cout << "obj0: " << obj0 << endl;
  cout << "pt0 : " << pt0 << endl;

  //////////////////////
  // with function.
  function<bool (const string)> fcn_obj = &string::empty;
  size_t obj1 = count_if(svecobj.begin(),svecobj.end(),fcn_obj);
  cout << "obj1: " << obj1 << endl;
  
  function<bool (const string*)> fcn_pt = &string::empty;
  size_t pt1 = count_if(svecpt.begin(),svecpt.end(),fcn_pt);
  cout << "pt1: " << pt1 << endl;

  //////////////////////
  //with mem_fn
  size_t obj2 = count_if(svecobj.begin(),svecobj.end(),
                         mem_fn(&string::empty));
  cout << "obj2: " << obj2 << endl;
  size_t pt2 = count_if(svecpt.begin(),svecpt.end(),mem_fn(&string::empty));
  cout << "pt2: " << pt2 << endl;

  /////////////////////
  // finally, with bind
//  auto bindfn = bind(&string::empty,_1);
  size_t obj3 = count_if(svecobj.begin(),svecobj.end(),
                         bind(&string::empty,_1));
  size_t pt3 = count_if(svecpt.begin(),svecpt.end(),
                        bind(&string::empty,_1));
  
  cout << "obj3: " << obj3 << endl;
  cout << "pt3: " << pt3 << endl;

  // for practice
  std::copy(svecobj.begin(),svecobj.end(),
            ostream_iterator<string>(cout," "));
  cout << endl;

}


int main()
{
  countemptystrings();
  return 0;
}

