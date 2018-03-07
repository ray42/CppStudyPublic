#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main(int argc, char** argv)
{

  void (*pf1)(int);             // points to a C++ function
  extern "C" void (*pf2)(int);  // points to a C function
  pf1 = pf2; // error: pf1 and pf2 have different types


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
