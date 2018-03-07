#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

// Program to print quartiles.
// Two cases, if the number of numbers are 1) odd and 2) even.
//  0 1 2 3 4 5  6 7 8 9  10 11
// [1 2 3 4 5 6][7 8 9 10 11 12]
// Q1 = (3+4)/2, Q2 = (6+7)/2, Q3 = (9+10)/2
//
//  0 1 2 3 4  5 6 7 8 9
// [1 2 3 4 5][6 7 8 9 10]
// Q1=3, Q2= (5+6)/2, Q3 = 8
//
// So if it's even, simply find the median, then find the median of the
// two halves. If size/2 = size, then the sublists are:
// [0, mid-1][mid, size-1]
// 
//
//
//  0 1 2 3 4  5  6 7 8 9  10
// [1 2 3 4 5][6][7 8 9 10 11]
// Q1=3, Q2=6, Q3=9
//
//  0 1 2 3  4  5 6 7 8
// [1 2 3 4][5][6 7 8 9]
// Q1=(2+3)/2, Q2=5, Q3=(7+8)/2
//
// [0, mid-1][mid][mid+1,size-1]
using std::cout; using std::endl;
using std::vector; using std::cin;
using std::sort;

int main()
{
  cout << "Enter a list of numbers: " << endl;

  // Storage for the numbers
  vector<double> numbers;
  // The current read in number.
  double x;

  // invariant: numbers contain the numbers read in so far.
  while(cin >> x)
  {
    numbers.push_back(x);
  }

  typedef vector<double>::size_type vec_sz;
  vec_sz size = numbers.size();
  if(size == 0)
  {
    cout << endl << "You must enter some numbers. "
         "Please try again";
  }

  // sort the grades
  sort(numbers.begin(),numbers.end());

  // compute the median
  vec_sz mid=size/2;
  double median;
  median = size%2 ==0?(numbers[mid-1] + numbers[mid])/2
                     :numbers[mid];

  // Compute Q1
  double lowerq;
  double upperq;
  vec_sz quarter = mid/2;
  // First do for even numbers
  if(size%2==0)
  {
    lowerq=mid%2 ==0 ? (numbers[quarter-1] + numbers[quarter])/2
                  : numbers[quarter];
    upperq=mid%2==0? (numbers[mid+quarter-1] + numbers[mid+quarter])/2
                   :numbers[mid+quarter];

   
  }
  else
  // Now do for odd numbers:
  {
    lowerq= mid%2 ==0 ? (numbers[quarter-1] + numbers[quarter])/2
                  : numbers[quarter];

    // The magic here is the offset, since we have:
    // [0, mid-1][mid][mid+1,size-1]
    // we must offset by mid+1, rather than just mid.
    upperq=mid%2==0? (numbers[mid+1+quarter-1] + numbers[mid+1+quarter])/2
                   :numbers[mid+1+quarter];
  }
  
  // output:
  cout << "Median: " << median << endl;
  cout << "LowerQ: " << lowerq << endl;
  cout << "UpperQ: " << upperq << endl;

  return 0;
}
