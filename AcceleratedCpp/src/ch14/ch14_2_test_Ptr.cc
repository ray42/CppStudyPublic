#include<iostream>
#include<string>
#include<sstream>

#include "Ptr.h"
#include "Core.h"


using std::cout; using std::endl; using std::cin;
using std::string;
using std::istringstream;

int main(int argc, char** argv)
{

  // Testing Ptr class
  cout << "Test1: Ptr default constructor" << endl;
  Ptr<Core> p1;
  // Now check the ref count and pointer.
  cout << "p1.refptr: " << p1.ref_count() << ", p1.p: " << p1.get_ptr() << endl;
  cout << "\n" << endl;

  // Test2
  cout << "Test2: Ptr(T*) constructor" << endl;
  string str = "A 1 2 3 4 5 6 7 8";
  istringstream iss;
  iss.str(str);
  Ptr<Core> p2(new Core(iss));
  // Now check the ref count and pointer.
  cout << "p2.refptr: " << p2.ref_count() << ", p2.p: " << p2.get_ptr() << endl;
  cout << "\n" << endl;

  // Test3
  cout << "Test3: copy constructor" << endl;
  Ptr<Core> p3 = p2;
  cout << "p3.refptr: " << p3.ref_count() << ", p3.p: " << p3.get_ptr() << endl;
  cout << "\n" << endl;

  // Test4
  cout << "Test4: assignment operator" << endl;
  p1 = p3;
  cout << "p1.refptr: " << p1.ref_count() << ", p1.p: " << p1.get_ptr() << endl;
  cout << "\n" << endl;

  // Test5 make p3 unique
  cout << "Test5: Make p3 unique (so p3's address should be different)" << endl;
  p3.make_unique();
  cout << "p1.refptr: " << p1.ref_count() << ", p1.p: " << p1.get_ptr() << endl;
  cout << "p2.refptr: " << p2.ref_count() << ", p2.p: " << p2.get_ptr() << endl;
  cout << "p3.refptr: " << p3.ref_count() << ", p3.p: " << p3.get_ptr() << endl;
  cout << "\n" << endl;

  cout << "Test6: dereference operator T& Ptr<T>::operator*()" << endl;
  cout << "name is: " << (*p1).name() << endl;
  cout << "\n" << endl;

  cout << "Test7: testing T* Ptr<T>::operator->()" << endl;
  cout << "name is: " << p1->name() << endl;


  cout << "\n" << endl;
  cout << "Got to end of ch14_2_test_Ptr" << endl;
  return 0;
}

