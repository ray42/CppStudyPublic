#include<vector>
using std::vector;

#include<list>
using std::list;

#include<iterator>
using std::begin; using std::end;

#include<iostream>
using std::cout; using std::endl;

//Exercise 9.26: Using the following definition of ia, copy ia into a vector
//and into a list. Use the single-iterator form of erase to remove the
//elements with odd values from your list and the even values from your
//vector.
// int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
int main()
{
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

  vector<int> ivec(begin(ia),end(ia));
  list<int> ilist(begin(ia),end(ia));

  auto ilistit = ilist.begin();
  while(ilistit != ilist.end())
    if(*ilistit&1) // odd
    {
      ilistit = ilist.erase(ilistit);
    }
    else
    {
      ++ilistit;
    }
  
  for(auto i:ilist)
    cout << i<< " ";
  cout << endl;


  // Now for vector, remove even
  auto ivecit = ivec.begin();
  while(ivecit != ivec.end())
    if(*ivecit&1) // odd
    {
      ++ivecit;
    }
    else
    {
      ivecit = ivec.erase(ivecit);
    }

  for(auto i:ivec)
    cout << i << " ";
  cout << endl;

  return 0;
}
