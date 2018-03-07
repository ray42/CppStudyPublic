/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"Blob24.h"
#include"./../common/rr.h"

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::endl;

int main()
{
  rr::debug = true;

{
  cout << "T1: default constructor" << endl;
  Blob<string> sb;
  sb.printall() << endl << endl;
}
{
  cout << "T2: il constructor" << endl;
  Blob<string> sb{"Hello", "There", "How", "Are", "You?"};
  sb.printall() << endl << endl;
}

{
  cout << "T3: copy constructor and pop_back" << endl;
  cout << "Copy constructor is defined to have valuelike behaviour"<<endl;
  Blob<string> sb1{"Hello", "There", "How", "Are", "You?"};
  Blob<string> sb2(sb1);
  sb1.printall() << endl;
  sb2.printall() << endl;
  cout << "Calling pop_back on sb2"<<endl;
  sb2.pop_back();
  sb1.printall() << endl;
  sb2.printall() << endl << endl;
}

{
  cout << "T4: copy assignment" << endl;
  Blob<string> sb1{"Hello", "There", "How", "Are", "You?"};
  Blob<string> sb2;
  sb2 = sb1;
  sb1.printall() << endl;
  sb2.printall() << endl;
  cout << "Calling pop_back on sb2"<<endl;
  sb2.pop_back();
  sb1.printall() << endl;
  sb2.printall() << endl << endl;
}

{
  cout << "T5: move constructor" << endl;
  // Note: if we do this, the temporary is optimized away
//  Blob<string> sb1(Blob<string>{"sum", "wan", "wan"});
  // to call the move c-tor, we need:
  Blob<string> sb1(std::move(Blob<string>{"sum", "wan", "wan"}));
  sb1.printall() << endl << endl;
}

{
  cout << "T6: move assign op" << endl;
  Blob<string> sb1;
  sb1 = Blob<string>{"sum", "wan", "wan"};
  sb1.printall() << endl << endl;
}

{
  rr::debug = false;
  cout << "T7: front and back, first nonconst, then const" << endl;
  Blob<string> sb{"one", "two", "three"};
  const Blob<string> csb{"cone", "ctwo", "cthree"};
  rr::debug = true;
  sb.printall() << endl;
  cout << sb.front() << ", " << sb.back() << endl;
  csb.printall() << endl;
  cout << csb.front() << ", " << csb.back() << endl<<endl;
}

{
  rr::debug = false;
  cout << "T8: Testing op== and op!=" << endl;
  Blob<string> sb{"one", "two", "three"};
  const Blob<string> csb{"cone", "ctwo", "cthree"};
  rr::debug = true;
  cout << (sb == sb) << endl;
  cout << (sb != sb) << endl;
  cout << (csb == sb) << endl;
  cout << (csb != sb) << endl;
  cout << endl<<endl;
}

{
  cout << "T9: ConstBlobPtr iterator equality." << endl;
  rr::debug = false;
  Blob<string> sb{"Hello", "Ray", "Hello", "World"};

  for (ConstBlobPtr<string> iter = sb.cbegin(); iter != sb.cend(); 
      iter.incr())
  {
      std::cout << iter.deref() << " ";
  }
  cout << "\n\n" << endl;
}

{
  rr::debug = false;
  cout << "T10: Blob relational operators: <, >, <=, <=" << endl;
  Blob<string> sb1{"A", "B", "C", "D"};
  Blob<string> sb2{"A", "C", "C", "D"};
  rr::debug=true;
  cout << "sb1 < sb1: " << (sb1 < sb1) << endl;
  cout << "sb1 < sb2: " << (sb1 < sb2) << endl;
  cout << "sb2 < sb1: " << (sb2 < sb1) << endl;
  cout << "\n" << endl;
  cout << "sb1 > sb1: " << (sb1 > sb1) << endl;
  cout << "sb1 > sb2: " << (sb1 > sb2) << endl;
  cout << "sb2 > sb1: " << (sb2 > sb1) << endl;
  cout << "\n" << endl;
  cout << "sb1 <= sb1: " << (sb1 <= sb1) << endl;
  cout << "sb1 <= sb2: " << (sb1 <= sb2) << endl;
  cout << "sb2 <= sb1: " << (sb2 <= sb1) << endl;
  cout << "\n" << endl;
  cout << "sb1 >= sb1: " << (sb1 >= sb1) << endl;
  cout << "sb1 >= sb2: " << (sb1 >= sb2) << endl;
  cout << "sb2 >= sb1: " << (sb2 >= sb1) << endl;
  cout << "\n\n"<<endl;
}

  //////////////////////////////////////////////////////////////////////////

  {
    rr::debug = false;
    cout << "T11: BlobPtr relational operators: <, >, <=, <=" << endl;
    Blob<string> sb1{"A", "B", "C", "D"};

    BlobPtr<string> sbp1(sb1,1);
    BlobPtr<string> sbp2(sb1,2);
    
    rr::debug=true;
    cout << "sbp1 < sbp1: " << (sbp1 < sbp1) << endl;
    cout << "sbp1 < sbp2: " << (sbp1 < sbp2) << endl;
    cout << "sbp2 < sbp1: " << (sbp2 < sbp1) << endl;
    cout << "\n" << endl;
    cout << "sbp1 > sbp1: " << (sbp1 > sbp1) << endl;
    cout << "sbp1 > sbp2: " << (sbp1 > sbp2) << endl;
    cout << "sbp2 > sbp1: " << (sbp2 > sbp1) << endl;
    cout << "\n" << endl;
    cout << "sbp1 <= sbp1: " << (sbp1 <= sbp1) << endl;
    cout << "sbp1 <= sbp2: " << (sbp1 <= sbp2) << endl;
    cout << "sbp2 <= sbp1: " << (sbp2 <= sbp1) << endl;
    cout << "\n" << endl;
    cout << "sbp1 >= sbp1: " << (sbp1 >= sbp1) << endl;
    cout << "sbp1 >= sbp2: " << (sbp1 >= sbp2) << endl;
    cout << "sbp2 >= sbp1: " << (sbp2 >= sbp1) << endl;
    cout << "\n"<<endl;
  }
  {
    rr::debug = false;
    cout << "T12: Blob, BlobPtr op[]" << endl;
    Blob<string> sb1{"A", "B", "C", "D"};
    cout << sb1[2] << endl;
    BlobPtr<string> sp(sb1);
    cout << sp[0] << endl;
    cout << "\n" << endl;
  }
  {
    // exer 27, 28
    rr::debug = false;
    cout << "T13: ++, --, +=, -=, +, -" << endl;
    Blob<string> sb{"A", "B", "C", "D", "E", "F", "G"};
    BlobPtr<string> sbp(sb);
    cout << sbp.deref() << endl;
    sbp++;
    cout << sbp.deref() << endl;
    sbp--;
    cout << sbp.deref() << endl;
    sbp+=2;
    cout << sbp.deref() << endl;
    sbp-=2;
    cout << sbp.deref() << endl;
    BlobPtr<string> sbp1 = sbp + 4;
    cout << sbp1.deref() << endl;
    BlobPtr<string> sbp2= sbp1 - 4;
    cout << sbp2.deref() << endl;
  }
  {
    // exer 30
    rr::debug = false;
    cout << "T14: op* op->" << endl;
    Blob<string> sb{"A", "BB", "C", "D", "E", "F", "G"};
    BlobPtr<string> sbp(sb);
    ++sbp;
    cout << *sbp << endl;
    cout << sbp->size() << endl;

    // repeat with const just to see if it works.
    const Blob<string> csb{"A", "BB", "C", "D", "E", "F", "G"};
    ConstBlobPtr<string> csbp(csb);
    ++csbp;
    cout << *csbp << endl;
    cout << csbp->size() << endl;
    // it works!
  }

  {
    rr::debug = false;
    cout << "T15: testing iter range constructor for Blob" << endl;
    // testing out new iter range constructor
    vector<string> strvec{"iter", "range", "constructor"};
    Blob<string> sb(strvec.cbegin(),strvec.cend());
    sb.printall() << endl;
  }

  rr::greet(__PRETTY_FUNCTION__);
  return 0;
}
