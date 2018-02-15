// A test for bitcard.hpp
// by Naomi Burhoe c. 2018

#include <iostream>
#include "bitcard.hpp"

int main()
{
  // default construct
  std::cout << "Construct\n";
  Card c1;

  // construct with set values
  std::cout << "Construct with set values\n";
  Card c2(Ace, Spades);

  // copy construct
  std::cout << "Copy Construct\n";
  Card c3 = c2;

  // copy assign
  std::cout << "Copy assign\n";
  c1 = c3;
  

  // compare
  std::cout << "== operation\n";
  if (c2 == c1)
     std::cout << "c2 == c1\n";

  Card c4(Ten, Hearts);
  // compare unequal values
  std::cout << "!= operation\n";
  if (c4 != c1)
     std::cout << "c4 != c1\n";

  // greater/less than values
  std::cout << "< operation\n";
  if(c4 < c1)
     std::cout << "c4 < c1\n";

  std::cout << "> operation\n";
  if(c1 > c4)
     std::cout << "c1 > c4\n";

  // display card values
  std::cout << displayCard(c1) << '\n' << displayCard(c4) << '\n';

  std::cout << "\ntesting finished\n";
}
