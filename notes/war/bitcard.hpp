
#pragma once

#include <iostream>

// Defines a new type (user-defined type). Sometimes called
// a kind of type constructor (ignore that).
enum Rank {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
};

// Represents the suits of a card.
enum Suit {
  Hearts, // This is called an enumerator
  Diamonds,
  Clubs, 
  Spades,
};


// A card is a Rank AND a SUIT.
//
// I want to do this:
//
//    Card c1{Ace, Spades}; // Construct from values
//    Card c2 = c1; // Copy constructor
//    c2 = c1; // Assignment operator
//    c1 == c2;
//    c1 != c2;
//
// Our representation has this layout:
//
//    ssrrrr
//
// where s is a suit bit and r is a rank bit.

class Card {
public:

  Card()
  { }

  Card(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
  { }

  Rank getRank() const
  {
    return (Rank)(0b001111 & bits); // 0xf & bits
  }

  Suit getSuit() const
  {
    return (Suit)(0b110000 & bits >> 4);
  }

  // We can somewhat optmize the performance of the
  // == operator by comparing integer values;
  bool operator==(Card c) const
  {
    return bits == c.bits;
  }

  bool operator!=(Card c) const
  {
    return bits != c.bits;

  }

private:
  unsigned char bits;

};


// Two cards are equal when they have the same
// rank and suit.
/*inline bool 
operator==(Card a, Card b) {
  return a.get_rank() == b.get_rank() && 
         a.get_suit() == b.get_suit();
}*/

// If you define ==, then you had better define
// != also.
/*
inline bool 
operator!=(Card a, Card b) {
  return !(a == b);
}*/

// When do you pass by value?
// When do you pass by const reference?
//
// When the argument is only an input to the
// function.
//
// When do you copy vs. reference?
//
// DEFINITELY pass by const reference when your
// object dynamically allocates memory.


// When do you pass by reference?
//
// When the argument is an output of the 
// function. The function modifies the value
// of the input.
//
// The parameter could also be "mutable".
// Also called an in/out parameter.
// The caller initializes it, the function
// modifies the value to indicate status.




#if 0
// When do you pass by reference/const reference?

void f(int n) {
  while (n != 0) {
    // Do stuff.
    --n;
  }
}

int x = 4;
f(x);
assert(x == 4);
#endif
