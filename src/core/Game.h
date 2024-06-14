#ifndef GAME_H
#define GAME_H
#include "../../vendor/GLAD/include/glad.h"
#include <chrono>
#include "../pch.h"
#include "gameWindow.h"
#include "render/spriteBatch.h"

namespace Mystic {
class Game {
    public:
        Game();
        virtual ~Game();
        void run();
        void shutDown();
        virtual void loadContent();
        virtual void update(GameTime* gametime);
        virtual void draw(GameTime* gameTime, SpriteBatch* spriteBatch);
    private:
        GameWindow* m_gameWindow = nullptr;
        SpriteBatch* m_spriteBatch = nullptr;
        int m_width, m_height;
        bool m_initialized = false;
        bool m_running = false;
    private:
        void init();
    };
}
#endif