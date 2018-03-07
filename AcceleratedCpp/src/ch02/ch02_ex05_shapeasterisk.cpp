#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
  cout << "\n";
  const unsigned height=5;
  // square
  for (unsigned i = 0; i < height; i++) 
  {
    for (unsigned j = 0; j < height; j++) 
    {
      cout << "*";
    }
    cout << endl; 
  }

  cout << "\n\n";

  // rectangle
  const unsigned width = 5;
  for (unsigned i = 0; i < height; i++) 
  {
    for (unsigned j = 0; j < width; j++) 
    {
      cout << "*";
    }
    cout << endl; 
  }

  // triangle
  for (unsigned i = 0; i < height; i++) 
  {
    for (unsigned j = 0; j < i; j++) 
    {
      cout << "*";
    }
    cout << endl; 
  }
  return 0;
}
