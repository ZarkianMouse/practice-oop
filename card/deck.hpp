// Deck Data Structure
// Copyright of Naomi Burhoe c. Spring 2018

#include <iosfwd>
#include <vector>
#include <initializer_list>
#include "card.hpp"


class Deck : public std::vector<Card*>
{
public:
 

  Deck(std::initializer_list<Card*> list)
    : std::vector<Card*>(list)
  { }

  Deck(const Deck& d)
  {
    for (Card* c : d) {
      push_back(c->clone());
    }
  }


  ~Deck() {
    for (Card* c : *this)
      delete c;
  }
};


