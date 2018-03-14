#include "bitcard.hpp"

#include <iostream>

BitDeck
get_bit_deck()
{
    BitDeck d {
    {Ace, Spades},
    {Two, Spades},
    {Three, Spades},
    {Four, Spades},
    {Five, Spades},
    {Six, Spades},
    {Seven, Spades},
    {Eight, Spades},
    {Nine, Spades},
    {Ten, Spades},
    {Jack, Spades},
    {Queen, Spades},
    {King, Spades},

    {Ace, Clubs},
    {Two, Clubs},
    {Three, Clubs},
    {Four, Clubs},
    {Five, Clubs},
    {Six, Clubs},
    {Seven, Clubs},
    {Eight, Clubs},
    {Nine, Clubs},
    {Ten, Clubs},
    {Jack, Clubs},
    {Queen, Clubs},
    {King, Clubs},

    {Ace, Diamonds},
    {Two, Diamonds},
    {Three, Diamonds},
    {Four, Diamonds},
    {Five, Diamonds},
    {Six, Diamonds},
    {Seven, Diamonds},
    {Eight, Diamonds},
    {Nine, Diamonds},
    {Ten, Diamonds},
    {Jack, Diamonds},
    {Queen, Diamonds},
    {King, Diamonds},

    {Ace, Hearts},
    {Two, Hearts},
    {Three, Hearts},
    {Four, Hearts},
    {Five, Hearts},
    {Six, Hearts},
    {Seven, Hearts},
    {Eight, Hearts},
    {Nine, Hearts},
    {Ten, Hearts},
    {Jack, Hearts},
    {Queen, Hearts},
    {King, Hearts},
  };
  return d;
}

std::ostream& 
operator<<(std::ostream& os, BitCard c)
{
  return os << c.get_rank() << c.get_suit();
}

std::ostream& 
operator<<(std::ostream& os, const BitDeck& d)
{
  for (int i = 0; i < d.size(); ++i) {
    os << d[i];
    if ((i + 1) % 13 == 0)
      os << '\n';
    else
      os << ' ';
  }
  return os;
}
