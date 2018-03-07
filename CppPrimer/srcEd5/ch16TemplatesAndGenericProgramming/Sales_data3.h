#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include<iostream>

class Sales_data
{
  friend std::istream& operator>>(std::istream&, Sales_data&); // input
  friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output

  // exer14-20 addition and compound assignment
  friend Sales_data operator+(const Sales_data&, const Sales_data&); // add

public:
  Sales_data(const std::string&s, unsigned n, double p):
    bookNo(s),units_sold(n),revenue(p*n)
  {/* empty */}
  Sales_data():Sales_data("",0,0.0f){/* empty */}
  Sales_data(const std::string&s):Sales_data(s,0,0.0f){/* empty */}
  Sales_data(std::istream &is);

  // exer14-45 conversion operator to string and to double
  explicit operator std::string() const
  { return bookNo;}
  explicit operator double() const
  { return avg_price();}


  // exer14-20 addition and compound assignment
  Sales_data& operator+=(const Sales_data&); //compound-assignment

  // exer14-22 assignment string
  Sales_data& operator=(const std::string&);

  std::string isbn() const {return bookNo;}

  std::ostream& printall(std::ostream& os=std::cout);

private:
  inline double avg_price() const;

  std::string bookNo; // isbn
  unsigned units_sold;
  double revenue;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);

// exer14-20 addition and compound assignment
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
  return units_sold ? revenue/units_sold : 0;
}

#endif
