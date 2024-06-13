#include <glad.h>
#include "pch.h"
#include "core/game.h"
#include <iostream>



int main() {
    std::cout << "Init" << std::endl;    
    mystic::game mainGame;
    mainGame.run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}