/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;

#include<algorithm>
using std::for_each;
using std::transform;
using std::copy;

#include<iterator>
using std::ostream_iterator;

#include<list>
using std::list;

//Exercise 10.34: Use reverse_iterators to print a vector in reverse
//order.
void ex34()
{
  cout << "Ex 34 with for_each" << endl;
  vector<int> v{1,2,3,4,5,6,7,8,9};
  for_each(v.crbegin(),v.crend(),
      [](const int i){cout << i << " ";});
  cout << endl;

  cout << "Ex 34 with transform and iterator adaptor" << endl;
  // again but with stream iterator, to I don't forget it.
  // Note: The difference in use between for_each seems to be that in 
  // transform, we can put the result into another iterator.
  transform(v.crbegin(),v.crend(),ostream_iterator<int>(cout," "),
      [](const int i){return i;});
  cout << endl;
}

//Exercise 10.35: Now print the elements in reverse order using ordinary
//iterators.
void ex35()
{
  cout << "Ex 35 with .base()" << endl;
  //           rend.base()
  //       rend |
  //          | |
  vector<int> v{1,2,3,4,5,6,7,8,9};
  copy(v.crend().base(),v.cend(),ostream_iterator<int>(cout, " "));
  cout << endl;
}

//Exercise 10.36: Use find to find the last element in a list of ints with
//value 0.
void ex36()
{
  //                          8th element.
  list<int>il{0,1,0,2,3,5,7,9,0,5,3,6};
  auto it=find(il.crbegin(),il.crend(),0);
  // is it a reverse iterator?
  cout << *it << endl;
  ++it;
  cout << *it << endl;
  // yes it is, because incrementing it gives 9, i.e. it's going backwards
  // towards the front (towards rbegin).
}

//Exercise 10.37: Given a vector that has ten elements, copy the elements
//from positions 3 through 7 in reverse order to a list.
void ex37()
{
  //               (     <-  ]
  vector<int>v{0,1,2,3,4,5,6,7,8,9};
  //         ^rend               ^rbegin
  //               ^rend-3   ^rbegin+2
  //
  //So I need to copy from rbegin+2 to rend-4
  
  list<int>l;
  copy(v.crbegin()+2,v.crend()-3,back_inserter(l));
  
  // Lets print it:
  copy(l.cbegin(),l.cend(),ostream_iterator<int>(cout," "));
  cout << endl;
}

int main()
{
  ex34();
  ex35();
  ex36();
  ex37();

  return 0;
}

