#include<iostream>
#include "Sales_item.h"

int main(int argc, char** argv)
{
  // Use it to write a program that reads a set of book sales
  // transactions, writing each transaction to the standard output.
  Sales_item item1, item2;
  std::cin >> item1 >> item2; // read a pair of translation
  std::cout << item1+item2 << std::endl;
  return 0;
}
