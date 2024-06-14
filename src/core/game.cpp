#include "game.h"

namespace mystic {
    game::game() {
    }

    game::~game() {
        delete m_gameWindow;
        delete m_spriteBatch;
    }

    void game::run() {
        m_running = true;
        game::init();
        gameTime gt;
        game::loadContent();
        while(!m_gameWindow->windowShouldClose()) {
            update(&gt);
            draw(&gt, m_spriteBatch);
            m_gameWindow->render();
            gt.tick();
        }
    }
    void game::shutDown() {

    }
    void game::loadContent()
    {
        //MYSTIC_TRACE("Load called");
    }
    void game::update(gameTime* gametime) { }
    void game::draw(gameTime* gameTime, spriteBatch* spriteBatch) { }

    void game::init() {
        std::cout << "Init from game.cpp" << std::endl;
        if(m_initialized) {
            std::cout << "Game already initialized" << std::endl;
            return;
        }
        m_gameWindow = new gameWindow("Name", 800, 600);
        m_spriteBatch = new mystic::spriteBatch();
        m_initialized = true;
    }
}