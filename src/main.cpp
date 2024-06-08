#include "pch.h"
#include "core/game.h"


int main() {
    game mainGame;
    mainGame.print();
    for(int i = 0; i < 5; i++) {
        mainGame.run();
        mainGame.print();
    }
    mainGame.shutdown();
    mainGame.print();
    return 0;
}