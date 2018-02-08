#include "card.hpp"

// Out-of class definition
//
// Mainly, prefer to put these in the .cpp file.
// But, if you put them in the header file, make
// them inline.
//
// Prefer (often?) to put function definitions in
// a .cpp file in order to separate the *interface*
// of a class from its *implementation*.


Card::Card(Rank r, Suit s)
  : rank(r), suit(s)
{ }

Card::Card(const Card& c)
  : rank(c.rank), suit(c.suit)
{ }

Card& 
Card::operator=(const Card& c) {
  rank = c.rank;
  suit = c.suit;

  // // The code above is equivalent to this:
  // this->rank = c.rank;
  // this->suit = c.suit;
  return *this;
}

