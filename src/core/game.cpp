#include "game.h"

void game::print() {
    MYSTIC_INFO("Test");
    // spdlog::info("Welcome to spdlog!");
    // spdlog::info("Welcome to spdlog2!");
    // spdlog::error("Did this work?");
}

void game::run()
{
    MYSTIC_TRACE("Trace");
    MYSTIC_WARN("Warn");
    MYSTIC_ERROR("Error");
    MYSTIC_CRITICAL("crit");

    //m_height++;
    m_width++;
}

void game::shutdown() {
    m_height = 0;
    m_width = 0;
}
