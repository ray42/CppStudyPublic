#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::endl; using std::cin;
using std::vector;
using std::string;

int main()
{
  // Repeat the previous program but read strings this time.
  string var;
  vector<string> vec;
  while(cin >> var)
  {
    vec.push_back(var);
  }

  for(const auto &i : vec)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
