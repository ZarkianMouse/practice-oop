
#include "player.hpp"
#include "deck.hpp"
#include <iostream>
#include <vector>

// What's in a game of war?
// - cards (values between 1 and 13, suits)
// - deck
// - players (hands?)... might be stack-like
// - sacrifice pile
//    - compare cards -- top card "wins"
//    - equal... flip some extra cards, recurse
//    - winning player gets sacrifices (how?)

const int SIZE = 52;

int
 main() {
    std::cout << "hello world\n";

    test();
    std::cout << "3...2...1...War!!\n";
    
    Player p1("Player 1");
    Player p2("Player 2");
    std::cout << p1.getName() << " vs. " << p2.getName() << '\n';
    
    Deck myDeck = generateDeck(SIZE);
    std::cout << "Deck generated\n";
    
    Deck deckP1;
    Deck deckP2;
    divideDeck(myDeck, deckP1, deckP2);
    std::cout << "Decks divided\n";

    //gameLoop
    //revealCard1
    //revealCard2
    //declareWinner
    //discard

    //endGame
}
