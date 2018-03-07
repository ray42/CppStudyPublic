/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
using std::ostream;

#include"Quote3.h"
#include"Bulk_quote5.h"
#include"Limit_quote7.h"

// calculate and print the price for the given number of copies, 
// applying any discounts
double print_total(ostream &os,
                   const Quote &item, size_t n)
{
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main()
{
  Quote q("X-42-220", 3.99);
  q.printstate() << endl;
  Bulk_quote bq("Y-69-284", 4.99, 10, 0.1);
  bq.printstate() << endl;


  Limit_quote lq("Y-69-284", 4.99, 8,10, 0.1);
  cout << "\n\nAbout to print_total"<< endl;
  print_total(cout,q,10);
  print_total(cout,bq,10);
  print_total(cout,lq,10);
  print_total(cout,lq,11);


  return 0;
}

