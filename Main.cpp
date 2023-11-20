#include <iostream>
#include <memory>
#include "Player.h"
using namespace std;

int main() {
    unique_ptr<Game> game(new Game());
    game -> attack();
}