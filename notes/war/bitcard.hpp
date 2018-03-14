
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
//    00ssrrrr  (8 bits)
//
// where s is a suit bit and r is a rank bit.
class Card {
public:
  // The default card is indeterminate. This is just
  // like writing:
  //
  //  int x; // indeterminate
  Card() = default;

  // Use c-style casts to make r and s unsigned integers.
  Card(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
  { }

  Rank get_rank() const {
    return (Rank)(0b001111 & bits); // 0xf & bits
  }

  Suit get_suit() const {
    return (Suit)((0b110000 & bits) >> 4);
  }

  // We can somewhat optimize the performance of the
  // == operator by comparing integer values.
  bool operator==(Card c) const {
    return bits == c.bits;
  }

  bool operator!=(Card c) const {
    return bits != c.bits;
  }

  // You may, from time to time see this. This is
  // called a friend function definition. A friend
  // function definition is NOT a member of the 
  // class. This operator actually lives outside the
  // class, but has access to the private members
  // of Card.
  //
  // This appears from time to time.
  friend bool operator==(Card a, Card b) {
    return a.bits == b.bits;
  }

private:
  unsigned char bits;
};

// I can't do this yet.
Card c;



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
