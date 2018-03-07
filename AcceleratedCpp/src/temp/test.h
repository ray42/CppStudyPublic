#ifndef GUARD_TEST_H
#define GUARD_TEST_H

#include<string>

// legal: base function template
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType arg);

// legal: explicit/full function template specialization
template <>
std::string Foo<std::string, char>(char arg) { return "Full"; }

// illegal: partial function template specialization of the return type
//          function template partial specialization is not allowed
// template <typename ArgumentType>
// void Foo<void, ArgumentType>(ArgumentType arg);

// legal: overloads the base template for a pointer argument type
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType *argPtr) { return "PtrOverload"; }

// legal: base function name reused. Not considered an overload. 
// ill-formed: non-overloadable declaration
//template <typename ArgumentType>
//std::string Foo(ArgumentType arg) { return "Return1"; }

// legal: base function name reused. Not considered an overload. 
// ill-formed: non-overloadable declaration
template <typename ReturnType>
ReturnType Foo(char arg) { return "Return2"; }

#endif

