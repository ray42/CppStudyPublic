#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

class Base {
public:
  virtual ~Base(){};
  static void statmem()
  {
    cout << "hi from base static" << endl;
  }
  void pr()
  {
    cout << someint << endl;
  }

  virtual void pp(int i=11)const
  {
    cout << i << endl;
  }

  static int someint;
};
int Base::someint = 42;

class Derived : public Base {
public:
  static void statmem()
  {
    cout << "hi from derived static" << endl;
  }

  void f(const Derived&);
  void pr()
  {
    cout << "derived pr: " << someint << endl;
    Base::pr();
  }
  virtual void pp(int i=22) const override
  {
    cout << i << endl;
  }

  static int someint;
};
int Derived::someint = 69;

//struct B {
//  virtual void f1(int) const;
//  virtual void f2();
//  void f3();
//};
//struct D1 : B {
//  void f1(int) const override; // ok: f1 matches f1 in the base
//  void f2(int) override; // error: B has no f2(int) function
//  void f3() override;    // error: f3 not virtual
//  void f4() override;    // error: B doesn't have a function named f4
//};


int main(int argc, char** argv)
{

  cout << Derived::someint << endl;
  cout << Base::someint << endl;

  Derived d;
  d.pr();

  Base::statmem();
  Derived::statmem();

  Base b;
  b.pp();
  d.pp();

  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
