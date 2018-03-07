/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"Limit_quote28.h"
#include"./../common/rr.h"

#include<iostream>
using std::cout; using std::endl;
using std::ostream;

#include<string>
using std::string;

//ostream& Limit_quote::printstate(ostream& os) const
//{
//  os << "ISBN: " << isbn() 
//     << ", price: " << price
//     << ", min_qty: " << min_qty
//     << ", dc: " << discount;
//  return os;
//}

auto Limit_quote::debug(std::ostream& os) const->ostream&
{
  Disc_quote::debug(os) << std::endl;
  os << "LQ: max_qty "<< max_qty;
  return os;
}

Limit_quote::Limit_quote(
  const string& book, double p, size_t min, size_t max, double disc)
:  Disc_quote(book,p,min,disc), max_qty(max)
{rr::greet(__PRETTY_FUNCTION__,this);}

double Limit_quote::net_price(size_t cnt) const
{
  if((cnt >= quantity) && (cnt <= max_qty))
    return cnt*(1-discount)*price;
  else
    return cnt*price;
}





