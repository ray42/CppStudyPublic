#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::endl;

#include<iterator>
using std::advance;

#include<forward_list>
using std::forward_list;

int main()
{
  // silly loop to remove even-valued elements 
  // and insert a duplicate of odd-valued elements
  forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto prev_iter = vi.before_begin();
  auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
  while (iter != vi.end())
  {
    if (*iter % 2) // true if odd
    { 
      iter = vi.insert_after(prev_iter, *iter);  // duplicate the current element
      // Note that insert will insert the element BEFORE iter. So to get to
      // the next unprocessed element, we must advance two times:
      std::advance(iter,2); // new part of the code.
      std::advance(prev_iter,2);

//      iter += 2; // advance past this element and the one inserted before it
    } 
    else // else is even
    { 
      iter = vi.erase_after(prev_iter);          // remove even elements
      // don't advance the iterator; iter denotes the element after the one we erased
    }
  }

  for(auto i:vi)
    cout << i << " ";
  cout << endl;

  return 0;
}



