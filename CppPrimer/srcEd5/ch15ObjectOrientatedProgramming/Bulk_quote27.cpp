#include"Bulk_quote26.h"
#include"./../common/rr.h"

#include<iostream>
using std::cout; using std::endl;
using std::ostream;

#include<string>
using std::string;

//ostream& Bulk_quote::printstate(ostream& os) const
//{
//  os << "ISBN: " << isbn() 
//     << ", price: " << price
//     << ", min_qty: " << min_qty
//     << ", dc: " << discount;
//  return os;
//}
auto Bulk_quote::debug(std::ostream& os) const->std::ostream&
{
  Disc_quote::debug(os) << std::endl;
  os << "BQ";
  return os;
}

//Bulk_quote::Bulk_quote(const string& book, double p, size_t qty, double disc)
//:  Disc_quote(book,p,qty,disc)
//{ rr::greet(__PRETTY_FUNCTION__,this);}

double Bulk_quote::net_price(size_t cnt) const
{
  return cnt >= quantity ? cnt*(1-discount)*price:cnt*price;
//  if(cnt >= min_qty)
//    return cnt*(1-discount)*price;
//  else
//    return cnt*price;
}

