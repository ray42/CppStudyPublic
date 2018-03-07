/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */

#ifndef AND_QUERY_H
#define AND_QUERY_H


#include"./../common/rr.h"

class AndQuery: public BinaryQuery
{
  friend Query operator& (const Query&, const Query&);

  AndQuery(const Query& left, const Query& right)
    : BinaryQuery(left,right,"&"){}

  // concrete class: AndQuery inherits rep and defines the remaining pure
  // virtual, eval.
  QueryResult eval(const Text&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

#endif




