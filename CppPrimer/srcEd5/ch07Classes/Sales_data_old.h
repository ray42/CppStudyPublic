#ifndef RR_SALES_DATA_OLD_H
#define RR_SALES_DATA_OLD_H

#include<string>

struct Sales_data_old
{
  // ISBN
  std::string bookNo = "";

  // Name of book
  // This appears to be not used by the program in the book, but I think
  // all books should have a name, so I'll leave it here.
//  std::string bookName = ""; 

  // Number of units sold
  unsigned units_sold = 0;

  // Price per book.
  double price = 0.0;

  // revenue = units_sold*price
  double revenue = 0.0;
};
#endif /* RR_SALES_DATA_H */
