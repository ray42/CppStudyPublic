#include"Quote11.h"
#include<iostream>
using std::cout; using std::endl;
using std::ostream;

ostream& Quote::printstate(ostream& os) const
{
  os << "ISBN: " << bookNo << ", price: " << price;
  return os;
}

auto Quote::debug(std::ostream& os) const->std::ostream&
{
  os << "Q: isbn " << bookNo <<", price: " << price;
  return os;
}


