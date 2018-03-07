// source file for the median function
#include<algorithm> //std::sort
#include<stdexcept> // std::domain_error
#include<vector> // std::vector
#include<numeric>

#include "average.h"

using std::sort; using std::domain_error; using std::vector;

using std::accumulate;
// compute the median of a vector<double>
// note that calling this function copies the entire argument vector

// compute the average of a vector<double>
double average(const std::vector<double>& v)
{
  return accumulate(v.begin(),v.end(),0.0)/v.size();
}


