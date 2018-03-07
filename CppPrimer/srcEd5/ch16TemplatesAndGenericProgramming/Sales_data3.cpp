/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"Sales_data3.h"
#include<iostream>
using std::cout; using std::ostream; using std::endl;
#include<string>
using std::string;
#include<utility>


ostream& Sales_data::printall(ostream& os)
{
  os << this << ": isbn " << bookNo << ", units_sold " << units_sold 
             << ", revenue " << revenue << endl;
  return os;
}

Sales_data::Sales_data(std::istream &is):Sales_data()
{
  is>>*this;
}

// exer14-20 addition and compound assignment
Sales_data& Sales_data::operator+=(const Sales_data&rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

//exer14-22 assignment op= taking string
Sales_data& Sales_data::operator=(const string& isbn)
{
//  bookNo = isbn;
//  // reset everything else
//  units_sold = 0;
//  revenue = 0.0;

  // Note: Moopphy has this:
  //*this = Sales_data(isbn);
  //However, that would invoke a constructor, which creates a temporary, 
  //then use the synthesized assignment operator.
  //
  //Maybe this is better:
  //*this = std::move(Sales_data(isbn)), this would use the synthesized
  //move-assignment c-tor.

  // actually, I'll use std::move
  *this=std::move(Sales_data(isbn));

  return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
  double price = 0.0; // no need to initialize;
                      // we'll read into price before we useit
  is >> item.bookNo >> item.units_sold >> price;
  if(is) // check that the inputs succeed
  {
    item.revenue = price*item.units_sold;
  }
  else
  {
    item = Sales_data(); // input failed: give the object default state
  }
  return is;
}

std::ostream& operator<<(std::ostream&os, const Sales_data&item)
{
  os << item.isbn() << " " 
     << item.units_sold << " " 
     << item.revenue << " " 
     << item.avg_price();
  return os;
}

// addition operator
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
  Sales_data sum=lhs;
  sum+=rhs;

  return sum;
}
