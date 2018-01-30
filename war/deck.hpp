#include "card.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class Deck
{
  public:
    Deck() {}
    ~Deck() {}
   
    void addCard(Card n)
    {
       deck.push_back(n);	    
    }
   
    Card removeCard()
    {
       Card n = deck.back();
       deck.pop_back();
       return n;
    }
   
    std::vector<Card> copyDeck()
    {
       return deck;
    }
    
    int size()
    { 
       return deck.size();
    }

    void displayDeck()
    {
      for(unsigned int i = 0; i < deck.size(); ++i)
      {
	 std::cout << "Element[" << i << "] = " << deck[i].getRank() << std::endl;
      }
      std::cout << std::endl;
    }

    bool searchDeck(Card n)
    {
       if (std::find(deck.begin(), deck.end(), n) != deck.end())
         return true;
       else
         return false;
    }

    private:
      std::vector<Card> deck;
};

Deck generateDeck(int size)
{
    Deck deck;
    bool cardThere;
    for(unsigned int i = 0; i < size; ++i)
    {
       Card n(static_cast<Rank>(rand() % End), static_cast<Suit>(rand() % Blank));
       cardThere = deck.searchDeck(n);
       if (!cardThere)
          deck.addCard(n);
       else
          --i;
    }
    return deck;
}

void divideDeck(Deck orig, Deck &p1, Deck &p2)
{
   int i = orig.size() - 1;
   while (i > 0)
   {
      p1.addCard(orig.removeCard());
      p2.addCard(orig.removeCard());
      i -= 2;
   }
}
