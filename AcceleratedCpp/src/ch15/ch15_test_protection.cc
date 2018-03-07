// From Accelerated C++:
//
// A member of a derived class can access the protected members of the
// base-class parts of objects of its own class, or of other classes derived
// from it, but it cannot access the protected members of base-class objects
// that stand alone—that is, that are not part of a derived-class object.
// 
// *Okay, I understand this so far*
//
// This rule may be surprising, but its logic is straightforward: If the
// language granted derived objects access to the protected members of a
// base-class object, then it would be trivial to subvert the protection
// mechanisms. If we needed access to a protected member of a class, we could
// define a new class that inherited from the class that we wanted to access.
// Then we could define the operation that needed access to the protected
// member as a member of that newly derived class (1). By doing so, we could
// override the original class designer's protection strategy. For this reason,
// protected access is restricted to members of the base-class part of a
// derived-class object, and does not allow direct access to the members of
// base-class objects.
//
// (1) What? - But I thought this is allowed. What am I not getting?
//
// Okay, lets try to subvert the protection mechanism, let's see if the
// language prevents me!


#include<iostream>

using std::cout; using std::endl;

class Base
{
public:
  Base()
  {
    cout << "Base constructor" << endl;
    protected_int = 1;
  }

protected:
  void protected_fun() const
  {
    cout << "Hi from protected function" << endl;
  }

  int protected_int;
};

class Derived : public Base
{
public:
  Derived(){ }

  void modify_protected_int()
  {
    protected_int = 999;
  }

  int get_protected_int() const
  {
    return protected_int;
  }

};

// We are testing if we can override the original class designer's protection
// strategy by define a new class that inherited from the class that we wanted
// to access. Then we could define the operation that needed access to the
// protected member as a member of that newly derived class.
int main()
{
  Derived derived;

  derived.modify_protected_int();
    
  // OMG! We just did what the book said is not allowed?
  // Did the book just provided a bad example?
  cout << derived.get_protected_int() << endl;
    
  return 0;
}
