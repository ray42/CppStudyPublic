#include <iostream>
#include "Sales_data.h"

int main()
{
  Sales_data total; // variable to hold data for the next transaction

  // Recall that the input format is in:
  // ISBN #unitSold pricePerUnit
  //
  // which we need to read into Sales_data_old.
  // read the first transaction and ensure that there are data to process
  double temp_price = 0.0;
  if (std::cin >> total.bookNo >> total.units_sold >> temp_price)
  {
    // Work out the revenue for the first book.
    total.revenue = temp_price*total.units_sold;

    Sales_data trans; // variable to hold the running sum
    
    // read and process the remaining transactions
    while (std::cin >> trans.bookNo >> trans.units_sold >> temp_price)
    {
      trans.revenue = temp_price*trans.units_sold;

      // if we're still processing the same book
      if (total.isbn() == trans.isbn())
      {
        total.combine(trans); // update the running total
      }
      else
      {
        // print results for the previous book
        std::cout << total.isbn() << " " 
                  << total.units_sold << " "
                  << total.revenue << " "
                  << total.avg_price() << std::endl;

        total = trans;  // total now refers to the next book
      }
    }

    // print results for the previous book
    std::cout << total.isbn() << " " 
              << total.units_sold << " "
              << total.revenue << " "
              << total.avg_price() << std::endl;
  }
  else
  {
    // no input! warn the user
    std::cerr << "No data?!" << std::endl;
    return -1;  // indicate failure
  }
  return 0;
}
