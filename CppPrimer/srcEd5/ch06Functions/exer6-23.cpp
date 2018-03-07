#include<iostream>

using std::cout; using std::endl;

#include<iterator>
using std::begin; using std::end;


void print(const int* pi)
{
  if (pi) cout << *pi << endl;
}


// using a marker to specify the extent of an array:
void print(const char *cp)
{
  if(cp) // if cp is not null
    while (*cp)// so long as the character it points to is not a null char
      cout << *cp++; // print the character and advance the pointer
  cout << endl;
}

// Using the Standard Library Conventions
void print(const int* beg, const int* end)
{
  while(beg != end)
    cout << *beg++ << endl; // print the current element
                            // and advance the pointer
}

// Explicitly passing a size parameter
// const int ia[] is equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print(const int ia[], size_t size)
{
  for(size_t i = 0; i!= size; ++i)
    cout << ia[i] << endl;
}

// Array reference parameters
void print(int (&arr)[2])
{
  for(auto elem:arr)
    cout << elem << endl;
}
//Exercise 6.23: Write your own versions of each of the print functions 
//presented in this section. Call each of these functions to print i and j 
//defined as follows: int i = 0, j[2] = {0, 1} ;
int main()
{
  int i = 0;
  int j[2]={0,1};

  char ch[4] = "Ray";

  print(&i);
  print(ch);
  print(begin(j),end(j));
  print(j,end(j)-begin(j));
  print(j);


  return 0;
}
