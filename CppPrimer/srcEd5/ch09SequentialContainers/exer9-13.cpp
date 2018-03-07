#include<vector>
#include<list>
#include<iostream>
using std::vector;
using std::list;
using std::cout; using std::endl;

//Exercise 9.13: How would you initialize a vector<double> from a
//list<int>? From a vector<int>? Write code to check your answers.
int main()
{
  list<int> li={11,22,33,44,55};
  vector<double>vd1(li.begin(),li.end());
  for(const auto i:vd1)
  {
    cout << i << " ";
  }
  cout << endl;

  vector<int> vi={11,22,33,44,55};
  vector<double>vd2(vi.begin(),vi.end());
  for(const auto i:vd2)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
