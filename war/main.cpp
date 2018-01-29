#include "card.hpp"
#include "player.hpp"
#include "deck.hpp"
#include <iostream>

// What's in a game of war?
// - cards (values between 1 and 13, suits)
// - deck
// - players (hands?)... might be stack-like
// - sacrifice pile
//    - compare cards -- top card "wins"
//    - equal... flip some extra cards, recurse
//    - winning player gets sacrifices (how?)

int
 main() {
    std::cout << "hello world\n";

    test();
    std::cout << "3...2...1...War!!\n";
    
    Deck newDeck(52);
    newDeck.allocateDeck();
    std::cout << "deck shuffled\n";
    //Loop
    //generateDeck
    //divideDeck
    
    //gameLoop
    //revealCard1
    //revealCard2
    //declareWinner
    //discard

    //endGame
}
