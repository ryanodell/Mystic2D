//TODO: Do this when compiling, not directly in code:
#define DEBUG
#include <glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "pch.h"
#include "core/game.h"
#include <iostream>
#include "sandbox/TestGame.h"
#include "core/Log.h"


int main() {
    Mystic::Log::Init();
    std::cout << "Init" << std::endl;
    TestGame mainGame;
    mainGame.Run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}