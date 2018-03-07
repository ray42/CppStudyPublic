/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;


class TreeNode
{
public:
  // First we decide if we want valuelike or pointer like behaviour.
  // When we copy a TreeNode, we do not copy the objects pointed to by
  // *left and *right.
  //
  // WHAT WE DO NOT WANT: When we delete the copied object, is for it to
  // delete it's left and right child. Since the orginal might still need 
  // it.

  TreeNode():{}
  // Actually not done, this doesn't make much sense without more
  // specification. I need to know what is required in terms of 
  // functionality.




private:
  // Value of the node.
  std::string value;
  
  // Count how many instances of this pointer.
  size_t *count;

  // Left and right child.
  TreeNode *left;
  TreeNode *right;
};


class BinStrTree
{
private:
  TreeNode *root;
};

int main()
{
  return 0;
}

