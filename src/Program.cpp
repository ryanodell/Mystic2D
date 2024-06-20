// #include <glad.h>
// #include "pch.h"
// #include "core/game.h"
// #include <iostream>
// #include "sandbox/TestGame.h"

//TODO: Do this when compiling, not directly in code:
#define DEBUG
//
#include <glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "pch.h"
#include "core/game.h"
#include <iostream>
#include "sandbox/TestGame.h"


int main() {
    std::cout << "Init" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    TestGame mainGame;
    mainGame.Run();
    // mystic::game mainGame;
    // mainGame.run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}