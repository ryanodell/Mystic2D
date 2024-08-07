#ifndef GAME_H
#define GAME_H
#include "../../vendor/GLAD/include/glad.h"
#include <chrono>
#include "../pch.h"
#include "gameWindow.h"
#include "../core/Input.h"
#include "content/ContentManager.h"
#include "render/Renderer.h"
#define GLT_IMPLEMENTATION
#include "gltext.h"

namespace Mystic {
class Game {
    public:
        Game();
        virtual ~Game();
        void Run();
        void ShutDown();
        //ContentManager ContentManager;
        virtual void LoadContent();
        virtual void Update(GameTime* gametime);
        virtual void Draw(GameTime* gameTime, Renderer* renderer);
        virtual void UnloadContent();
        Input input;
    private:
        GameWindow* m_gameWindow = nullptr;
        Renderer* m_renderer = nullptr;
        int m_width, m_height;
        bool m_initialized = false;
        bool m_running = false;
    private:
        void init();
    };
}
#endif