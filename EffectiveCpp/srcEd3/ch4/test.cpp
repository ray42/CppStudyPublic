#include<iostream>
using std::cout; using std::clog; using std::cerr; using std::endl; 
using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;


template<typename T>
class mynum{

public:
  mynum(T _i)
  : i(_i)
  {}

  mynum operator*(const mynum &rhs) const
  {
    return i*rhs.i;
  }

  void print() const
  {
    cout << i << endl;
  }

private:
  T i;
};

int main(int argc, char** argv)
{

  mynum<int> two(2);
  mynum<int> three(3);
  
  const mynum<int> foo(3);


  //passing ‘const mynum<int>’ as ‘this’ argument discards qualifiers
  //i.e. cannot assign to const.
  //
  //taking off the const works from the return type works.
  two*three = foo;
  //six.print();

  std::cout << "argc: " << argc << ", argv[0]: " << argv[0] << std::endl;
  return 0;
}
