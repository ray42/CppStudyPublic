// Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer
// to Y, and Y has an object of type X.

class Y; // Y is declared.
class X
{
  Y* y = nullptr; // must declare Y
};

class Y
{
  X x; // okay since X is already defined.
};
