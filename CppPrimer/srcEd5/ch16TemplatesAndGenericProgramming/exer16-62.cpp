/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */

#include<iostream>
using std::cout; using std::endl;



// open the std namespace so we can specialize std::hash 
namespace std {

template<> // we're defining a specialization
struct hash<Sales_data> // the template parameter of Sales_data
{
  // the type used to hash an unordered container must define these types
  typedef size_t result_type;
  typedef Sales_data argument_type; // by default this type needs ==
  
  size_t operator()(const Sales_data&s)const;
  //  our class ues synthesized copy control and default constrcutor
}

size_t hash<Sales_data>::operator()(const Sales_data& s)const
{
  return hash<string>()(s.bookNo)^
         hash<unsigned>()(s.units_sold)^
         hash<double>()(s.revenue);
}

}// close the std namespace; note: no semicolon after the close curly

int main()
{
  return 0;
}

