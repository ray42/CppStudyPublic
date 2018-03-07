#include<iostream>
#include<vector>
#include<iterator>
using std::cout; using std::endl;
using std::vector;
using std::back_inserter;

int main()
{
  vector<int> v;
  auto it = back_inserter(v);
  cout << "v.size(): " << v.size() << endl; // size is 0
  *it = 1; // calls push_back on v
  cout << "v.size(): " << v.size() << endl; // size is 1
  *it = 2; // calls push_back on v
  *it = 2; // calls push_back on v
  cout << "v.size(): " << v.size() << endl; // size is 3
  ++it; ++it; ++it; // incrementing has no effect.
  *it=3; // calls push_back on v
  cout << "v.size(): " << v.size() << endl; // size is 4
  return 0;
}
