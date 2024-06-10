#include <glad.h>
//#define GLFW_DLL
#include "pch.h"
#include "core/game.h"


int main() {
    mystic::logger::init();
    mystic::game mainGame;
    mainGame.run();
    return 0;
}