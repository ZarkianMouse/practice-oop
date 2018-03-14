
#pragma once

#include "card.hpp"

#include <vector>

// Represents a card, whose value is a Rank AND a SUIT.
class BadCard {
public:
  BadCard() = default;

  BadCard(Rank r, Suit s)
    : rank(r), suit(s)
  { }

  /// Returns the rank of the card.
  Rank get_rank() const { 
    return rank; 
  }

  /// Returns the suit of the card.
  Suit get_suit() const { 
    return suit; 
  }

  // Equality
  friend bool operator==(BadCard a, BadCard b) {
    return a.rank == b.rank && a.suit == b.suit;
  }
  friend bool operator!=(BadCard a, BadCard b) {
    return !(a == b);
  }

  // Ordering
  //
  // NOTE: This implementation defines what is called the "product order"
  // of the cards. This is not suitable for sorting or computing the min/max
  // of cards since some pairs of cards are incomparable. That is, neither
  // is less than the other, nor are the equal. For example, consider the 2 of 
  // Spades (2S) and Ace of Clubs (AC). None of the following hold:
  //
  // - 2S < AC is false since 2 > A
  // - AC < 2S is false since C > S
  // - 2S != AC
  //
  // It is not possible to determine which is less than the other. 
  //
  // The product order is an example of a partial order.
  friend bool operator<(BadCard a, BadCard b) {
    return a.suit < b.suit  && a.rank < b.rank;
  }
  friend bool operator>(BadCard a, BadCard b) {
    return b < a;
  }
  friend bool operator<=(BadCard a, BadCard b) {
    return !(b < a);
  }
  friend bool operator>=(BadCard a, BadCard b) {
    return !(a < b);
  }

private:
  Rank rank;
  Suit suit;
};


// A deck is a sequence of cards.
using BadDeck = std::vector<BadCard>;

/// Returns a standard deck of cards.
BadDeck get_bad_deck();


// Streaming
std::ostream& operator<<(std::ostream& os, BadCard c);
std::ostream& operator<<(std::ostream& os, const BadDeck& d);


