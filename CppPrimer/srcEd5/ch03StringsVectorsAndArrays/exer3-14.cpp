#include<iostream>
#include<vector>

using std::cout; using std::endl; using std::cin;
using std::vector;

int main()
{
  // Write a program to read a sequence of ints from cin and store those 
  // values in a vector.
  int var=0;
  vector<int> vec;
  while(cin >> var)
  {
    vec.push_back(var);
  }

  // Note: mooophy uses this:
  // for (int i; std::cin >> i; vec.push_back(i));
  // which reduces the scope of i, which is pretty cool.

  for(const auto &i : vec)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
