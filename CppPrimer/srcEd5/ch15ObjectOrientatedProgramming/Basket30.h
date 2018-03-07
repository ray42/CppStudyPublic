/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef BASKET_H
#define BASKET_H

#include<memory> // shared_ptr
#include<set> // multiset
#include<iostream> // ostream

#include"Quote30.h"
#include"Disc_quote30.h"
#include"Bulk_quote30.h"
#include"Limit_quote30.h"

class Basket
{
public:

  //////////////////////////////////////////////////////////////////////////
  //ex15-30 basket stuff.
  //  // Basket uses synthesized default constructor and copy-control members
//  void add_item(const std::shared_ptr<Quote>&sale)
//  {items.insert(sale);}

  // New add_item, so that the user does not have to create a shared_ptr
  // with make_shared<Quote>(param for Quote)

  void add_item(const Quote& sale) // copy the given object
  {
    // bind the new object from clone directly to a shared_ptr.
    // do NOT call make_shared, since that will allocate a new object on the
    // heap.
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  }

  void add_item(Quote&& sale) // move the given object
  {
    // need to covert the name sale into an rvalue with std::move
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }

  //////////////////////////////////////////////////////////////////////////


  //prints the total price for each book and
  //the overall price for all items in the basket
  double total_receipt(std::ostream&) const;

private:
  // function to compare shared_ptrs needed by the multiset member
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs)
  { return lhs->isbn() < rhs->isbn(); }

  // multiset to hold multiple quotes, ordered by he compare member
  std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};
};
#endif




