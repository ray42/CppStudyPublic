#include<iostream>
#include<vector>

#include "median.h"


using std::cout; using std::endl; using std::cin;
using std::vector;


template<class T>
T max(const T& left, const T& right)
{
return left > right ? left : right;
}



int main(int argc, char** argv)
{
  vector<double> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  
  double m = median(v);
//
//  double m = max(1.2,2.2);
  cout <<"m: " <<  m << endl;
  return 0;
}


