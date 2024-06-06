#include "pch.h"
#include "core/game.h"
// #define SPDLOG_HEADER_ONLY
// #include "spdlog/spdlog.h"


int main() {

    game mainGame;
    for(int i = 0; i < 5; i++) {
        mainGame.run();
        mainGame.print();
    }
    mainGame.shutdown();
    mainGame.print();
    std::cin.get();
    return 0;
}