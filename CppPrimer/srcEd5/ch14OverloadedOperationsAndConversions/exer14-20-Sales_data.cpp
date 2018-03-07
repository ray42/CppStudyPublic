/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"Sales_data20.h"
#include<iostream>
using std::cout; using std::endl;


int main()
{
  // isbn, units_sold, price
  Sales_data s1("0-220-284-1",5,3);
  Sales_data s2("0-220-284-1",10,3);
  
  {
    cout << "T1 op+ and op+=" << endl;
    Sales_data s3= s1+s2;
    s3.printall();
    s3+=s3;
    s3.printall();
  }

  return 0;
}
