/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include "Message.h"
#include "Folder.h"

int main()
{
  cout <<"Start ex33\n\n"<< endl;
  
  Message msg("This is a message");
  msg.printall();
  cout <<endl;

//  Folder fdr("folder1");
//  fdr.printall();
//  cout <<endl;

//  msg.save(fdr);
//  msg.printall();
//  cout <<endl;

//  fdr.printall();
//  cout <<endl;


  cout <<"\n\nEnd ex33"<< endl;
  return 0;
}

