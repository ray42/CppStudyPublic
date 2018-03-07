#include<iostream>
using std::cout; using std::endl;

#include<ostream>
using std::ostream;

#include"StrBlob.h"


int main()
{
  cout << "Start of ex12-19\n" << endl;
  
  StrBlob sb1;
  
  cout << sb1.printAll() << endl;
  
  // Now put some elements in.
  sb1.push_back("Ray1");
  sb1.push_back("Ray2");
  sb1.push_back("Ray3");
  cout << sb1.printAll() << endl;
  cout << "sb1.front " << sb1.front() << endl;
  cout << "sb1.back " << sb1.back() << endl;
  sb1.pop_back();
  cout << sb1.printAll() << endl;

  // Now test the list constructor
  StrBlob sb2{"Jo1","Jo2","Jo3"};
  cout << sb2.printAll() << endl;

  // Okay, all of that works, now testing StrBlobPtr.

  cout << "Using StrBlobPtr to print" << endl;

  for(StrBlobPtr pbeg(sb1.begin()), 
                 pend(sb1.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
  
  //  for(auto beg = sb1.begin(); beg != sb1.end(); sb1.incr())
//  {
//    cout << sb1.deref() << endl;
//  }



  cout << "\nEnd of ex12-19" << endl;
  return 0;
}

