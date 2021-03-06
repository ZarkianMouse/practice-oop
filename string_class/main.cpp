#include "string.hpp"
#include <iostream>

void f();

int
main()
{
  // Default construct
  mstring s0;

  // Construct and assign from a literal value
  mstring s1 = "hello";

  std::cout << "s1 = " << s1 << '\n';
  s1 = "foo";

  std::cout << "s1 = " << s1 << '\n';

  // Copy construct and assign
  mstring s2 = s1;

  s2 = s1; // s2 == s1
  std::cout << "s2 = " << s2 << '\n';

  // Compare
  s1 == s1;
  s2 == s1;

  // Order
  if ((s1 < s1) == true)
    std::cout << "true\n";
  else
    std::cout << "false\n";
    // lexicographical comparison

  // Object independence
  s2 = "bar"; // Does not change the value of s1
  std::cout << "s2 = " << s2 << '\n'
            << "s1 = " << s1 << '\n';

  s0.~mstring();
  s1.~mstring();
  s2.~mstring();

}
