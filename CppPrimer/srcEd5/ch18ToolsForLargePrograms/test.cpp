#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;

using std::vector;
using std::string;

#include<stdexcept>
using std::exception;

//void foo(...)
//{
//  cout << "Hello" << endl;
//}


namespace rayns{

  int sumwanwan = 42;
}


inline namespace rayns
{
  int isthisinlined=0;
}

void compute(int i)
{
  cout << "Hi from int" << endl;
}

void compute(const void* p)
{
  cout << "Hi from const void*" << endl;
}
//void compute(void* p)
//{
//  cout << "Hi from void*" << endl;
//}

struct B
{
  void print(int i)
  {
    cout << i << endl;
  }
};

struct D: public B
{
  void print(string s)
  {
    cout << s << endl;
  }
};


int main(int argc, char** argv)
{
  D d;
  d.print(1);

//  compute(0);

//  try{
//  throw exception{};
//  }catch(...)
//  {
//    cout << "hi from ..." << endl;
//    throw;
//  }
//  catch(exception e)
//  {
//    cout << "is this caught?" << endl;
//  }


//  foo(1,2,3);


  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
