#ifndef RR_SALES_DATA_H
#define RR_SALES_DATA_H

#include<string>
#include<iostream>

class Sales_data;

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

class Sales_data
{

friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);

public:
  // constructors
//  Sales_data()=default; // default constructor
  Sales_data():units_sold(0), revenue(0.0){} // for exer7-14

  // Takes ISBN, default values for other members
  Sales_data(const std::string &s):bookNo(s){}

  Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n){}

  Sales_data(std::istream& is){ read(is,*this);} // reads a transaction

  // new members: operations on Sales_data objects
  std::string isbn() const {return bookNo;}
  Sales_data& combine(const Sales_data&);
  
private:
  
  inline double avg_price() const;

  // data members are unchanged from 2.6.1

  // ISBN
  std::string bookNo="";

  // Number of units sold
  unsigned units_sold = 0;

  // revenue = units_sold*price
  double revenue = 0.0;
};

// constructor which reads
//Sales_data::Sales_data(std::istream &is)
//{
//  read(is,*this);
//}

double Sales_data::avg_price() const
{
  if(units_sold)
    return revenue/units_sold;
  else
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold+=rhs.units_sold; // add the 
  revenue+=rhs.revenue;
  return *this;
}




// input transactions contain ISBN, number of copies sold, and sales price
std::istream &read(std::istream &is, Sales_data &item)
{
  double price=0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price*item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
  Sales_data sum = lhs; // copy data members from lhs into sum
  sum.combine(rhs); // add data members from rhs into sum
  return sum;
}

#endif /* RR_SALES_DATA_H */
