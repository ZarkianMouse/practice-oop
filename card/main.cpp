// Driver Program for Card Class Practice
// Copyright of Naomi Burhoe c. Spring 2018

#include <iostream>
#include  <cassert>
#include <vector>
//#include "card.hpp"
//#include "bitcard.hpp"
//#include "inheritcard.hpp"
#include "deck.hpp"


int main() {
   std::cout << "Hello World\n";
   Deck myDeck {
    StandardCard(Ace, Spades),
    StandardCard(Two, Spades),
    StandardCard(Three, Spades),
    StandardCard(Four, Spades),
    StandardCard(Five, Spades),
    StandardCard(Six, Spades),
    StandardCard(Seven, Spades),
    StandardCard(Eight, Spades),
    StandardCard(Nine, Spades),
    StandardCard(Ten, Spades),
    StandardCard(Jack, Spades),
    StandardCard(Queen, Spades),
    StandardCard(King, Spades),

    StandardCard(Ace, Clubs),
    StandardCard(Two, Clubs),
    StandardCard(Three, Clubs),
    StandardCard(Four, Clubs),
    StandardCard(Five, Clubs),
    StandardCard(Six, Clubs),
    StandardCard(Seven, Clubs),
    StandardCard(Eight, Clubs),
    StandardCard(Nine, Clubs),
    StandardCard(Ten, Clubs),
    StandardCard(Jack, Clubs),
    StandardCard(Queen, Clubs),
    StandardCard(King, Clubs),

    StandardCard(Ace, Diamonds),
    StandardCard(Two, Diamonds),
    StandardCard(Three, Diamonds),
    StandardCard(Four, Diamonds),
    StandardCard(Five, Diamonds),
    StandardCard(Six, Diamonds),
    StandardCard(Seven, Diamonds),
    StandardCard(Eight, Diamonds),
    StandardCard(Nine, Diamonds),
    StandardCard(Ten, Diamonds),
    StandardCard(Jack, Diamonds),
    StandardCard(Queen, Diamonds),
    StandardCard(King, Diamonds),

    StandardCard(Ace, Hearts),
    StandardCard(Two, Hearts),
    StandardCard(Three, Hearts),
    StandardCard(Four, Hearts),
    StandardCard(Five, Hearts),
    StandardCard(Six, Hearts),
    StandardCard(Seven, Hearts),
    StandardCard(Eight, Hearts),
    StandardCard(Nine, Hearts),
    StandardCard(Ten, Hearts),
    StandardCard(Jack, Hearts),
    StandardCard(Queen, Hearts),
    StandardCard(King, Hearts),

    JokerCard(Black),
    JokerCard(Red),
  };
   std::cout << myDeck << '\n';
    myDeck.~Deck();
}
