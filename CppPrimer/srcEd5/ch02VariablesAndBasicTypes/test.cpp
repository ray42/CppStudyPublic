#include<iostream>
#include <typeinfo>

class Foo
{
public:
  Foo(const int & ii)
  {
    i=ii;
  }

  int i=42;
  const int c3 = 7;           // error: not static
  static int c4 = 7;          // error: not const
  static const float c5 = 7;  // error: not integral

};


//extern int i = 0; 
int main()
{
  // 1) It is an error to provide an initializer on an extern inside a 
  // function, let's test this.
//  extern int i = 0; // yeah, we get a compiler error
  //See above the main function, we can initialize an extern if outside a 
  //function


  // 2) Can we assign an rvalue to a reference?
  //int & lvalref=4; //no we get a compile time error.
//  const int & lvalref = 4; // but this works, since we're promising to not
  // change the value. Since a reference is another name for a name, we need
  // to be able to identify the storage if we want to change it. If we're 
  // not going to change it, then it's okay, hence we can assign a rvalue to
  // a const reference.


  // Do we get a compile error when we not do initialize a const variable?
//  const int k; // yes we get a compile error.

  // Seeing if we can bound a non-const reference to a const object:
//  const int cival=0;
//  int &ri = cival; // No, we cannot do this.

  // Can we define a const reference?
//  int qq=0;
//  int& const i = qq; // no we cannot.


  // test for exer 2.31: Can you convert an inbuilt int type to pointer 
  // type?
//  int null=0, * p = null; // no we cannot.
//  int null=0, * p = nullptr;

//  typedef char *pstring;
//  pstring const_pstr=0;
//  pstring const pstr_const=0;

//  const int i = 0;
//  std::cout << typeid(i).name() << std::endl;

//  const_pstr=0;
//  pstr_const=0;

//  auto i = 0, p=1.2;

  ////////////////////
//  int i = 42;
//  auto ri= i, *pi=;
//  auto * pi2= &i;
//  std::cout << "*pi: " << *pi << std::endl;
//  std::cout << "*pi2: " << *pi2 << std::endl;

////////////////////////////
  // Can I assign a int literal to a pointer?
//  int *i = 42;

//  ///////////////// testing decltype
//  int ival = 42;
//  const int cival=69;
//  int & r=ival;
//  const int& cr=cival;
//  int *pi = &ival;
//  const int* cpi=&ival;
//  int* const pic=&ival;
//  const int* const cpic=&ival;
//
//  // these are same as the above.
//  decltype(ival) dival=0;     // int
//  decltype(cival) dcival = 0; // const int
//  decltype(r) dr=ival;        // int&
//  decltype(cr) dcr=cival;     // const int&
//  decltype(pi) dpi = &ival;   // int*
//  decltype(cpi) dcpi=&ival;   // const int*
//  decltype(pic) dpic=&ival;   // int* const
//  decltype(cpic) dcpic=&ival; // const int* const
//
//  // expressions, we ignore the top level const of the pointer,
//  // since we are deferencing.
//  decltype(*pi) dedpi = ival; // int&
//  decltype(*cpi) dedcpi=0;    // const int&
//  decltype(*pic) dedpic=ival; // int&
//  decltype(*cpic) dedccpi=0;  // const int&

  Foo foo(1);
  std::cout << "foo.i: " << foo.i << std::endl;
  
  std::cout << "Hello, got to end of test" << std::endl;
  return 0;
}
