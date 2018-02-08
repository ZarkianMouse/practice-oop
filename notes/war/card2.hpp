#ifndef CARD_HPP
#define CARD_HPP

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
    End,
};

// Represents the suits of a card.
enum Suit {
    Hearts, // This is called an enumerator
    Diamonds,
    Clubs,
    Spades,
    Blank,
};


// I want to do this
class Card {
public :
  // Declares a constructor taking a rank and
  // a suit as arguments.
  //
  // Constructors are used to initialize data members
  // of the class and acquire resources (if any -- none
  // are needed here).
  Card(Rank r, Suit s)
    : rank(r), suit(s) // The right way
  {}
  
  // A copy constructor ALWAYS has the following
  // form (except when you're an expert)
  Card(const Card& c)
    : rank(c.rank), suit(c.suit)
  {}

  const Rank getRank();
  const Suit getSuit();
// A copy assignment operator ALWAYS has the
  // following form:
  //
  // If you write:
  //    c1 = c2;
  // "this" is a pointer to c1.
  Card& operator=(Card& c);


  // Declares a destructor. If we had acquired
  // resources, we should release them here. If not,
  // DO NOT DEFINE A DESTRUCTOR.
  ~Card() {
  }


private:
  Rank rank;
  Suit suit;
};

// When do you pass by value?
//
// When the argument is only an input to the function.

// When do you copy vs. reference?
//
// DEFINITELY pass by const reference when your
// object dynamically allocates memory.


// When do you pass by reference?
//
// When the argument is the output of the
// function.  The function modifies the value
// of the input.
//
// The parameter could also be "mutable".
// Also called an in/out parameter.
// The caller initializes it, the function
// modifies the value to indicate status.

#endif
