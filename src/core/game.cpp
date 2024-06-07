#include "game.h"

void game::print() {
    spdlog::info("Welcome to spdlog!");
    spdlog::info("Welcome to spdlog2!");
    spdlog::error("Did this work?");
}

void game::run()
{

    //m_height++;
    m_width++;
}

void game::shutdown() {
    m_height = 0;
    m_width = 0;
}
