#include<iostream>
#include<sstream>

using std::cout; using std::endl; using std::cin;
using std::istringstream;

// Exercise 5.9: Write a program using a series of if statements to count 
// the number of vowels in text read from cin.
int main()
{
  // test data:
  istringstream ss("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
      "Donec lacinia scelerisque orci et porttitor. Pellentesque id eros ornare,\n"
      "finibus lectus ut, malesuada enim. Curabitur semper suscipit dolor, a\n"
      "dignissim libero cursus at. Proin malesuada eu quam non facilisis.\n"
      "Aliquam mattis augue quis felis pharetra viverra. Nam maximus neque diam,\n"
      "a molestie dui bibendum ac. Donec ac ante tortor. Nunc facilisis mattis\n"
      "dictum. Aenean maximus augue sit amet enim tempor pulvinar. Proin maximus\n"
      "turpis eu condimentum gravida. Class aptent taciti sociosqu ad litora\n"
      "torquent per conubia nostra, per inceptos himenaeos. Mauris massa diam,\n"
      "varius id mi in, lacinia ultrices libero. Vestibulum ante ipsum primis in\n"
      "faucibus orci luctus et ultrices posuere cubilia Curae; Suspendisse vel\n"
      "nunc ut dui posuere pellentesque.");
    
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  char ch;
  while(ss >> ch)
  {
    if (ch == 'a')
      ++aCnt;
    else if (ch == 'e')
      ++eCnt;
    else if (ch == 'i')
      ++iCnt;
    else if (ch == 'o')
      ++oCnt;
    else if (ch == 'u')
      ++uCnt;
  }
  // print results
  cout << "Number of vowel a: \t" << aCnt << '\n'
       << "Number of vowel e: \t" << eCnt << '\n'
       << "Number of vowel i: \t" << iCnt << '\n'
       << "Number of vowel o: \t" << oCnt << '\n'
       << "Number of vowel u: \t" << uCnt << endl;

  return 0;
}
