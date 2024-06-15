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
        void Run();
        void ShutDown();
        virtual void LoadContent();
        virtual void Update(GameTime* gametime);
        virtual void Draw(GameTime* gameTime, SpriteBatch* spriteBatch);
        virtual void UnloadContent();
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