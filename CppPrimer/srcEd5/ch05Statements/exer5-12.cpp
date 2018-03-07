#include<iostream>
#include<sstream>

using std::cout; using std::endl; using std::cin;
using std::istringstream;

// Exercise 5.12: Modify our vowel-counting program so that it counts the
// number of occurrences of the following two-character sequences: ff, fl,
// and fi.
int main()
{
  // test data:
  istringstream ss("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
      "Donec lacinia scelerisque orci et porttitor. Pellentesque id eros ornare,\n"
      "finibus lectus ut, malesuada enim.\t Curabitur semper suscipit dolor, a\n"
      "dignissim libero cursus at. Proin malesuada eu quam non facilisis.\n"
      "Aliquam mattis augue quis felis pharetra viverra. Nam maximus neque diam,\n"
      "a molestie dui bibendum ac. Donec \tac ante tortor. Nunc facilisis mattis\n"
      "dictum. Aenean maximus augue sit\t amet enim tempor pulvinar. Proin maximus\n"
      "turpis eu condimentum gravida. Class aptent taciti sociosqu ad litora\n"
      "torquent per conubia nostra, per inceptos himenaeos. Mauris massa diam,\n"
      "varius id mi in, lacinia ultrices libero. Vestibulum ante ipsum primis in\n"
      "faucibus orci luctus et ultrices posuere cubilia Curae; Suspendisse vel\n"
      "nunc ut dui posuere pellentesque.");
    
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  unsigned wsCnt = 0, tabCnt = 0, newlineCnt = 0;
  unsigned ffCnt = 0, flCnt = 0, fiCnt = 0; 
  char ch='\0';
  char previous_char='\0';

  // std::noskipws: no skip whitespace
  while(ss >> std::noskipws >> ch)
  {
    switch(ch)
    {
      case 'a': case 'A':
        ++aCnt;
        break;
      case 'e': case 'E':
        ++eCnt;
        break;
      case 'i': if(previous_char == 'f') ++fiCnt;
      case 'I':
        ++iCnt;
        break;
      case 'o': case 'O':
        ++oCnt;
        break;
      case 'u': case 'U':
        ++uCnt;
        break;
      case ' ':
        ++wsCnt;
        break;
      case '\t':
        ++tabCnt;
        break;
      case '\n':
        ++newlineCnt;
        break;
      case 'l': 
        if(previous_char == 'f') ++flCnt;
        break;
      case 'f':
        if(previous_char == 'f') ++ffCnt;
      break;
    }
    // update the previous char to the current char
    previous_char = ch;
  }
  // print results
  cout << "Number of vowel a(A): \t" << aCnt << '\n'
       << "Number of vowel e(E): \t" << eCnt << '\n'
       << "Number of vowel i(I): \t" << iCnt << '\n'
       << "Number of vowel o(O): \t" << oCnt << '\n'
       << "Number of vowel u(U): \t" << uCnt << '\n'
       << "Number of whitespace ' ': \t" << wsCnt << '\n'
       << "Number of tabs: \t" << tabCnt << '\n'
       << "Number of newlines: \t" << newlineCnt <<  '\n'
       << "Number of ff chars: \t" << ffCnt <<  '\n'
       << "Number of fl chars: \t" << flCnt <<  '\n'
       << "Number of fi chars: \t" << fiCnt <<  endl;

  return 0;
}
