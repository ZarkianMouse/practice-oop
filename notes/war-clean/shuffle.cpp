
#include "bitcard.hpp"

int main()
{
  // declares an empty vector.
  Deck d0 {};

  Card c {Ace, Spades};

  // Declares a deck to be a sequence of cards.
  // Explicitly declare what each card is.
  Deck d1 {
    {Ace, Spades}, // Initializes a card object
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

  
  // std::minstd_rand prng;
  std::default_random_engine prng;

  shuffle(d1.begin(), d1.end(), prng);

#if 0
  // Dynamically initialize each card.
  Deck d2;
  for (int s = Spades; s <= Hearts; ++s) {
    for (int r = Ace; r <= King; ++r) {
      // Creates and then copies a card into the
      // vector.
      d1.push_back({static_cast<Rank>(r),
                    static_cast<Suit>(s)});

      // Like above, but only one Card object is
      // created. Forwards arguments to be used as
      // arguments to a constructor.
      //
      // Use this if creating an object requires
      // dynamic allocation.
      d1.emplace_back(static_cast<Rank>(r),
                      static_cast<Suit>(s));

    }
  }
#endif

}
