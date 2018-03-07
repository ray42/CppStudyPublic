/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<iomanip>

int main()
{
  //////////////////////////////////////////////////////////////////////////
  // iostream
  //boolalpha Display true and false as strings
  cout << true << " " << false << endl;
  cout << std::boolalpha << true << " " << false << endl;
  //noboolalpha Display true and false as 0, 1
  cout << std::noboolalpha << true << " " << false << endl;
  cout << endl;
 
  //showbase Generate prefix indicating the numeric base of integral values
  cout << std::showbase << std::dec << 42 << endl;
  cout << std::showbase << std::hex << 42 << endl;
  //noshowbase Do not generate notational base prefix
  cout << std::noshowbase << std::dec << 42 << endl;
  cout << std::noshowbase << std::hex << 42 << endl;
  cout << endl;

  //showpoint Always display  decimal point for floating-point values
  cout << std::showpoint << 42 << endl;
  //noshowpoint Display a decimal only if the value has a fractional part
  cout << std::noshowpoint << 42 << endl;

  //showposDisplay + in nonnegative numbers
  //noshowposDo not display + in nonnegative numbers
  //uppercasePrint 0X in hexadecimal, E in scientific
  //nouppercasePrint 0x in hexadecimal, e in scientific
  //decDisplay integral values in decimal numeric base
  //hexDisplay integral values in hexadecimal numeric base
  //octDisplay integral values in octal numeric base
  //leftAdd fill characters to the right of the value
  //rightAdd fill characters to the left of the value
  //internalAdd fill characters between the sign and the value
  //fixedDisplay floating-point values in decimal notation
  //scientificDisplay floating-point values in scientific notation
  //hexfloatDisplay floating-point values in hex (new to C++11)
  //defaultfloatReset the floating-point format to decimal (new to C++11)
  //unitbufFlush buffers after every output operation
  //nounitbufRestore normal buffer flushing
  //skipwsSkip whitespace with input operators
  //noskipwsDo not skip whitespace with input operators
  //flushFlush the ostream buffer
  //endsInsert null, then flush the ostream buffer
  //endlInsert newline, then flush the ostream buffer

  //////////////////////////////////////////////////////////////////////////
  // iomanip
  //setfill(ch)Fill whitespace with ch
  //setprecision(n)Set floating-point precision to n
  //setw(w)Read or write value to w} characters
  //setbase(b)Output integers in base b
 
  return 0;
}

