// #include <iostream>

// int main() {
//     std::cout << "test" << std::endl;

// }














//original - after this is all figured out =/
#include <glad.h>
//#define GLFW_DLL
#include "pch.h"
#include "core/game.h"
#include <iostream>



int main() {
    // mystic::logger::init();
    // mystic::logger::getInstance()->trace("sup");
    //MYSTIC_INFO("Boot.");
    std::cout << "test" << std::endl;
    std::cout << "test2" << std::endl;
    // MYSTIC_INFO("Boot.");
    mystic::game mainGame;
    mainGame.run();
    // MYSTIC_INFO("Game closed.");
    return 0;
}