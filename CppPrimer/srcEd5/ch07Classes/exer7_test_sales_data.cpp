#include<iostream>
#include "Sales_data.h"

int main()
{
  Sales_data sd;

  sd.isbn() = "some isbn";
  std::cout << "isbn()" << sd.isbn() << std::endl;

  sd.bookNo = "Some isbn";
  std::cout << "bookNo" << sd.bookNo << std::endl;

  return 0;
}
