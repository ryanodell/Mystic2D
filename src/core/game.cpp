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
            game::update(&gt);
            game::draw(&gt, m_spriteBatch);
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
    void game::update(gameTime* gametime) {
        //MYSTIC_TRACE("Update called");
    }
    void game::draw(gameTime* gameTime, spriteBatch* spriteBatch) {
        // MYSTIC_TRACE("Draw called");
    }
    void game::init() {
        if(m_initialized) {
            //MYSTIC_WARN("Game already initialized");
            return;
        }
        m_gameWindow = new gameWindow("Name", 800, 600);
        m_spriteBatch = new mystic::spriteBatch();
        m_initialized = true;
    }
}