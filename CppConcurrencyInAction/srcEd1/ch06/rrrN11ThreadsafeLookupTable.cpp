/*
 * =========================================================================
 * Copyright (c) 2018, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
#include<utility> // pair
#include<list> // list
#include<shared_mutex> // shared_mutex
#include<thread> // thread


template<typename Key, typename Value, typename Hash=std::hash<Key> >
class threadsafe_lookup_table
{
private:
  class bucket_type
  {
  private:
    using bucket_value = std::pair<Key,Value>;
    using bucket_data = std::list<bucket_value>;
    using bucket_iterator = typename bucket_data::iterator;

    bucket_data data;
    //
  };

};


int main()
{
  return 0;
}

