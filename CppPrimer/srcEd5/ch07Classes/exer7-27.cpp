#include<iostream>
#include "Screen-7-27.h"

using std::cout; using std::endl;

int main()
{
  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";

  return 0;
}
