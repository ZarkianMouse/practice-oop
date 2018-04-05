// Bitcard Class
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

class Card {
public:
  Card() = default;

  Card(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
  { }

  Card(Color c)
    : bits((unsigned)c)
  { }

  Rank get_rank() const {
    return (Rank)(0b001111 & bits); // 0xf & bits
  }

  Suit get_suit() const {
    return (Suit)((0b110000 & bits) >> 4);
  }

  Color get_color() const {
    return (Color)(0b001111 & bits);
  }

  // We can somewhat optimize the performance of the
  // == operator by comparing integer values.
  bool operator==(Card c) const {
    return bits == c.bits;
  }

  bool operator!=(Card c) const {
    return bits != c.bits;
  }

private:
  unsigned char bits;
};
