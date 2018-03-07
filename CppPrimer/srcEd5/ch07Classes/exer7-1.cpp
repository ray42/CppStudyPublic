#include <iostream>
#include "Sales_data_old.h"

int main()
{
  Sales_data_old total; // variable to hold data for the next transaction

  // Recall that the input format is in:
  // ISBN #unitSold pricePerUnit
  //
  // which we need to read into Sales_data_old.
  // read the first transaction and ensure that there are data to process
  if (std::cin >> total.bookNo >> total.units_sold >> total.price)
  {
    // Work out the revenue for the first book.
    total.revenue = total.price*total.units_sold;

    Sales_data_old trans; // variable to hold the running sum
    
    // read and process the remaining transactions
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price) 
    {
      // if we're still processing the same book
      if (total.bookNo == trans.bookNo)
      {
        total.units_sold += trans.units_sold; // update the running total
        total.revenue+= (trans.units_sold*trans.price);
      }
      else
      {
        // print results for the previous book
        std::cout << total.bookNo << " " 
                  << total.units_sold << " "
                  << total.revenue << " "
                  << (total.revenue/total.units_sold) << std::endl;

        total = trans;  // total now refers to the next book
      }
    }

    // print results for the previous book
    std::cout << total.bookNo << " " 
              << total.units_sold << " "
              << total.revenue << " "
              << (total.revenue/total.units_sold) << std::endl;
  }
  else
  {
    // no input! warn the user
    std::cerr << "No data?!" << std::endl;
    return -1;  // indicate failure
  }
  return 0;
}
