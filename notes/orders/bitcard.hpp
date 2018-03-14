#pragma once

#include "card.hpp"

#include <vector>

// A card, whose value is that of a Rank AND a SUIT.
//
// Our representation has this layout:
//
//    00ssrrrr
//
// where s is a suit bit and r is a rank bit. The 2 hight order bits are
// unused (reserved for future use).
//
// Note that not all permutations of bits in this pattern represent a card.
// For example the 6 bits 011111 would designate a Club, but also an invalid
// rank. There are only 13 ranks, the rank value here (1111) has integer
// value 15. 
class BitCard 
{
public:
  BitCard() = default;

  BitCard(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
  { }

  // Returns the rank of the card.
  Rank get_rank() const { 
    return (Rank)(0b001111 & bits); 
  }

  // Returns the suit of the card.
  Suit get_suit() const { 
    return (Suit)((0b110000 & bits) >> 4); 
  }

  // Equality comparison
  friend bool operator==(BitCard a, BitCard b) {
    return a.bits == b.bits; 
  }
  friend bool operator!=(BitCard a, BitCard b) {
    return a.bits != b.bits; 
  }

  // Total ordering
  //
  // NOTE: This function defines an ordering that is equivalent to that in
  // GoodCard. This is because the suit is stored in the high order bits and
  // the rank in the low order bits. For example, 
  // 
  // - all Spades have the bit pattern 00rrrr, or the values 0 to 15.
  // - all Clubs have the bit pattern 01rrrr, or the values 16 to 31.
  // - all Diamonds have the bit pattern 10rrrr, or the values 32 to 47.
  // - all Clubs have the bit pattern 11rrrr, or the values 48 to 63.
  //
  // Within those value ranges, the Ranks of cards are the bits corresponding
  // to the integer values. Sorting these integer values will naturally
  // group all Spades before Clubs, Clubs before Diamonds, etc.
  friend bool operator<(BitCard a, BitCard b) {
    return a.bits < b.bits; 
  }
  friend bool operator>(BitCard a, BitCard b) {
    return a.bits > b.bits; 
  }
  friend bool operator<=(BitCard a, BitCard b) {
    return a.bits <= b.bits; 
  }
  friend bool operator>=(BitCard a, BitCard b) {
    return a.bits >= b.bits; 
  }

private:
  unsigned char bits;
};


/// Represents a deck of cards.
using BitDeck = std::vector<BitCard>;

/// Returns a standard deck of cards.
BitDeck get_bit_deck();


// Streaming
std::ostream& operator<<(std::ostream& os, BitCard c);
std::ostream& operator<<(std::ostream& os, const BitDeck& d);


