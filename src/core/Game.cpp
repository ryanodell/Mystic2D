#include "game.h"

namespace Mystic {
Game::Game() {
}

Game::~Game() {
    delete m_gameWindow;
    delete m_renderer;
}

void Game::Run() {
    m_running = true;
    Game::init();
    GameTime gt;
    LoadContent();
    while (!m_gameWindow->WindowShouldClose()) {
        Update(&gt);
        Draw(&gt, m_renderer);
        m_gameWindow->SwapBuffers();
        gt.Tick();
    }
    UnloadContent();
}
void Game::ShutDown() {
}
void Game::LoadContent() {
    // MYSTIC_TRACE("Load called");
}
void Game::Update(GameTime* gametime) {}
void Game::Draw(GameTime* gameTime, Renderer* renderer) {}
void Game::UnloadContent() {}

void Game::init() {
    std::cout << "Init from game.cpp" << std::endl;
    if (m_initialized) {
        std::cout << "Game already initialized" << std::endl;
        return;
    }
    glfwInit();    
    m_gameWindow = new GameWindow("Name", 960, 540);
    input = Input(m_gameWindow->GetInternalWindow());
    
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  
    //glEnable(GL_CULL_FACE);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    // glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    // glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);

    // glfwWindowHint(GLFW_ALPHA_BITS, 8);
    // glfwWindowHint(GLFW_DEPTH_BITS, 24);
    // glfwWindowHint(GLFW_STENCIL_BITS, 8);
    if (!gltInit()) {
        MYSTIC_CORE_ERROR("Failed to initialize glText");
        glfwTerminate();
    }
    m_renderer = new Renderer();
    m_renderer->Init();
    m_renderer->SetClearColor(COLOR_BLACK);
    m_initialized = true;
}
}  // namespace Mystic