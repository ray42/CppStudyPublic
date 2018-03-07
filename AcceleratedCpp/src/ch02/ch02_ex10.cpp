#include<iostream>

int main() {
int k = 0;
int n = 5; // NOTE: n was not defined
while (k != n) {
// invariant: we have written k asterisks so far
using std::cout;
cout << "*";
++k;
}
std::cout << std::endl;
// std:: is required here
return 0;
}
