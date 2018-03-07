#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cout; using std::endl;
using std::unique;

int main()
{
  vector<int> v{1,1,2,2,1,1,2,2};
  auto unique_end = unique(v.begin(),v.end());
  for(auto i:v) 
    cout << i << " "; // 1 2 1 2 | 1 1 2 2
  cout << endl;

  for(auto b = v.begin(); b!= unique_end; ++b)
    cout << *b << " "; // 1 2 1 2
  cout << endl;

  return 0;
}
