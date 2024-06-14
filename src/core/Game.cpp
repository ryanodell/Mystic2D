#include "game.h"

namespace Mystic {
    Game::Game() {
    }

    Game::~Game() {
        delete m_gameWindow;
        delete m_spriteBatch;
    }

    void Game::Run() {
        m_running = true;
        Game::init();
        GameTime gt;
        Game::LoadContent();
        while(!m_gameWindow->WindowShouldClose()) {
            Update(&gt);
            Draw(&gt, m_spriteBatch);
            m_gameWindow->Render();
            gt.Tick();
        }
    }
    void Game::ShutDown() {

    }
    void Game::LoadContent()
    {
        //MYSTIC_TRACE("Load called");
    }
    void Game::Update(GameTime* gametime) { }
    void Game::Draw(GameTime* gameTime, SpriteBatch* spriteBatch) { }

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