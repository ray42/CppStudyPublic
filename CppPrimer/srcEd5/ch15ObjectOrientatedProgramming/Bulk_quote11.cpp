#include"Bulk_quote11.h"

#include<iostream>
using std::cout; using std::endl;
using std::ostream;

#include<string>
using std::string;

ostream& Bulk_quote::printstate(ostream& os) const
{
  os << "ISBN: " << isbn() 
     << ", price: " << price
     << ", min_qty: " << min_qty
     << ", dc: " << discount;
  return os;
}
auto Bulk_quote::debug(std::ostream& os) const->std::ostream&
{
  os << "BQ: min_qty " << min_qty << ", discount " << discount;
  return os;
}

Bulk_quote::Bulk_quote(const string& book, double p, size_t qty, double disc)
:  Quote(book,p), min_qty(qty), discount(disc)
{
}

double Bulk_quote::net_price(size_t cnt) const
{
  if(cnt >= min_qty)
    return cnt*(1-discount)*price;
  else
    return cnt*price;
}

