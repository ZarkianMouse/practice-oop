#include "game.hpp"
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

const int DECK_SIZE = 52;

int
 main() {
    std::cout << "hello world\n";

    std::cout << "3...2...1...War!!\n";
    
    War newGame;
    
    playWar(newGame, DECK_SIZE);

    newGame.declareWinner();
    
    std::cout << "Thanks for playing\n";
}
