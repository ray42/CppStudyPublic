/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
using std::ostream;

#include"Quote11.h"
#include"Bulk_quote11.h"
#include"Limit_quote11.h"

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
{
  cout << "E7 testing classes" << endl;
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
  cout << endl;
}
{
  cout << "E11 pt1"<<endl;
  Quote q("Q-4242", 1.20);
  Bulk_quote bq("BQ-220220", 2.40, 10, 0.1);
  Limit_quote lq("LQ-284284", 4.80, 8, 10, 0.1);

  // Note: Not dynamic binding!
  // The codes below are not dynamic binding. The compiler has known what 
  // the r referring to at compile time. As a result, the virtual function 
  // debug of the subobject is called.
  //
  // NOTE: The above is wrong. A reference is bound to an object, you can
  // never re-assign it. Thus, we're "copy" assigning.
  // So the static and dynamic type is always known at compile time.
  Quote& qr = q;
  qr.debug() << endl;
  qr = bq;
  qr.debug() << endl;
  qr = lq;
  qr.debug() << endl;

  Bulk_quote& br = bq;
  br.debug() << endl;
//  br = q; // this is error since there is no copy assingment in Bulk_quote
//  which takes a Quote.
//  br.debug() << endl;
//  br = lq;
//  br.debug() << endl;

  cout << "E11 pt2"<<endl;
  //note   dynamic binding!
  //The below will happen dynamic binding. The reason might be that while
  //print_debug compiling the compiler compile it independently from the 
  //rest codes. The compiler has no idea what the parameter q referring to.
  //Thus compiler will leave the decision to run time. That is, dynamic 
  //binding.
  //
  //Once dynamic binding happens, the corresponding virtual function in 
  //derived class will be called rather than that of the subobject inside 
  //the derived object.
  //
  //Anyway, the reference is essentially an address being passed.
  auto print_debug = [](const Quote& qq){qq.debug()<<endl;};
  print_debug(q);
  print_debug(bq);
  print_debug(lq);
}

  return 0;
}

