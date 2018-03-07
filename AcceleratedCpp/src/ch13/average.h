#ifndef GUARD_AVERAGE_H
#define GUARD_AVERAGE_H

// header file for the median function
#include<vector> // std::vector
#include<numeric> // std::accumulate

// compute the average of a vector<T>
template<class T> T average(const std::vector<T>& v)
{
  return std::accumulate(v.begin(),v.end(),T(0)) / v.size();
}
#endif
