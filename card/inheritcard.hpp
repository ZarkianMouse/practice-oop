// Inheritance-based Card Class
// Copyright of Naomi Burhoe c. Spring 2018

#include <iosfwd>

// Represents ranks of card
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
  Spades,
  Clubs, 
  Diamonds,
  Hearts,
};

// Represents Joker color attribute
enum Color {
  Black, Red
};


// Declares the base class. This class
// abstractly represents the set of all
// cards. There is no object that is not
// one of the derived classes.
class Card
{
public:
  // Just a regular constructor...
  Card(int n)
    : id(n)
  { }

  // Ignore me...
  virtual ~Card() = default;

  // Goal: somebody calls clone and gets a new
  // Card of the same dynamic type and having
  // the same value.
  //
  // This is a virtual function. Calling a virtual
  // function actually calls an overridden version
  // of this function. Which override? The one
  // in the dynamic type of the object on which
  // the function is called.
  //
  // This actually called "virtual constructor".
  // virtual Card* clone() { throw std::logic_error("oops"); }

  // This is called a *pure virtual function*.
  // Pure virtual functions *must* be overridden in
  // a derived class.
  virtual Card* clone() = 0;


  int get_id() const { return id; }

  // Just for fun... uniquely number
  // each card in the deck.
  int id;
};

// Declares a derived class. We often say
// that Standard IS-A Card.
class StandardCard : public Card
{
public:
  // We "inherit" the members of the base
  // class (almost as if) they were declared
  // here.
  // int id;

  // Just a regular constructor... but.
  // You can call a base class constructor
  // explicitly in the member initializer
  // list.
  StandardCard(int n, Rank r, Suit s)
    : Card(n), rank(r), suit(s)
  { }

  // This is an *override* of clone.
  Card* clone() override {
    return new StandardCard(*this);
  }

  Rank get_rank() const { return rank; }
  Suit get_suit() const { return suit; }

private:
  Rank rank;
  Suit suit;
};

// Declares another derived class.
class JokerCard : public Card
{
public:
  JokerCard(int n, Color c)
    : Card(n), color(c)
  { }

  // An *override* of Card::clone.
  Card* clone() override {
    return new JokerCard(*this);
  }


  Color get_color() const { return color; }
private:
  Color color;
};
