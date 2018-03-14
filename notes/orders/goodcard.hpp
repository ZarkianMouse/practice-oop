
#pragma once

#include "card.hpp"

#include <vector>

// Represents a card, whose value is a Rank AND a SUIT.
class GoodCard {
public:
  GoodCard() = default;

  GoodCard(Rank r, Suit s)
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
  friend bool operator==(GoodCard a, GoodCard b) {
    return a.rank == b.rank && a.suit == b.suit;
  }
  friend bool operator!=(GoodCard a, GoodCard b) {
    return !(a == b);
  }

  // Ordering
  //
  // NOTE: This function implements the "lexicographical order" for the
  // rank/suit pair. This guarantees a total order of the cards in the deck,
  // meaning that they can be used for sorting.
  //
  // The alphabetical ordering of strings is another example of a 
  // lexicographical order.
  //
  // Note that we compare suit first so that all cards with the same suit are
  // grouped together.
  //
  // FOR FUN: Reverse the order in which rank and suit are compared. What
  // happens?
  friend bool operator<(GoodCard a, GoodCard b) {
    if (a.suit < b.suit)
      return true;
    if (b.suit < a.suit)
      return false;
    return a.rank < b.rank;
  }
  friend bool operator>(GoodCard a, GoodCard b) {
    return b < a;
  }
  friend bool operator<=(GoodCard a, GoodCard b) {
    return !(b < a);
  }
  friend bool operator>=(GoodCard a, GoodCard b) {
    return !(a < b);
  }

private:
  Rank rank;
  Suit suit;
};


// A deck is a sequence of cards.
using GoodDeck = std::vector<GoodCard>;

/// Returns a standard deck of cards.
GoodDeck get_good_deck();


// Streaming
std::ostream& operator<<(std::ostream& os, GoodCard c);
std::ostream& operator<<(std::ostream& os, const GoodDeck& d);


