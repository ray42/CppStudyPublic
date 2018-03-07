#include<iostream>
#include<sstream>

using std::cout; using std::endl; using std::cin;
using std::istringstream;

// Exercise 5.10: There is one problem with our vowel-counting program as
// we've implemented it: It doesn't count capital letters as vowels. Write a
// program that counts both lower- and uppercase letters as the appropriate
// vowel--that is, your program should count both 'a' and 'A' as part of
// aCnt, and so forth.
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
  char ch='\0';

  while(ss >> ch)
  {
    switch(ch)
    {
      case 'a': case 'A':
        ++aCnt;
        break;
      case 'e': case 'E':
        ++eCnt;
        break;
      case 'i': case 'I':
        ++iCnt;
        break;
      case 'o': case 'O':
        ++oCnt;
        break;
      case 'u': case 'U':
        ++uCnt;
        break;
    }
  }
  // print results
  cout << "Number of vowel a(A): \t" << aCnt << '\n'
       << "Number of vowel e(E): \t" << eCnt << '\n'
       << "Number of vowel i(I): \t" << iCnt << '\n'
       << "Number of vowel o(O): \t" << oCnt << '\n'
       << "Number of vowel u(U): \t" << uCnt << endl;

  return 0;
}
