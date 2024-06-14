#include <glad.h>
#include "pch.h"
#include "core/game.h"
#include <iostream>
#include "sandbox/TestGame.h"



int main() {
    std::cout << "Init" << std::endl;    
    TestGame mainGame;
    mainGame.Run();
    // mystic::game mainGame;
    // mainGame.run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}