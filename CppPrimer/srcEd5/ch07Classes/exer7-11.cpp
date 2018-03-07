#include<iostream>
using std::cout; using std::endl;

#include "Sales_data.h"



int main()
{
  Sales_data sd1;
  cout << "sd1";
  print(cout,sd1) << endl;


  Sales_data sd2("12345X");
  cout << "sd2";
  print(cout,sd2) << endl;

  Sales_data sd3("12345X",42,9.99);
  cout << "sd3";
  print(cout,sd3) << endl;

  Sales_data sd4(std::cin);
  cout << "sd4";
  print(cout,sd4) << endl;

  return 0;
}
