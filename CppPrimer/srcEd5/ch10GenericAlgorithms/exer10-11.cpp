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
//Exercise 10.11: Write a program that uses stable_sort and isShorter
//to sort a vector passed to your version of elimDups. Print the vector to
//verify that your program is correct.
bool isShorter(const string&s1, const string&s2)
{
  return s1.size() < s2.size();
}

int main()
{
  std::vector<std::string> vs{"the","quick","red","fox","jumps","over", 
                              "the", "slow", "red", "turtle"};
  vector<string> vu=elimDups(vs);
  std::cout << "elim dups:" << std::endl;
  for(const auto& i:vs)
    std::cout << i << " ";
  std::cout << std::endl;

  std::stable_sort(vs.begin(),vs.end(),isShorter);
  std::cout << "sorted by length" << std::endl;
  for(const auto& i:vs)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
