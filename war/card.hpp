#include <iostream>


// A card is basically a pair of rank and suit.
// How do you represent a rank?
// How do you represent a suit?
//    - Just use ints. Right?
// How do you represent a pair of things?
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

class Card {
  public:

  // Declares a constructor taking a rank and
  // a suit as arguments.
  //
  // Constructors are used to initialize data members
  // of the class and acquire resources (if any -- none
  // are needed here).
  Card(Rank r, Suit s)
    : rank(r), suit(s) {}; // The right way

  Rank getRank() const {return rank;};
  Suit getSuit() const {return suit;};
  // Declares a destructor. If we had acquired
  // resources, we should release them here. If not,
  // DO NOT DEFINE A DESTRUCTOR.
  ~Card() {
  }

private:
  Rank rank;
  Suit suit;
};

void f() {
  Card c {Ace, Spades};
  // c.rank = Ace;
  // c.suit = Spades;
}
