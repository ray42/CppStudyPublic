#include"Quote3.h"
#include<iostream>
using std::cout; using std::endl;
using std::ostream;

ostream& Quote::printstate(ostream& os) const
{
  os << "ISBN: " << bookNo << ", price: " << price;
  return os;
}
