#include<iostream>
#include<string>
#include<vector>

class NoDefault
{
public:
  NoDefault(int i):someInt(i)
  {
  }

  int someInt;
};

class C
{
public:
  C()=default;

//  NoDefault nd; // error
  NoDefault nd{0}; // works

};


using std::cout; using std::endl;

int main()
{

  // exer 7-44
  // error, no default initializer, it is required to initialize the 
  // elements.
//  std::vector<NoDefault> vec(10);  // error

  // However, if we provide an initializer, then vector can use this element
  // to copy initialize:
  std::vector<NoDefault> vec(10, NoDefault(0)); // this works.

  std::vector<C> vecC(10);
//  NoDefault nd("No Default");
//  cout << nd.someStr << endl;
  return 0;
}
