#include "string.hpp"
#include <iostream>

int
main()
{
  // Default construct
  string s0;


  // Construct and assign from a literal value
  string s1 = "hello";
  s0.printStr();
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
