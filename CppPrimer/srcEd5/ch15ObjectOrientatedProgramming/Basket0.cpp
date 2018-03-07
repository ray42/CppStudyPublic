/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#include"Basket0.h"

double Basket::total_receipt(ostream& os) const
{
  double num = 0.0; // holds the running total
  // iter refers to the first element in a batch of elements with the same
  // ISBN.
  //
  // upper_bound returns an iterator to the element just past the end of 
  // that batch
  for(auto iter = items.cbegin();
           iter != items.cend();
           iter = items.upper_bound(*iter))
  {
    // we know there's at least one element with this key in the Basket
    // otherwise we would have reached items.cend() already.
    // print the line item for this book.
    sum+=print_total(os,**iter,items.count(*iter));
  }
  os << "Total Sale: " << sum << endl; // print the final overall total
  return sum;
}


