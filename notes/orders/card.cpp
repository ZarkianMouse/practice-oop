#include "card.hpp"

#include <iostream>

static char
spell_rank(Rank r)
{
  switch (r) {
  case Ace: return 'A';
  case Two: return '2';
  case Three: return '3';
  case Four: return '4';
  case Five: return '5';
  case Six: return '6';
  case Seven: return '7';
  case Eight: return '8';
  case Nine: return '9';
  case Ten: return 'T';
  case Jack: return 'J';
  case Queen: return 'Q';
  case King: return 'K';
  }
}

std::ostream& 
operator<<(std::ostream& os, Rank r)
{
  return os << spell_rank(r);
}

static const char*
spell_suit(Suit s)
{
  switch (s) {
  case Spades: return "\u2660";
  case Clubs: return "\u2663";
  case Diamonds: return "\u2662";
  case Hearts: return "\u2661";
  }
}

std::ostream& 
operator<<(std::ostream& os, Suit s)
{
  return os << spell_suit(s);
}
