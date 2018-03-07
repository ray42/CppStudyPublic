/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"ex14-2-Sales_data.h"

Sales_data::Sales_data(std::istream &is):Sales_data()
{
  is>>*this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
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

Sales_data operator+(const Sales_data&lhs, const Sales_data&rhs)
{
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

