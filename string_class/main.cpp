#include "string.hpp"
#include <iostream>

void f();

int
main()
{
  // Default construct
  mstring s0;

  f();
  // Construct and assign from a literal value
  mstring s1 = "hello";
  s1.printStr();
  //s1 = "foo";

// Copy construct and assign
// String s2 = s1;

/*
s2 = s1; // s2 == s1
std::cout << "s2 = " << s2 << '\n';

// Compare
s1 == s1;
s2 == s1;

// Order
s1 < s1; // lexicographical comparison

// Object independence
s2 = "bar"; // Does not change the value of s1

*/
  return 0;
}
