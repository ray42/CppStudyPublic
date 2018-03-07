#include<iostream>
#include<string>
#include<vector>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::vector;


// Redo the first exercise from 3.16 using iterators.
//
// Since there are only two type of vectors, int and string, I'll use a 
// template to make this easier.
// This is a bit cheeky since we've not learnt about templates yet.
// But the code is pretty easy to understand.
template<typename T> void size_and_content(const vector<T>& vec)
{
  cout << "Size: " << vec.size() << endl;
  cout << "Contents: ";
  for(auto it=vec.cbegin(); it != vec.cend(); ++it)
  {
    cout << (*it) << " ";
  } 
  cout << endl;
}

int main()
{
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4{10};
  vector<int> v5{10, 42};
  vector<string> v6{10};
  vector<string> v7{10, "hi"};
  
  cout << "v1:" << endl;
  size_and_content(v1);

  cout << "v2:" << endl;
  size_and_content(v2);

  cout << "v3:" << endl;
  size_and_content(v3);

  cout << "v4:" << endl;
  size_and_content(v4);

  cout << "v5:" << endl;
  size_and_content(v5);

  cout << "v6:" << endl;
  size_and_content(v6);

  cout << "v7:" << endl;
  size_and_content(v7);

  return 0;
}
