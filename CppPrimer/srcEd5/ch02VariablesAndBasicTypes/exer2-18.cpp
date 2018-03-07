#include<iostream>
#include<cstdlib>
int main(int argc, char** argv)
{
  // Write code to change the value of a pointer. 
  // Write code to change the value to which the pointer points.

  int ival=42;
  int *pi = nullptr; // initialised to null
  std::cout << "ival: " << ival << std::endl;
  
  // change the value of pi to the address of ival
  pi = &ival;
  
  // Changing assign 17 to ival via pi
  *pi = 17;
  std::cout << "ival: " << ival << std::endl;
  return EXIT_SUCCESS;
}
