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


#if 0
// A card is a Rank AND Suit....
// We can build this using a pair. Pair is vocabulary
// type. This is reasonable, but it's not in our problem
// domain.
using Card = std::pair<Rank, Suit>;
C c;
c.first = Ace;
c.second = Spades;
#endif

// Rank = { Ace, Two, ..., King }
// Suit = { Hearts, Diamonds, Clubs, Spades }
// R X S = { (Ace, Hearts), (Two, Hearts), ... , (King, Spades) }

// A card is a Rank AND a Suit.  The set of values
// of this class is the *cross product* of the set
// of values of Rank and Suit.

struct Card
{
  Rank rank;
  Suit suit;
};

// Two cards are equal when they have the same
// rank and suit.
//
// In general, define == to mean that two objects
// represent the same entity.  This means that you
// can *substritute* equal values as inputs to (certain)
// functions and expect the equal results.
bool operator==(Card a, Card b) {
  return a.rank == b.rank && a.suit == b.suit;
}

// If you define ==, then you had better define
// != also.
bool operator!=(Card a, Card b) {
  return !(a == b);
}

// What value does c have? Possibly indeterminate.
// Be careful. This could be an invalid card.
//
// We can default construct a card.  We can create
// a card object, and invoke the default constructor.
Card c;
c.rank = Ace;
c.suit = Spades;

// If you can write 'Card c;', you can also write
// this.  It's because Card is default constructible.
// Be cardful, these have indeterminate value.
Card cards[52];

// You can do this too. I don't know what the value
// of these cards is.
//
// Also, don't use "naked" arrays.
Card *ptr = new Card[52];

// Vector will also use the default constructor.
std::vector<Card> deck(52);

// We can copy cards.  This is called copy
// construction.
//
// What must be true after copy construct? It had
// better be the case that c and c2 have the
// *same value* (represent the same entity).
Card c2 = c;
assert(c2 == c);

// This is called copy assignment.
//
// What must be true after copy assignment? Same
// as above.
c2 = c;
assert(c2 == c);

// This is called move construction. Essentially
// steal the bits (representation) from c and
// put them in c3.
//
// After move construction, c3 has the previous value
// of c. The value of c is "valid but unspecified".
Card c3 = std::move(c);

// This is called move assignment.
c3 = std::move(c);

//Value semantics.
//
// Any type (calss) that can be copied (and moved)
// is typically said to have "value semantics".
//
// Value semantic types are said to be Regular
// types.


// You can provide values using an initializer-list.
// This will select one of several constructors to
// initialize the object.
//
// If you don't define any constructors, then this
// will still magically initialize the object.
Card c {Ace, Spades};

int n = 4;
int n {4};
int n {}; // Guarantes n == 0

Rank r{}; // Guarantees 0 bits
Card c{}; // Guarantees all 0 bits



// This is not a value semantic class.  This is
// a *resource class*.  We don't really know how
// to define equality or copying for this type
// so that it would work like 'int'.
//
// There is no design that will ever make File
// work like int.
File f1("~/.bashrc");
File f2 = f1;





#if 0

// A card is a Rank AND a SUIT.
//
// Technically this is a class.
class Card {
  // Declares a constructor taking a rank and
  // a suit as arguments.
  //
  // Constructors are used to initialize data members
  // of the class and acquire resources (if any -- none
  // are needed here).
  Card(Rank r, Suit s)
    : rank(r), suit(s) // The right way
  {
    // rank = r; // The wrong way.
    // suit = s;
  }

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

#endif

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
