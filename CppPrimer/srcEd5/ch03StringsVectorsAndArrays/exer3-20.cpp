#include<iostream>
#include<vector>
#include<string>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::vector;
using std::string;
using std::to_string;

int main()
{
  // Read a set of integers into a vector. Print the sum of each pair of 
  // adjacent elements. 
  int currentint;
  vector<int> intvec;
  cout << "Please enter a list of integers" << endl;
  while(cin >> currentint)
    intvec.push_back(currentint);

  // Now print the sum of each pair. We need at least two numbers.
  if(intvec.size() < 2)
  {
    cerr << "Please supply at least two numbers" << endl;
  }

  // We go from position 0 to position size-1 and add the current and next
  // value
  for(decltype(intvec.size()) i=0; i < intvec.size()-1; ++i)
  {
    cout << intvec[i] + intvec[i+1] << " ";
  }
  cout << endl;

  // Change your program so that it prints the sum of the first and last
  // elements, followed by the sum of the second and second-to-last, and so 
  // on.
  
  // There are two obvious cases, if the number of inputs are even or odd.
  // 1) Even: We simply add the numbers
  // 2) Odd: When we get to the middle, we will add the middle to itself.
  decltype(intvec.size()) mid = intvec.size()/2;
  for(decltype(intvec.size()) i = 0; i < mid; ++i)
  {
    cout << intvec[i] + intvec[intvec.size()-i-1] << " ";
  }

  // If odd, print out the middle times two.
  cout << ((intvec.size()%2==0)?"":to_string(intvec[mid]*2)) << endl;
  return 0;
}
