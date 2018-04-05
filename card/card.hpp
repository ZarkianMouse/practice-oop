// Discriminated Union Card Class
// Copyright of Naomi Burhoe c. Spring 2018

#include <iosfwd>
#include <cassert>

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

class StandardCard {
public:
  StandardCard() = default;
  StandardCard(Rank r, Suit s)
    : rank(r), suit(s) {}

  Rank get_rank() const {
    return rank;
  }

  Suit get_suit() const {
    return suit;
  }

   Rank rank;
   Suit suit;

};


class JokerCard
{
public:
   JokerCard(Color c)
     : color(c)
   {}

   Color get_color() const {
     return color;
   }

   Color color;

};

class Card
{
public:
  enum Kind {
     Standard,
     Joker
  };

private:
  union Value {
     Value(StandardCard c) : sc(c) { }
     Value(JokerCard c) : jc(c) { }
     StandardCard sc;
     JokerCard jc;
  };

public:

  // Creates a stnadard card. This establishes an
  // *invariant*. The invariant or property being
  // established is that when kind == Standard, the
  // active member of value is sc.
  //
  // Plural of invariant is invariants. This is not
  // the same as invariance.
  Card(StandardCard sc)
    : kind(Standard), val(sc)
  { }

  // invariant: When kind == Joker, the active member
  // of val is jc.
  Card(JokerCard jc)
    : kind(Joker), val(jc)
  { }

  bool isStandard() const { return kind == Standard;}
  bool isJoker() const { return kind == Joker;}

  Card* clone() {
    if (isStandard())
        return new Card(val.sc);
    else
        return new Card(val.jc);
  }

  StandardCard getStandardCard()
  {
    // Do not access a member of a union
    // 
    assert(isStandard());
    return val.sc;
  }
  JokerCard getJokerCard()
  {
    assert(isJoker());
    return val.jc;
  }

  Suit get_suit()
  {
    return getStandardCard().get_suit();
  }

  Rank get_rank()
  {
    return getStandardCard().get_rank();
  }

  Color get_color()
  {
    return getJokerCard().get_color();
  }

private:
  Kind kind;
  Value val;

};

