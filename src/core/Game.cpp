#include "game.h"

namespace Mystic {
    Game::Game() {
    }

    Game::~Game() {
        delete m_gameWindow;
        delete m_spriteBatch;
    }

    void Game::run() {
        m_running = true;
        Game::init();
        GameTime gt;
        Game::loadContent();
        while(!m_gameWindow->windowShouldClose()) {
            update(&gt);
            draw(&gt, m_spriteBatch);
            m_gameWindow->render();
            gt.tick();
        }
    }
    void Game::shutDown() {

    }
    void Game::loadContent()
    {
        //MYSTIC_TRACE("Load called");
    }
    void Game::update(GameTime* gametime) { }
    void Game::draw(GameTime* gameTime, SpriteBatch* spriteBatch) { }

    void Game::init() {
        std::cout << "Init from game.cpp" << std::endl;
        if(m_initialized) {
            std::cout << "Game already initialized" << std::endl;
            return;
        }
        m_gameWindow = new GameWindow("Name", 800, 600);
        m_spriteBatch = new Mystic::SpriteBatch();
        m_initialized = true;
    }
}