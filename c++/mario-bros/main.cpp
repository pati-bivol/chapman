#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Game.h"

int main(int argc, char *argv[]) {
    Game game = Game("spec.txt", "log.txt");
    game.play();
    return 0;
}