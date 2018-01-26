#include "card.hpp"
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

    Rank r1 = King;
    Rank r2 = Queen;

    std::cout << (r1 == r2) << '\n';
    std::cout << (r1 < r2) << '\n';

// We can cast int to rank.
// This is a potential error condition. You are obliged
// to verify that Ace <= n0 && n0 <= King.

    int n0;
    Rank r5 = static_cast<Rank>(n0);

// This is a widening conversion and  is guaranteed
// to work (almost certainly).

    int n = King;
}
