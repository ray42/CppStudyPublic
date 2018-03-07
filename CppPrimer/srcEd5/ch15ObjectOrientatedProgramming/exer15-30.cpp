/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;
using std::ostream;

#include<vector>
using std::vector;

#include<memory>
using std::shared_ptr;

#include<algorithm>
using std::for_each;

#include"./../common/rr.h"
#include"Basket30.h"
#include"Quote30.h"
#include"Disc_quote30.h"
#include"Bulk_quote30.h"
#include"Limit_quote30.h"


int main()
{
{
  cout << "E7 testing classes" << endl;
  Quote q("X-42-220", 3.99);
//  q.printstate() << endl;
  Bulk_quote bq("Y-69-284", 4.99, 10, 0.1);
//  bq.printstate() << endl;

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
  cout << endl;
  print_debug(bq);
  cout << endl;
  print_debug(lq);
  cout << endl;

  // exer 15-17
//  Disc_quote DQ;
}

{
  cout << "E26 Part 1, Quote:"<<endl;
  rr::debug=true;
  cout << "default constructor" << endl;
  Quote q;
  cout << "non-default constructor" << endl;
  Quote q2("Q-4242", 1.20);
  cout << "copy constructor" << endl;
  Quote q3(q2);
  rr::debug=false;
  Quote q4;
  cout << "copy assign op" << endl;
  rr::debug=true;
  q4=q3;
  cout << "move constructor" << endl;
  Quote q5(std::move(q4));
  rr::debug=false;
  
  Quote q6;
  rr::debug=true;
  cout << "move assign op" << endl;
  q6 = std::move(q5);
  
  rr::debug=false;
}
{
  cout << "E26 Part 2, Bulk_quote"<<endl;
  rr::debug=true;
  cout << "\ndefault constructor" << endl;
  Bulk_quote q;
  cout << "\nnon-default constructor" << endl;
  Bulk_quote q2("BQ-220220", 2.40, 10, 0.1);
  cout << "\ncopy constructor" << endl;
  Bulk_quote q3(q2);
  rr::debug=false;
  Bulk_quote q4;
  cout << "\ncopy assign op" << endl;
  rr::debug=true;
  q4=q3;
  cout << "\nmove constructor" << endl;
  Bulk_quote q5(std::move(q4));
  rr::debug=false;
  
  Bulk_quote q6;
  rr::debug=true;
  cout << "\nmove assign op" << endl;
  q6 = std::move(q5);
  
  cout << "\nNow look at how the destructors are ordered:" << endl;
  rr::debug=true;
}

{
  rr::debug = false;
  cout <<"\n\nExer 28, 29 vector<Ouote>, vector<shared_ptr<quote>>" << endl;
  vector<Quote> vq;
  for(unsigned i = 0; i < 10; ++i)
  {
    vq.push_back(Bulk_quote("BQ-220220", 2, 5, 0.1));
  }

  double totprice=0.0;
  for_each(vq.begin(),vq.end(),
      [&totprice](const Quote& q)
      {
        totprice+=q.net_price(20);
      });
  // £2*20*10 = 400
  cout << "total: " << totprice << endl;

  vector<shared_ptr<Quote>> vqp;
  for(unsigned i = 0; i < 10; ++i)
  {
    vqp.push_back(std::make_shared<Bulk_quote>("BQ-220220", 2, 5, 0.1));
  }
  totprice = 0.0;
  for_each(vqp.begin(),vqp.end(),
      [&totprice](shared_ptr<Quote> qpt)
      {
        totprice+=qpt->net_price(20);
      });

  // 10% discount, £40 off, price is 360.
  cout << "total: " << totprice << endl;
}

{
  cout <<"\n\nExer 30 Basket" << endl;
  rr::debug = false;
  Basket basket;
  // we had 10 quotes (inserted 10 quotes into the vector), then
  // we indicated that we wanted 20 of each quote, therefore, we have 200.
  for(unsigned i = 0; i < 200; ++i)
  {
    basket.add_item(Quote("220-284",2));
  }
  cout << "Total: " << basket.total_receipt(cout) << endl;
}
{
  cout <<"\nExer 30 Basket - part 2" << endl;
  rr::debug = false;
  Basket basket;
  // we had 10 quotes (inserted 10 quotes into the vector), then
  // we indicated that we wanted 20 of each quote, therefore, we have 200.
  for(unsigned i = 0; i < 200; ++i)
  {
    basket.add_item(Bulk_quote("220-284",2,5,0.1));
  }
  cout << "Total: " << basket.total_receipt(cout) << endl;
}



  return 0;
}
