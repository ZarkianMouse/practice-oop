
#include <iostream>

class Player {
  public:
    Player(std::string n) : name(n), score(0) {}
    ~Player() {}

    const std::string getName() {return name;}
    int getScore() {return score;}
    void updateScore() {++score;}
  private:
    std::string name;
    int score;
};

