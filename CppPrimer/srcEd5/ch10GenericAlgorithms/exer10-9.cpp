#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using std::string;
using std::vector;

// lets practice trailing return types
template<typename T>
auto elimDups(vector<T>&vec)->vector<T>&
{
  // first sort
  std::sort(vec.begin(),vec.end());
  vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
  return vec;
}

int main()
{
  std::vector<std::string> vs{ "a", "v", "a", "s", "v", "a", "a" };
  vector<string> vu=elimDups(vs);
  for(auto i:vs)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
