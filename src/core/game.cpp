#include "game.h"

namespace mystic {
    game::game()
    {
    }

    game::~game()
    {
    }

    void game::run() {
        game::init();
    }
    void game::loadContent()
    {
    }
    void game::update(gameTime &gametime)
    {
    }
    void game::draw(gameTime &gameTime, spriteBatch &spriteBatch)
    {
    }
    void game::init()
    {
        if(m_initialized) {
            MYSTIC_WARN("Game already initialized");
            return;
        }
        m_initialized = true;
    }
}