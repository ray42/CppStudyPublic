/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */

#include"Sales_data4-5-6-7-8.h"
#include<iostream>
using std::cout; using std::endl; using std::istream; using std::ostream;

#include<sstream>
using std::ostringstream;
using std::istringstream;

#include<functional> // less

#include<vector>
using std::vector;

#include<utility>
using std::make_tuple;
using std::get;
using std::pair;
using std::make_pair;

#include<tuple>
using std::tuple;

#include<string>
using std::string;

#include<algorithm>
using std::equal_range;

#include<numeric>
using std::accumulate;



// template declarations
template<typename T> int compare(const T &v1, const T &v2);

// exer17-4 - tuple
// matches has three members:
// an index of a store and iterators into that store's vector
typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator> matches;

// exer17-5 - pair pair
typedef pair<vector<Sales_data>::size_type,
            pair<vector<Sales_data>::const_iterator,
                 vector<Sales_data>::const_iterator>> matches_pair;

// exer17-6 - not using tuple or pair (so I use a class)
struct matches_struct
{
  vector<Sales_data>::size_type storeNo;
  vector<Sales_data>::const_iterator beg;
  vector<Sales_data>::const_iterator end;

  matches_struct(vector<Sales_data>::size_type n,
                 vector<Sales_data>::const_iterator b,
                 vector<Sales_data>::const_iterator e):
    storeNo(n),beg(b),end(e)
  {}
};


// files holds the transactions for every store
// findBook returns a vector with an entry for EACH STORE that sold the 
// given book.
vector<matches> findBook(const vector<vector<Sales_data>>&files,
                         const string &book) // book is isbn
{
  // a match for each shop this book is sold in.
  vector<matches> ret; // initially empty

  // for each store find the range of matching books, if any
  for(auto it = files.cbegin(); it!=files.cend(); ++it)
  {
    // find the range of Sales_data that have the same ISBN
    auto found = equal_range(it->cbegin(),it->cend(),book,
        [](const Sales_data &lhs, const Sales_data &rhs) -> bool
        {
          return lhs.isbn() < rhs.isbn();
        });

    // found is a pair, containing iterators into vector<Sales_data> for
    // this store.
    if(found.first != found.second)
      // remember the index of this store and matching range
      ret.push_back(make_tuple(it-files.cbegin(),found.first,found.second));
  }
  return ret;
}

// files holds the transactions for every store
// findBook returns a vector with an entry for EACH STORE that sold the 
// given book.
vector<matches_pair> findBook_pair(const vector<vector<Sales_data>>&files,
                                   const string &book) // book is isbn
{
  // a match for each shop this book is sold in.
  vector<matches_pair> ret; // initially empty

  // for each store find the range of matching books, if any
  for(auto it = files.cbegin(); it!=files.cend(); ++it)
  {
    // find the range of Sales_data that have the same ISBN
    auto found = equal_range(it->cbegin(),it->cend(),book,
        [](const Sales_data &lhs, const Sales_data &rhs) -> bool
        {
          return lhs.isbn() < rhs.isbn();
        });

    // found is a pair, containing iterators into vector<Sales_data> for
    // this store.
    if(found.first != found.second)
      // remember the index of this store and matching range
      ret.push_back(make_pair(it-files.cbegin(),
                              make_pair(found.first,found.second)));
      //ret.push_back(make_tuple(it-files.cbegin(),found.first,found.second));
  }
  return ret;
}

// files holds the transactions for every store
// findBook returns a vector with an entry for EACH STORE that sold the 
// given book.
vector<matches_struct> findBook_struct(const vector<vector<Sales_data>>&files,
                                       const string &book) // book is isbn
{
  // a match for each shop this book is sold in.
  vector<matches_struct> ret; // initially empty

  // for each store find the range of matching books, if any
  for(auto it = files.cbegin(); it!=files.cend(); ++it)
  {
    // find the range of Sales_data that have the same ISBN
    auto found = equal_range(it->cbegin(),it->cend(),book,
        [](const Sales_data &lhs, const Sales_data &rhs) -> bool
        {
          return lhs.isbn() < rhs.isbn();
        });

    // found is a pair, containing iterators into vector<Sales_data> for
    // this store.
    if(found.first != found.second)
      // remember the index of this store and matching range
      ret.push_back(matches_struct(it-files.cbegin(),
                                   found.first,found.second));
      //ret.push_back(make_tuple(it-files.cbegin(),found.first,found.second));
  }
  return ret;
}


void reportResults(istream &in, ostream &os,
                   const vector<vector<Sales_data>> &files)
{
  // book to look for
  string s;
  while(in >> s)
  {
    // stores that sold this book.
    auto trans = findBook(files,s);
    if(trans.empty())
    {
      cout << s << "not found in any stores " << endl;
      continue; // get the next book to look for
    }

    // loop through the stores that have sold book s.
    // for every store with a sale
    for(const auto &store : trans)
    {
      // get<n> returns the specified member from the tuple in store
      os << "store " << get<0>(store) << " sales: "
         << accumulate(get<1>(store), get<2>(store), Sales_data(s))
         << endl;
    }
  }
}

void reportResults_pair(istream &in, ostream &os,
                        const vector<vector<Sales_data>> &files)
{
  // book to look for
  string s;
  while(in >> s)
  {
    // stores that sold this book.
    auto trans = findBook_pair(files,s);
    if(trans.empty())
    {
      cout << s << "not found in any stores " << endl;
      continue; // get the next book to look for
    }

    // loop through the stores that have sold book s.
    // for every store with a sale
    for(const auto &store : trans)
    {
      // get<n> returns the specified member from the tuple in store
      os << "store " << store.first << " sales: "
         << accumulate(store.second.first, store.second.second, Sales_data(s))
         << endl;
    }
  }
}

// compare function.
template<typename T> int compare(const T &v1, const T &v2)
{
  if(std::less<T>()(v1,v2)) return -1;
  if(std::less<T>()(v2,v1)) return 1;
  return 0;
}

void reportResults_struct(istream &in, ostream &os,
                          const vector<vector<Sales_data>> &files)
{
  // book to look for
  string s;
  while(in >> s)
  {
    // stores that sold this book.
    auto trans = findBook_struct(files,s);
    if(trans.empty())
    {
      cout << s << "not found in any stores " << endl;
      continue; // get the next book to look for
    }

    // loop through the stores that have sold book s.
    // for every store with a sale
    for(const auto &store : trans)
    {
      // get<n> returns the specified member from the tuple in store
      os << "store " << store.storeNo << " sales: "
         << accumulate(store.beg, store.end, Sales_data(s))
         << endl;
    }
  }
}

int main()
{
//{
//  // E
//  cout << "E2 - compare"  << endl;
//  cout << compare(1,2)<< endl;
//  cout << compare(2,1)<< endl;
//  cout << compare(2,2)<< endl;
//
//  cout << "\nE3 compare Sales_data" << endl;
//  Sales_data s1, s2;
//  // error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
////  compare(s1,s2);
//}

  //////////////////////////////////////////////////////////////////////////
  // exer17-4

  // each element in files holds the transactions for a particular store
  // 1) Sales_data contains isbn, units_sold and price per book
  // 2) vector<Sales_data> are all the books the shop has sold.
  // 3) the outer vector are ll the books for all the shops!
  vector<vector<Sales_data>> files;

  // populate files
  // store 1
  vector<Sales_data> store1{Sales_data("ISBN-A",1,1.11),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-C",3,3.33)};

  vector<Sales_data> store2{Sales_data("ISBN-A",1,1.11),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-B",2,2.22),
                            Sales_data("ISBN-C",3,3.33)};
  files.push_back(store1);
  files.push_back(store2);

//  istringstream iss("ISBN-B");
  istringstream iss("ISBN-B\nISBN-C");
  reportResults(iss,cout,files);
  cout << endl;
  
  iss.clear();
  iss.str("ISBN-B\nISBN-C");
  reportResults_pair(iss,cout,files);

  cout << endl;
  iss.clear();
  iss.str("ISBN-B\nISBN-C");
  reportResults_struct(iss,cout,files);

//  vector<Sales_data> sd{Sales_data("ISBN-D",2,2),Sales_data("ISBN-D",5,5)};
//  cout << (sd[0]) << endl;
//  cout << (sd[1]) << endl;
//  cout << (sd[0]+sd[1]) << endl;
//  cout << accumulate(sd.cbegin(),sd.cend(),Sales_data()) << endl;

  return 0;
}
