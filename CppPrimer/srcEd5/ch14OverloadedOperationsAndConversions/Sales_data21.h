#ifndef SALES_DATA21_H
#define SALES_DATA21_H

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

  // exer14-20 addition and compound assignment
  Sales_data& operator+=(const Sales_data&); //compound-assignment
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
