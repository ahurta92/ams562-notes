#include <iostream>
#include <random>
#include <vector>

class Marble {
private:
  int weight;
  std::string color;

public:
  Marble() {
    int rand_color = rand() % 3;
    if (rand_color == 0) {
      color = "red";
    } else if (rand_color == 1) {
      color = "blue";
    } else {
      color = "yellow";
    }
    weight = ((rand() % 5) + 1);
    // marbles can weigh from values 1 to 5
  }
  void set_color(std::string col) { color = col; }
  void set_weight(int w) { weight = w; }
  std::string get_color() const { return color; }
  int get_weight() const { return weight; }
};

std::vector<Marble> getRandomMarbles(int N) {

    std::vector<Marble> marbles(N);
    srand(1);
    for (auto &marble : marbles) {
        int rand_color = rand() % 3;
        if (rand_color == 0) {
            marble.set_color("red");
        } else if (rand_color == 1) {
            marble.set_color("blue");
        } else {
            marble.set_color("yellow");
        }
        marble.set_weight((rand() % 5) + 1);
        // marbles can weigh from values 1 to 5
    }
    return marbles;
}
