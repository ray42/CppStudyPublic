/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<string>
using std::string;
using std::getline;

#include<iostream>
using std::cout;
using std::endl;

#include<vector>
using std::vector;

#include<fstream>
using std::ifstream;

#include<sstream>
using std::istringstream;

#include<set>
using std::set;

#include<map>
using std::map;

#include<memory>
using std::shared_ptr;

#include"TextQuery.h"

#include"QueryResult.h"

TextQuery::TextQuery(ifstream& is):file_spt(new vector<string>),
  word_map(map<string,shared_ptr<set<line_no>>>())

{
  string text;
  while(getline(is,text))           // for each line in the file
  {
    file_spt->push_back(text);      // remember this line of text
    int n = file_spt->size() - 1;   // the current line number
    istringstream line(text);       // separate the line into words
    string word;
    while(line >> word)             // for each word in that line
    {
      // if word isn't already in word_map, subscripting adds a new entry
      auto &lines = word_map[word]; //lines is a shared_ptr to a set of size_type
      // that pointer is null the first time we see word, note this works
      // because we are using a smart pointer, which have value-initialized null. 
      if(!lines) 
        lines.reset(new set<line_no>); // allocate a new set

      lines->insert(n);             // insert this line number
    }
  }
}

QueryResult TextQuery::query(const string&sought) const
{
  // we'll return a pointer to this set if we don't find sought
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  // use find and not a subscript to avoid adding words to word_map!
  auto loc = word_map.find(sought);

  if(loc == word_map.end())
    return QueryResult(sought, nodata, file_spt);// not found
  else
    return QueryResult(sought, loc->second, file_spt);
}


void TextQuery::testfun()
{
  cout << "file_pt: " << endl;
  for(const auto &i : *file_spt)
  {
    cout << i << endl;
  }
  
  cout << "word_map.size " << word_map.size() << endl;
  //Now print each set.
  for(const auto& ipair : word_map)
  {
    cout << ipair.first << "\t";
    for(const auto& iline: *ipair.second)
    {
      cout << iline << " ";
    }
    cout << endl;
  }
}
