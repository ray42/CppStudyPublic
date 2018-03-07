#include<iostream>
using std::cout; using std::endl; using std::ostream;


//////////////////////////////////////////////
//Base stuff
class Base
{
public:
  Base(int i=2):bval(i){}
  virtual ~Base()=default;
  virtual auto debug(ostream& os=cout)const->ostream&;

private:
  int bval=0;
};

auto Base::debug(ostream& os) const->ostream&
{
  os << "bval: " << bval << endl;
  return os;
}

///////////////////////////////////////////////
//Derived stuff
class Derived : public Base
{
public:
  Derived(int i=2,int j=3):Base(i), dval(j){}
  ~Derived()=default;

  auto debug(ostream& os=cout) const ->ostream& override final; // error here

private:
  int dval=0;
};

auto Derived::debug(ostream& os) const->ostream&
{
  os << "dval: " << dval << endl;
  return os;
}

///////////////////////////////////////////////
//Testing!
int main()
{
  Base b(42);
  b.debug()<<endl;
  return 0;
}





