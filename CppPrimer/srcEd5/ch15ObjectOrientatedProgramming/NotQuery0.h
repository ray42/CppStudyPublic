/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef NOTQUERY_H
#define NOTQUERY_H


class NotQuery:public Query_base
{
  friend Query operator~(const Query &);

  Notquery(const Query &q):query(q){}

  // concrete class: Notquery defines all inherited pure virtual functions
  std::string rep() const {return "~("+query.rep()+")";}
  QueryResult eval(const TextQuery &) const;

  Query query;

};

inline Query operator~(const Query &operand)
{
  return std:shared_ptr<Query_base>(new NotQuery(operand));
}

#endif

