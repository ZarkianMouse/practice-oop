#include <iostream>


// A card is basically a pair of rank and suit.
// How do you represent a rank?
// How do you represent a suit?
//    - Just use ints. Right?
// How do you represent a pair of things?
// Defines a new type (user-defined type)

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
  Card() {}


  Rank getRank() const {return rank;};
  Suit getSuit() const {return suit;};
  // Declares a destructor. If we had acquired
  // resources, we should release them here. If not,
  // DO NOT DEFINE A DESTRUCTOR.
  ~Card() {
  }
  void operator=(Card b) {rank = b.getRank(); suit = b.getSuit();}
private:
  Rank rank;
  Suit suit;
};

bool operator==(Card a, Card b)
{
    return a.getRank() == b.getRank() && a.getSuit() == b.getSuit();
}
