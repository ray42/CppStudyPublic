#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;

#include<algorithm>
using std::count_if;
using std::find_if;
using std::transform;

#include<functional>
using std::bind;
using std::greater;
using std::not_equal_to;
using std::multiplies;

#include<iterator>
using std::ostream_iterator;

//exer:14-42
// Using library function objects and adaptors, define an expression to
// 1) Count the number of values that are greater than 1024
// 2) Find the first string that is not equal to pooh
// 3) Multiply all values by 2
int main()
{
  //using namespace std::placeholders; // for _1, _2, etc....
  using std::placeholders::_1; // for _1, _2, etc....

  // Note: The algorithms listed above require unary predicates/functions
  // but the library function-objects require two arguments.
  // Thus we must use bind.

  vector<unsigned> vu{1, 2, 3, 4, 9001, 4000, 10};
  int ret1 = count_if(vu.begin(),vu.end(),bind(greater<unsigned>(),_1,1024));
  cout << ret1 << endl;

  vector<string> vs{"pooh","pooh","HELLO","pooh","WORLD"};
  auto ret2 = find_if(vs.begin(),vs.end(),bind(not_equal_to<string>(),_1,"pooh"));
  cout << *ret2 << endl;

  vector<double> vd{1.1, 2.2, 3.3, 4.4};
  transform(vd.begin(),vd.end(),vd.begin(),bind(multiplies<double>(),_1,2));

  transform(vd.begin(),vd.end(),ostream_iterator<double>(cout," "),
      [](const double i)
      {
        return i;
      });
  cout << endl;
  
  return 0;
}
