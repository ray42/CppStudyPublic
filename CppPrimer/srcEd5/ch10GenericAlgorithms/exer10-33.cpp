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

#include<fstream>
using std::ofstream; using std::ifstream;

#include<iterator>
using std::istream_iterator; using std::ostream_iterator;


//Exercise 10.33: Write a program that takes the names of an input file and
//two output files. The input file should hold integers. Using an
//istream_iterator read the input file. Using ostream_iterators, write
//the odd numbers into the first output file. Each value should be followed 
//by a space. Write the even numbers into the second file. Each of these 
//values should be placed on a separate line.
int main(int argc, char** argv)
{
  if(argc != 4)
  {
    cout << "Please supply 3 arguments:" << endl;
    cout << "Input file, Outfile1, Outfile2" << endl;
    return 1;
  }

  ifstream infile(argv[1]);
  ofstream ofodd(argv[2]);
  ofstream ofeven(argv[3]);

  // This is the cause of error:
  //istream_iterator<int> isiter((ifstream(argv[1])));

  // This works:
  istream_iterator<int> isiter(infile); 
  istream_iterator<int> isiterend;
  // the ostream to the below cannot be rvalues
  ostream_iterator<int> ositerOdd(ofodd," ");
  ostream_iterator<int> ositerEven(ofeven," ");
 
  while(isiter != isiterend)
  {
    *isiter&1? ositerOdd=*isiter : ositerEven=*isiter;
    ++isiter;
  }

// The above works, but Moophy's solution is interesting:
//std::ifstream ifs(argv[1]);
//std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);
//
//std::istream_iterator<int> in(ifs), in_eof;
//std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");
//
//std::for_each(in, in_eof, [&out_odd, &out_even](const int i){
//      *(i & 0x1 ? out_odd : out_even)++ = i;
//});
// 

  return 0;
}
