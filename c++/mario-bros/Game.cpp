#include "Game.h"

Game::Game(string inputFile, string outputFile) {
    std::fstream file(inputFile);
    int L, N, V, coinRatio, nothingRatio, goombaRatio, koopaRatio, mushroomRatio;
    file >> L >> N >> V >> coinRatio >> nothingRatio >> goombaRatio >> koopaRatio >> mushroomRatio;

    Game::L = L;
    Game::N = N;

    log.open(outputFile);

    world = new World(L, N, coinRatio, nothingRatio, goombaRatio, koopaRatio, mushroomRatio, log);
    mario = new Mario(L, V, N, log);

}
//
//Game::~Game() {
//    log.close();
//    delete world;
//    delete mario;
//}

void Game::play() {
    while (!isGameOver()) {
        world->interactWith(mario);
    }
    if (mario->V <= 0) {
        log << "WE LOST THE GAME. " << endl;
    } else {
        log << "WE WON THE GAME. " << endl;
    }
}

bool Game::isGameOver() {
    if (mario->level >= L) {
        return true;
    }
    return mario->V <= 0;
}

