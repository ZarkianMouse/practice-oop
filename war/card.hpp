#include <iostream>


// A card is basically a pair of rank and suit.
// How do you represent a rank?
// How do you represent a suit?
//    - Just use ints. Right?
// How do you represent a pair of things?
// Defines a new type (user-defined type). Sometimes called
// a kind of type constructor (ignore that).

enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

// Represents the suits of a card.
enum Suit {
    Hearts, // This is called an enumerator
    Diamonds,
    Clubs,
    Spades,
};


// Technically this is a class.
struct Card {
    Rank rank;
    Suit suit;
};
