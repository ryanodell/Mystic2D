#include <glad.h>
#include "pch.h"
#include "core/game.h"
#include <iostream>
#include "sandbox/testGame.h"



int main() {
    std::cout << "Init" << std::endl;    
    testGame mainGame;
    mainGame.run();
    // mystic::game mainGame;
    // mainGame.run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}