#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

int main(int argc, char** argv)
{
//  //A label may not stand alone; it must precede a statement or another
//  // case label. If a switch ends with a default case that has
//  //no work to do, then the default label must be followed by a null
//  //statement or an empty block.
//  int ival=42;
//  switch (ival){
//    case 1:
//      cout << "case 1" << endl;
//      break;
//    default:;
//  }


  do
  {
    int ival = 1;
    cout << "Got in do while" << ival << endl;
  }
  while (ival == 1)


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
