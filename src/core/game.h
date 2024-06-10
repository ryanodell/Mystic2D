#ifndef GAME_H
#define GAME_H
#include <chrono>
#include "../pch.h"
#include "gameWindow.h"
#include "render/spriteBatch.h"

namespace mystic {
class game {
    public:
        game();
        virtual ~game();
        void run();
        virtual void loadContent();
        virtual void update(gameTime* gametime);
        virtual void draw(gameTime* gameTime, spriteBatch* spriteBatch);
    private:
        gameWindow* m_gameWindow = nullptr;
        spriteBatch* m_spriteBatch = nullptr;
        int m_width, m_height;
        bool m_initialized = false;
        bool m_running = false;
    private:
        void init();
    };
}
#endif