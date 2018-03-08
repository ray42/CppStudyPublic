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
#include<algorithm> // find_if


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
    mutable std::shared_mutex mutex;                        //1

    // Returns iterator into the BUCKET, pointing to the first bucket_value
    // such that the keys match.
    bucket_iterator find_entry_for(Key const& key) const    //2
    {
      return std::find_if(data.begin(),data.end(),
          [&](bucket_value const& item)
          {
            return item.first == key;
          });
    }
  public:

    // Default value is something the user provides, which is returned if
    // the key does not exist
    Value value_for(Key const& key, Value const& default_value) const
    {
      std::shared_lock<std::shared_mutex> lock(mutex);      //3
      bucket_iterator const found_entry = find_entry_for(key);
      return (found_entry==data.end())?
             default_value : found_entry->second;
    }
  };

};


int main()
{
  return 0;
}

















