#include "player.hpp"
#include "deck.hpp"
#include <iostream>


class War {
  public :
    War() {}
    ~War() {}
   
   void showCards(Player &first, Deck &p1, Player &second, Deck &p2)
   {
      Card card1 = p1.removeCard();
      Card card2 = p2.removeCard();

      std::cout << first.getName() << "  " << card1.displayCard() << '\n'
                << second.getName() << "  " << card2.displayCard() << '\n';

      if (card1.getRank() > card2.getRank())
      {
         std::cout << first.getName() << " wins the round\n";
         first.updateScore();
      }
      else if (card2.getRank() > card1.getRank())
      {
         std::cout << second.getName() << " wins the round\n";
         second.updateScore();
      }
      else
         std::cout << "Tie! Too bad for both players\n";
      
   }
   
   void setWinner(std::string w)
   {
      winner = w;
   }
   
   void declareWinner()
   {
      std::cout << winner << '\n';
   }

   private :
     std::string winner;

};


void playWar(War &newGame, int SIZE)
{
    Player p1("Player 1");
    Player p2("Player 2");
    std::cout << p1.getName() << " vs. " << p2.getName() << '\n';
    
    Deck myDeck = generateDeck(SIZE);
    std::cout << "Deck shuffled\n";
    
    Deck deckP1;
    Deck deckP2;
    divideDeck(myDeck, deckP1, deckP2);
    std::cout << "Deck dealed\n";

    for (unsigned int i = 0; i < deckP1.size(); i++)
    {
        newGame.showCards(p1, deckP1, p2, deckP2);
        std::cout << p1.getName() << " score: " << p1.getScore() << '\n'
                  << p2.getName() << " score: " << p2.getScore() << '\n';

    }
    
    if (p1.getScore() > p2.getScore())
    {
        newGame.setWinner(p1.getName() + " wins!");
    }
    
    else if (p2.getScore() > p1.getScore())
    {
        newGame.setWinner(p2.getName() + " wins!");
    }
    
    else
    {
        newGame.setWinner("It's a tie!");
    }
}

