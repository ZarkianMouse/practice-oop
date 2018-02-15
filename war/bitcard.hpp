#pragma once

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
  Card() = default;

  Card(Rank r, Suit s)
   : bits ((unsigned)s << 4 | (unsigned)r)
  {}

  Rank getRank() const {
    return (Rank)(0b001111 & bits);
  }

  Suit getSuit() const {
    return (Suit)((0b110000 & bits) >> 4);
  }

  bool operator==(Card c) const {
    return bits == c.bits;
  }

  bool operator!=(Card c) const {
    return bits != c.bits;
  }

  void operator=(Card c) {
    bits = c.bits;
  }

  bool operator<(Card c) {
    return bits < c.bits;
  }

  bool operator>(Card c) {
    return bits > c.bits;
  }

  friend std::string displayCard(Card c);

private:
  unsigned char bits;
};


std::string displayCard(Card c)
{
   std::string myCard;
   
   switch((Rank)(0b001111 & c.bits))
   {
      case Ace   :  myCard = "Ace of ";
           break;
      case Two   :  myCard = "2 of ";
           break;
      case Three :  myCard = "3 of ";
           break;
      case Four  :  myCard = "4 of ";
           break;
      case Five  :  myCard = "5 of ";
           break;
      case Six   :  myCard = "6 of ";
           break;
      case Seven :  myCard = "7 of ";
           break;
      case Eight :  myCard = "8 of ";
           break;
      case Nine  :  myCard = "9 of ";
           break;
      case Ten   :  myCard = "10 of ";
           break;
      case Jack  :  myCard = "Jack of ";
           break;
      case Queen :  myCard = "Queen of ";
           break;
      case King  :  myCard = "King of ";
           break;
   }
   

   switch((Suit)((0b110000 & c.bits) >> 4))
   {
      case Hearts   :  myCard = myCard + "Hearts";
           break;
      case Diamonds :  myCard = myCard + "Diamonds";
           break;
      case Clubs    :  myCard = myCard + "Clubs";
           break;
      case Spades   :  myCard = myCard + "Spades";
           break;
   }
   return myCard;
}

