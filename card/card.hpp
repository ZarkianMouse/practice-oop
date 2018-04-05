// Discriminated Union Card Class
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

class StandardCard {
public:
  Card() = default;
  Card(Rank r, Suit s)
    : rank(r), suit(s) {}

  Rank getRank() const {
    return rank;
  }

  Suit getSuit() const {
    return suit;
  }
private:
   Rank rank;
   Suit suit;

};


class JokerCard
{
public:
   JokerCard(Color c)
     : color(c)
   {}

   Color getColor() const {
     return color;
   }

private:
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
    : kind(Standard), val(c)
  { }

  // invariant: When kind == Joker, the active member
  // of val is jc.
  Card(JokerCard c)
    : kind(Joker), val(c)
  { }

  bool isStandard() const { return kind == Standard;}
  bool isJoker() const { return kind == Joker;}

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

  Suit getSuit()
  {
    return getStandardCard().getSuit();
  }

  Rank getRank()
  {
    return getStandardCard().getRank();
  }

  Color getColor()
  {
    return getJokerCard().getColor();
  }

private:
  Kind kind;
  Value val;

};

