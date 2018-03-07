#ifndef RR_SALES_DATA_H
#define RR_SALES_DATA_H

#include<string>

struct Sales_data
{
  // ISBN
  std::string bookNo = "";

  // Name of book
  std::string bookName = "";

  // Number of units sold
  unsigned units_sold = 0;

  // Price per book.
  double price = 0.0;

  // revenue = units_sold*price
  double revenue = 0.0;
};
#endif /* RR_SALES_DATA_H */
