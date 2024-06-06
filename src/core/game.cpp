#include "game.h"

void game::print() {
    std::cout << "width: " << m_width << " " << "height: " << m_height << std::endl;
}

void game::run()
{
    m_height++;
    m_width++;
}

void game::shutdown() {
    m_height = 0;
    m_width = 0;
}
