#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;

int main()
{
  vector<int> vi{1,2,3,4,5};

  auto iter = vi.begin();
  while (iter != vi.end())
  if (*iter % 2)
  {
    iter = vi.insert(iter, *iter);
    iter+=2; // if odd, we advance twice
  }else
  {
    ++iter; // if even, advance once.
  }

  for(auto i:vi)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
