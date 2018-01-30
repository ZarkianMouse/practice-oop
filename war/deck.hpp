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
   
    std::vector<Card> copyDeck()
    {
       return deck;
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

Deck generateDeck()
{
    Card newCard(Ace, Spades);
    Deck myDeck;
    myDeck.addCard(newCard);

    
    Card newCard2(Ace, Spades);
    bool cardThere = myDeck.searchDeck(newCard2);
    if (cardThere)
        std::cout << "true\n";

}
