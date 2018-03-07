#include<iostream>
#include<vector>
#include<string>

#include "./../rayheader.h"

using std::cout; using std::endl; using std::endl;
using std::vector;
using std::string;

template <class In, class X> In find(In begin, In end, const X& x)
{
  while(begin != end && (*begin) != x)
    ++begin;

  return begin;
}

template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
  while(begin != end)
  {
    *dest++ = *begin++;
  }
  return dest;
}

int main(int argc, char** argv)
{
//  static const int arr[] = {16,2,77,29};
//  vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  vector<int> vec = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
  string vec_str = ray::print_vec(vec);
  cout << "Values are: " << vec_str << endl;

  // testing find
  int num = 22;
  vector<int>::iterator it= find(vec.begin(), vec.end(), num);
  if(it == vec.end())
    cout << "Not found " << num << endl;
  else
    cout << "Found: " << *it << endl;



  return 0;
}



