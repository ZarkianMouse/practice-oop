#include <iostream>

class Player {
  public:
    Player(std::string n) : name(n), score(0) {}
    ~Player() {}

    std::string getName() {return name;}
    int getScore() {return score;}
  private:
    std::string name;
    int score;
};


void test()
{
  Player p1("Joe");
  std::cout << p1.getName() << " " << p1.getScore() << '\n';
  return;
}
