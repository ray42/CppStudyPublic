#include<iostream>
#include<string>
#include<cstring>

using std::cout; using std::endl; using std::cin;
using std::string;

int main(int argc, char** argv)
{
//  unsigned cnt = 42;          // not a constant expression
//  constexpr unsigned sz = 42; // constant expression
                              // constexpr see § 2.4.4 (p. 66)
//  int arr[10];             // array of ten ints
//  int *parr[sz];           // array of 42 pointers to int
//  string bad[cnt];         // error: cnt is not a constant expression
//  string strs[get_size()]; // ok if get_size is constexpr, error otherwise

  //////////////////////////////////////////////////////////////////////////
//  char a4[6] = "Daniel";      //error: no space for the null!
//  const char a5[6] = "Daniel";      //error: no space for the null!

  //////////////////////////////////////////////////////////////////////////
  //p 174: testing null terminated string.
//  char ca[] = {'C', '+', '+'}; // not null terminated
//  cout << std::strlen(ca) << endl;
 
  //////////////////////////////////////////////////////////////////////////
  //p175 adding two pointers is illegal and meaningless
  const char ca1[]="A string example";
  const char ca2[]="A different string";

  char* ca3=ca1+ca2;


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
