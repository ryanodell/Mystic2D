//TODO: Do this when compiling, not directly in code:
#define DEBUG
#include <glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "core/game.h"
#include <iostream>
#include "sandbox/TestGame.h"
#include "core/Log.h"
// #include "../vendor/FREETYPE/ft2build.h"
// #include FT_FREETYPE_H  



int main() {    
    Mystic::Log::Init(LogLevel::TRACE, "log.txt");
    MYSTIC_INFO("Init");
    TestGame mainGame;
    mainGame.Run();
    MYSTIC_INFO("Shut Down");
    return 0;
}

/*
Logger usage:
    MYSTIC_CORE_TRACE("This is a core trace message");
    MYSTIC_CORE_INFO("This is a core info message");
    MYSTIC_CORE_WARN("This is a core warning message");
    MYSTIC_CORE_ERROR("This is a core error message");
    MYSTIC_CORE_CRITICAL("This is a core critical message");

    MYSTIC_TRACE("This is a client trace message");
    MYSTIC_INFO("This is a client info message");
    MYSTIC_WARN("This is a client warning message");
    MYSTIC_ERROR("This is a client error message");
    MYSTIC_CRITICAL("This is a client critical message");
*/