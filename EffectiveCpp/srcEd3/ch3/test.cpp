#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;

int main(int argc, char** argv)
{
  // item 16, testing if this works:
  std::string * stringArray = new[100] std::string;
  delete[] stringArray;

//  std::string * stringptr = new std::string("Hi");
//  delete [] stringptr;

  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
