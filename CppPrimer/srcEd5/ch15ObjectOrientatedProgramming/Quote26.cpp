/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 * =========================================================================
 */

#include"Quote26.h"
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


