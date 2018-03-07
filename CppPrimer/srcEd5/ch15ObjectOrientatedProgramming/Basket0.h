/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef BASKET_H
#define BASKET_H
#include"Quote28.h"
#include"Disc_quote28.h"
#include"Bulk_quote28.h"
#include"Limit_quote28.h"

class Basket
{
public:
  // Basket uses synthesized default constructor and copy-control members
  void add_item(const std::shared_ptr<Quote>&sale)
  {items.insert(sale);}

  //prints the total price for each book and
  //the overall price for all items in the basket
  double total_receipt(std::ostream&) const;

private:
  // function to compare shared_ptrs needed by the multiset member
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs)
  { return lhs->isbn() < rhs->isbn(); }

  // multiset to hold multiple quotes, ordered by he compare member
  std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items(compare);

};


#endif




