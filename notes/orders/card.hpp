#pragma once

#include <iosfwd>

// Represents the rank of a cards.
enum Rank 
{
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
enum Suit 
{
  Spades,
  Clubs, 
  Diamonds,
  Hearts,
};

// Streaming
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);