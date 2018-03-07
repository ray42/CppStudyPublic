

// Exercise 6.54: Write a declaration for a function that takes two int
// parameters and returns an int, and declare a vector whose elements have
// this function pointer type.
int foo(int,int);
vector<int(*)(int,int)> bar;

// Exercise 6.55: Write four functions that add, subtract, multiply, and divide
// two int values. Store pointers to these functions in your vector from the
// previous exercise.
int add(int a,int b){return a+b;}
int subtract(int a,int b){return a-b;}
int multiply(int a,int b){return a*b;}
int divide(int a,int b){return b!=0?a/b:0;}

bar.push_back(add);
bar.push_back(subtract);
bar.push_back(multiply);
bar.push_back(divide);

// Exercise 6.56: Call each element in the vector and print their result.
for(auto f : bar)
  cout << f(4,2) << endl;

