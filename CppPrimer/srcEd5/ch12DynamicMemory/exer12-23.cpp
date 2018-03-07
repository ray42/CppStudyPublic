/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<cstring>

// Exercise 12.23: Write a program to concatenate two string literals, putting
// the result in a dynamically allocated array of char . Write a program to
// concatenate two library strings that have the same value as the literals
// used in the first program.

void ex23()
{
  // Recap on string literals and null terminated strings.
  char ca[3] = {'A', 'B', 'C'}; // not null terminated.
  cout << "strlen(ca) " << strlen(ca) << endl;

  // Null terminated
  char ca2[] = "ABC";
  cout << "strlen(ca2) " << strlen(ca2) << endl;
  // Note, although ca2 does have the null character '\0', 

  // The difference can be seen with the sizeof operator
  // http://stackoverflow.com/questions/14905937/is-that-char-null-terminator-is-including-in-the-length-count
  //
  // strlen: Returns the length of the given byte string, 
  //         not including null terminator;
  // sizeof: Returns the length of the given byte string, 
  //         include null terminator;
  cout << "sizeof(ca) "<<sizeof(ca) << endl;
  cout << "sizeof(ca2) "<<sizeof(ca2) << endl;
  cout << "strlen(\"Hi\") "<< strlen("hi")<<endl;
  cout << "sizeof(\"Hi\") "<< sizeof("hi")<<endl;
  cout <<endl;

  // Now back to the exercise
  size_t nchars=strlen("Cat") + strlen("Dog")+1; // 1 for null char.

  char *charstr = new char[7];
  cout << "sizeof(charstr) " << sizeof(charstr) << endl;
  strcpy(charstr,"Cat");
  strcat(charstr,"Dog");
  cout << "nchars " << nchars << endl;
  cout << "charstr " << charstr << endl;
  cout << "strlen(charstr) " << strlen(charstr) << endl;

  // this gives the size of the pointer, not the size of the array.
  // this is one of the main difference between declaring char arr[num] and
  // char* arr= new char[num];, since in the first one, the size of a part 
  // of the array type. This is not the case with dynamic arrays.
  cout << "sizeof(charstr) " << sizeof(charstr) << endl;
  delete [] charstr; // Don't forget to delete!

  string cat="Cat";
  string dog="Dog";
  string catdog = cat+dog;
  cout << "catdog " << catdog << endl;
}

int main()
{
  ex23();
  return 0;
}
