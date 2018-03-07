/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"Sales_data45.h"
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;


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
    cout <<"\n"<<endl;
  }

  {
    cout << "T2 op=(string)" << endl;
    Sales_data s3;
    s3=string("0-284-220-1");
    s3.printall();
    cout << "\n"<<endl;
  }

  {
    cout << "E45 op string, op double" << endl;
    cout << static_cast<string> (s1) << endl;
    cout << static_cast<double> (s1) << endl;
  }


  return 0;
}
