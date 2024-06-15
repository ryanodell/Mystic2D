// #include <glad.h>
// #include "pch.h"
// #include "core/game.h"
// #include <iostream>
// #include "sandbox/TestGame.h"

#include <glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
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