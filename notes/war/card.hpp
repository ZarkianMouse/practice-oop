
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
class Card {
public:
  // Declares a constructor taking a rank and
  // a suit as arguments. This allows me to write:
  //
  //    Card c{Ace, Spades}
  //
  // Constructors are used to initialize data members
  // of the class and acquire resources (if any -- none
  // are needed here).
  Card(Rank r, Suit s);

  // A copy constructor ALWAYS has the following
  // form (except when you're an expert).
  Card(const Card& c);

  // A copy assignment operator ALWAYS has the
  // following form:
  //
  // If you write:
  //    c1 = c2;
  // "this" is a pointer to c1.
  Card& operator=(const Card& c);

  // Accessor functions. Sometimes called
  // observers.

  // Returns the rank of the card.
  //
  // In-class member function definitions
  // are implicitly inline.
  Rank get_rank() const { return rank; }

  // Returns the suit of the card.
  Suit get_suit() const { return suit; }

  // Mutators or modifiers functions.
  //
  // Think before adding mutator functions. Don't
  // blindly add set_ functions for private data
  // members --- they're probably private for a
  // reason.
  void set_rank(Rank r) { rank = r; }
  void set_suit(Suit s) { suit = s; }

  // A friend can access the private members of
  // this class.
  //
  // Be careful of using friends. This can indicate
  // that separate (logical) components are not in
  // fact separate, but depend on each other in other
  // ways.
  // friend bool operator==(Card a, Card b);

private:
  Rank rank;
  Suit suit;
};


// Two cards are equal when they have the same
// rank and suit.
inline bool 
operator==(Card a, Card b) {
  return a.get_rank() == b.get_rank() && 
         a.get_suit() == b.get_suit();
}

// If you define ==, then you had better define
// != also.
inline bool 
operator!=(Card a, Card b) {
  return !(a == b);
}

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
