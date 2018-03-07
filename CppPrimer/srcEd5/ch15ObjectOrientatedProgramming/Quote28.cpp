/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 * =========================================================================
 */

#include"Quote28.h"
#include"./../common/rr.h"
#include<iostream>
using std::cout; using std::endl;
using std::ostream;

//ostream& Quote::printstate(ostream& os) const
//{
//  os << "ISBN: " << bookNo << ", price: " << price;
//  return os;
//}

auto Quote::debug(std::ostream& os) const->std::ostream&
{
  os << "Q: isbn " << bookNo <<", price: " << price;
  return os;
}

// calculate and print the price for the given number of copies, 
// applying any discounts
double print_total(std::ostream &os,
                   const Quote &item, size_t n)
{
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}




