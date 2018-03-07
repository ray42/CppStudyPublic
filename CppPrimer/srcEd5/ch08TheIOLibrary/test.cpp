#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin; using std::flush; using std::ends;

using std::vector;
using std::string;

int main(int argc, char** argv)
{
cout << "hi!" << endl;   // writes hi and a newline, then flushes the buffer
cout << "hi!" << flush;  // writes hi, then flushes the buffer; adds no data
cout << "hi!" << ends;   // writes hi and a null, then flushes the buffer


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
