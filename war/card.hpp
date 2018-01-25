#pragma once

// A card is basically a pair of rank and suit.
//
// How do you represent a rank?
// How do you represent a suit?
//
//    - Just use ints. Right?
//
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

Suit s = Hearts;

// This is called a scoped enum. Enumerator names
// are part of the enum, not the enclosing class.
enum class Suit2 {
  Hearts2,
  Diamonds2,
  Clubs2, 
  Spades2,
};
Suit2 s2 = Suit2::Hearts2;


// A card is a Rank AND Suit....
// We can build this using a pair. Pair is vocabulary
// type. This is reasonable, but it's not in our problem
// domain.
using Card = std::pair<Rank, Suit>;
C c;
c.first = Ace;
c.second = Spades;


// Technically this is a class.
struct Card {
  Rank rank;
  Suit suit;
};

Card c;
c.rank = Ace;
c.suit = Spades;





#if 0
// Type alias...
//
// Is this a good abstraction? Why not?
using Card = int[2];

// Because this is practically meaningless.
Card c;
c[0] = 3;
c[1] = 1;



// This is still a bad abstraction... Why?
struct Card
{
  int first;
  int second;
};
#endif
