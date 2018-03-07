#include<list>
using std::list;

#include<deque>
using std::deque;

#include<iostream>
using std::cout; using std::endl;

//Exercise 9.20: Write a program to copy elements from a list<int> into
//two deques. The even-valued elements should go into one deque and the
//odd ones into the other.
int main()
{
  list<int>ilist{0,1,2,3,4,5,6,7,8};
  deque<int> odd, even;

  for(auto i:ilist)
    (i&1 ? odd:even).push_back(i);

  // How does this work? Okay, what determines if a number is odd or even?
  // It's the least significant digit. 
  // i.e. 343421, it's odd due to the 1.
  //      3436, it's even due to the 6.
  //
  // Now, in binary, the least significant digit is either a 0 or 1, 
  // 0 means even, 1 means odd.
  //
  // If we AND a number with 1, we actually AND the binary representation of
  // the number and ...0000000001, in which case, if this is 1, it's odd.
  // Otherwise it's even.
  //
  // Now, if it's 1 => odd => true.
  //      if it's 0 => even => false.

  for(auto i:odd) cout << i << " ";
  cout << endl;
  for(auto i:even) cout << i << " ";
  cout << endl;

  return 0;
}
