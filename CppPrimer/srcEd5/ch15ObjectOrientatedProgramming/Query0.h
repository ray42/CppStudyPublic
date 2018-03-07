/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef QUERY_H
#define QUERY_H


#include"./../common/rr.h"

// interface class to manage the Query_base inheritance hierarhy
class Query
{
  // these operators need access to the shared_ptr constructor
  // These return a Query object, bound to its newly created object
  // which is a shared_ptr<Query_base>. To support these operations
  // we will have a (private) Query constructor which takes a 
  // shared_ptr<Query_base>.
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);

public:
  //////////////////////////////////////////////////////////////////////////
  // C-tor builds new WordQuery
  // we declare, but cannot yet define, the constructor that takes a 
  // string. This constructor creates WordQuery object, so we cannot define
  // this constructor until we have defined the WordQuery class.
  Query(const std::string&);

  //////////////////////////////////////////////////////////////////////////
  // interface functions: call the corresponding Query_base operations

  // takes a TextQuery object and returns a QueryResult. The eval function 
  // will use the given TextQuery object to find the query's matching lines.
  QueryResult eval(const TextQuery& t) const {return p->eval(t);}

  // returns the string representation of th underlying query. This function
  // will be used by eval to create QueryResult representing the match and
  // by output operator to print the query expressions.
  std::string rep() const {return p->rep()};

private:
  // stores it's given pointer. Called by the operators above.
  Query(std::shared_ptr<Query_base> query):q(query){}

  // the pointer to Query_base.
  std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream &os, const Query &query)
{
  // Query::rep makes the virtual call through its Query_base pointer to rep()
  return os << query.rep();
}


#endif





