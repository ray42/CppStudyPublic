#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;


class Base
{
public:
  Base() = default;
  virtual ~Base()=default;
  void f(int i)
  {
    cout << "B int: " << i << endl;
  }

//private:
  void f(string s)
  {
    cout << "B string: " << s << endl;
  }
};

class Derived : public Base
{
public:
  Derived() = default;
  virtual ~Derived() = default;
  
  using Base::f;
  void f(int i)
  {
    cout << "D int: " << i << endl;
  }
private:

};

int main(int argc, char** argv)
{
  int i = 42;
  
  Derived d;
  d.f(i);
  d.f("test");
  

  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
