#include<iostream>
using std::cout; using std::endl;

#include<forward_list>
using std::forward_list;

#include<string>
using std::string;


//Exercise 9.27: Write a program to find and remove the odd-valued
//elements in a forward_list<int>.
void findRemoveOdd()
{
  forward_list<int> flst{0,1,2,3,4,5,6,7,8,9,11,7,2};

  // I need the previous iter to remove what's pointed to by the current 
  // iter
  
  // the element "off the start" of flst
  forward_list<int>::iterator prev = flst.before_begin();
  // the first element in flst
  forward_list<int>::iterator curr = flst.begin();
  // while there are still elements to process
  while(curr != flst.end())
    if(*curr&1) // if the element is odd
    {
      // erase it and move curr, no need to move prev since the prev element
      // has not moved.
      curr = flst.erase_after(prev);
    }
    else
    {
      // move the iterators to denote the next element and 
      // one before the next.
      // This is equivalent to prev=curr; ++curr;
      prev = curr++;
    }

  for(auto i :flst)
    cout << i << " ";
  cout << endl;
}

//Exercise 9.28: Write a function that takes a forward_list<string> and
//two additional string arguments. The function should find the first string
//and insert the second immediately following the first. If the first string 
//is not found, then insert the second string at the end of the list.
void findInsert(forward_list<string> &flst, 
                const string &findStr,
                const string &insertStr)
{
  forward_list<string>::iterator curr=flst.begin();
  forward_list<string>::iterator prev=flst.before_begin();

  // curr will go from [beg,end]
  // prev will go from [beg-1,end-1]
  while(curr != flst.end())
  {
    if((*curr) == findStr)
    {
      flst.insert_after(curr,insertStr);
      return;
    }
    else
    {
      prev=curr++;
    }
  }
  // Now prev is at end-1, so we insert it. Since if we got here, it means
  // we have not found findStr.
  flst.insert_after(prev,insertStr);
}

int main()
{
  findRemoveOdd();

  forward_list<string> l1={"A","B","C","D"};

  findInsert(l1,"A","X");
  for(const auto& s:l1)
    cout << s << " ";
  cout << endl;
  
  l1={"A","B","C","D"};
  findInsert(l1,"B","X");
  for(const auto& s:l1)
    cout << s << " ";
  cout << endl;

  l1={"A","B","C","D"};
  findInsert(l1,"D","X");
  for(const auto& s:l1)
    cout << s << " ";
  cout << endl;

  l1={"A","B","C","D"};
  findInsert(l1,"E","X");
  for(const auto& s:l1)
    cout << s << " ";
  cout << endl;

  return 0;
}
