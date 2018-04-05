// Driver Program for Card Class Practice
// Copyright of Naomi Burhoe c. Spring 2018

#include <iostream>
#include  <cassert>
#include "card.hpp"
//#include "bitcard.hpp"
//#include "inheritcard.hpp"
//#include "deck.hpp"


int main() {
   std::cout << "Hello World\n";

   StandardCard sc(Ace, Spades);
   JokerCard jc(Red);
 
   std::cout << sc.get_rank()  << "\t" 
             << sc.get_suit()  << "\n"
             << jc.get_color() << "\n";
}
