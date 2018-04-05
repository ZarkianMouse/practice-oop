#include <iostream>
#include <vector>
#include "deck.hpp"


/*Deck
get_deck()
{
  Deck d {
    new StandardCard(Ace, Spades),
    new StandardCard(Two, Spades),
    new StandardCard(Three, Spades),
    new StandardCard(Four, Spades),
    new StandardCard(Five, Spades),
    new StandardCard(Six, Spades),
    new StandardCard(Seven, Spades),
    new StandardCard(Eight, Spades),
    new StandardCard(Nine, Spades),
    new StandardCard(Ten, Spades),
    new StandardCard(Jack, Spades),
    new StandardCard(Queen, Spades),
    new StandardCard(King, Spades),

    new StandardCard(Ace, Clubs),
    new StandardCard(Two, Clubs),
    new StandardCard(Three, Clubs),
    new StandardCard(Four, Clubs),
    new StandardCard(Five, Clubs),
    new StandardCard(Six, Clubs),
    new StandardCard(Seven, Clubs),
    new StandardCard(Eight, Clubs),
    new StandardCard(Nine, Clubs),
    new StandardCard(Ten, Clubs),
    new StandardCard(Jack, Clubs),
    new StandardCard(Queen, Clubs),
    new StandardCard(King, Clubs),

    new StandardCard(Ace, Diamonds),
    new StandardCard(Two, Diamonds),
    new StandardCard(Three, Diamonds),
    new StandardCard(Four, Diamonds),
    new StandardCard(Five, Diamonds),
    new StandardCard(Six, Diamonds),
    new StandardCard(Seven, Diamonds),
    new StandardCard(Eight, Diamonds),
    new StandardCard(Nine, Diamonds),
    new StandardCard(Ten, Diamonds),
    new StandardCard(Jack, Diamonds),
    new StandardCard(Queen, Diamonds),
    new StandardCard(King, Diamonds),

    new StandardCard(Ace, Hearts),
    new StandardCard(Two, Hearts),
    new StandardCard(Three, Hearts),
    new StandardCard(Four, Hearts),
    new StandardCard(Five, Hearts),
    new StandardCard(Six, Hearts),
    new StandardCard(Seven, Hearts),
    new StandardCard(Eight, Hearts),
    new StandardCard(Nine, Hearts),
    new StandardCard(Ten, Hearts),
    new StandardCard(Jack, Hearts),
    new StandardCard(Queen, Hearts),
    new StandardCard(King, Hearts),

    new JokerCard(Black),
    new JokerCard(Red),
  };
  return d;
}*/

std::ostream& 
operator<<(std::ostream& os, Card c)
{
   if (c.isStandard())
      return os << c.get_rank() << c.get_suit();
   else
      return os << c.get_color();
}

std::ostream& 
operator<<(std::ostream& os, const Deck& d)
{
  for (int i = 0; i < d.size(); ++i) {
     if (d[i]->isStandard()) {
         os << d[i]->get_rank() << '\t'
                   << d[i]->get_suit() << '\n';
     }

     else if (d[i]->isJoker()) {
         os << d[i]->get_color() << '\n';
     }
   }
  return os;
}
