/*==========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * Code for the exercises from C++ Primer 5th Edition
 *==========================================================================
 */
#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include"./../common/rr.h"

// abstract class acts as a base class for concrete query types;
// all members are private
class Query_base
{
  friend class Query;

protected:
  using line_no = TextQuery::line_no; // used in the eval function
  virtual ~Query_base() = default;

private:
  // eval returns the QueryResult that matches this Query
  virtual QueryResult eval(const TextQuery&) const = 0;
  // rep is a string representation of the query
  virtual std::string rep() const = 0;
};

#endif


