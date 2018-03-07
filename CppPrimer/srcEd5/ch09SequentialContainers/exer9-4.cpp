#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::endl;

//Exercise 9.4: Write a function that takes a pair of iterators to a
//vector<int> and an int value. Look for that value in the range and return
//a bool indicating whether it was found.
bool find(vector<int>::const_iterator beg, 
          vector<int>::const_iterator end, int val)
{
  for (auto iter=beg; iter!=end; ++iter) 
  {
    if(*iter == val) return true;
  }
  return false;
}

//Exercise 9.5: Rewrite the previous program to return an iterator to the
//requested element. Note that the program must handle the case where the
//element is not found.
vector<int>::iterator findv2(vector<int>::iterator beg, 
                             vector<int>::iterator end, int val)
{
  for (auto iter=beg; iter!=end; ++iter) 
  {
    if(*iter == val) return iter;
  }
  return end;
}

int main()
{

  vector<int> v{0,1,2,3,4,5,6,7,8,9};
  cout << find(v.cbegin(),v.cend(),2) << endl;
  cout << find(v.cbegin(),v.cend(),42) << endl;

  auto it1=findv2(v.begin(),v.end(),2);
  auto it2=findv2(v.begin(),v.end(),42);

  cout << *it1 << endl;
  cout << *it2 << endl;

  return 0;
}
