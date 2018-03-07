/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include"./../common/rr.h"

class BinaryQuery:public Query_base
{
protected:
  BinaryQuery(const Query &l, const Query &r, const std::string &s)
  : lhs(l), rhs(r), opSym(s){}

  // abstract class: BinaryQuery doesn't define eval
  std::string rep() const
  {
    return "(" + lhs.rep + " "
               + opSym + " "
               + rhs.rep() + ")";
  }

  Query lhs, rhs; // right- and left-hand operands
  std::string opSym;
};


#endif


