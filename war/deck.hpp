#include "card.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>


class Deck {
  public:
    Deck(int s) : size(s), deck[size]() {}
    void allocateDeck();
    bool searchDeck(Card, int);
    ~Deck() {}
  private:
    int size;
    Card deck[size];

};


void Deck::allocateDeck()
{
  bool found = false;
  for (int i = 0; i < size; i++)
  {
    Card n = newCard();
    
    found = searchDeck(n, i);
    if (found == false)
      deck[i] = n;
    else
      --i;
  }
}


Card newCard()
{
  Card n(static_cast<Rank>(rand() % End), static_cast<Suit>(rand() % Blank));
  return n;
}

bool Deck::searchDeck(Card n, int nsize)
{
  for (int i = 0; i < nsize; i++)
  {
    if (n == deck[i])
      return true;
  }
  return false;
}


