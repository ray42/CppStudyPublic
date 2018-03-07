/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include"StrBlob27-28.h"
#include"./../common/rr.h"

#include<iostream>
using std::cout; using std::endl;

int main()
{
  rr::debug = true;

  {
    cout << "T1: default constructor" << endl;
    StrBlob sb;
    sb.printall() << endl << endl;
  }

  {
    cout << "T2: il constructor" << endl;
    StrBlob sb{"Hello", "There", "How", "Are", "You?"};
    sb.printall() << endl << endl;
  }

  {
    cout << "T3: copy constructor and pop_back" << endl;
    cout << "Copy constructor is defined to have valuelike behaviour"<<endl;
    StrBlob sb1{"Hello", "There", "How", "Are", "You?"};
    StrBlob sb2(sb1);
    sb1.printall() << endl;
    sb2.printall() << endl;
    cout << "Calling pop_back on sb2"<<endl;
    sb2.pop_back();
    sb1.printall() << endl;
    sb2.printall() << endl << endl;
  }

  {
    cout << "T4: copy assignment" << endl;
    StrBlob sb1{"Hello", "There", "How", "Are", "You?"};
    StrBlob sb2;
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
//    StrBlob sb1(StrBlob{"sum", "wan", "wan"});
    // to all the move c-tor, we need:
    StrBlob sb1(std::move(StrBlob{"sum", "wan", "wan"}));
    sb1.printall() << endl << endl;
  }

  {
    cout << "T6: move assign op" << endl;
    StrBlob sb1;
    sb1 = StrBlob{"sum", "wan", "wan"};
    sb1.printall() << endl << endl;
  }

  {
    rr::debug = false;
    cout << "T7: front and back, first nonconst, then const" << endl;
    StrBlob sb{"one", "two", "three"};
    const StrBlob csb{"cone", "ctwo", "cthree"};
    rr::debug = true;
    sb.printall() << endl;
    cout << sb.front() << ", " << sb.back() << endl;
    csb.printall() << endl;
    cout << csb.front() << ", " << csb.back() << endl<<endl;
  }

  {
    rr::debug = false;
    cout << "T8: Testing op== and op!=" << endl;
    StrBlob sb{"one", "two", "three"};
    const StrBlob csb{"cone", "ctwo", "cthree"};
    rr::debug = true;
    cout << (sb == sb) << endl;
    cout << (sb != sb) << endl;
    cout << (csb == sb) << endl;
    cout << (csb != sb) << endl;
    cout << endl<<endl;
  }

  {
    cout << "T9: ConstStrBlobPtr iterator equality." << endl;
    rr::debug = false;
    StrBlob sb{"Hello", "Ray", "Hello", "World"};

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr())
    {
        std::cout << iter.deref() << " ";
    }
    cout << "\n\n" << endl;
  }

  {
    rr::debug = false;
    cout << "T10: StrBlob relational operators: <, >, <=, <=" << endl;
    StrBlob sb1{"A", "B", "C", "D"};
    StrBlob sb2{"A", "C", "C", "D"};
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
    cout << "T11: StrBlobPtr relational operators: <, >, <=, <=" << endl;
    StrBlob sb1{"A", "B", "C", "D"};

    StrBlobPtr sbp1(sb1,1);
    StrBlobPtr sbp2(sb1,2);
    
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
    cout << "T12: StrBlob, StrBlobPtr op[]" << endl;
    StrBlob sb1{"A", "B", "C", "D"};
    cout << sb1[2] << endl;
    StrBlobPtr sp(sb1);
    cout << sp[0] << endl;
    cout << "\n" << endl;
  }
  {
    rr::debug = false;
    cout << "T13: ++, --, +=, -=, +, -" << endl;
    StrBlob sb{"A", "B", "C", "D", "E", "F", "G"};
    StrBlobPtr sbp(sb);
    cout << sbp.deref() << endl;
    sbp++;
    cout << sbp.deref() << endl;
    sbp--;
    cout << sbp.deref() << endl;
    sbp+=2;
    cout << sbp.deref() << endl;
    sbp-=2;
    cout << sbp.deref() << endl;
    StrBlobPtr sbp1 = sbp + 4;
    cout << sbp1.deref() << endl;
    StrBlobPtr sbp2= sbp1 - 4;
    cout << sbp2.deref() << endl;
  }

  return 0;
}
