#include<iostream>

#include "Core.h"
#include "Grad.h"


using std::cout; using std::endl; using std::cin;

int main(int argc, char** argv)
{
  Core* p1 = new Core(cin);
  Core* p2 = new Grad(cin);

  Core s1(cin);
  Grad s2(cin);
  cout << "\n"<< endl;

  p1->grade();
  p1->name();

  cout << "\n"<< endl;
  p2->grade();
  p2->name();

  cout << "\n"<< endl;
  s1.grade();
  s1.name();

  cout << "\n"<< endl;
  s2.grade();
  s2.name();

  cout << "\n\nGot to end of ch13e2" << endl;
  return 0;
}



