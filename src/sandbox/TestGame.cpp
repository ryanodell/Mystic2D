#include "testGame.h"

#include "../core/content/Shader.h"

TestGame::TestGame() {}

void TestGame::LoadContent() {
    m_renderer = new Renderer();
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_4.glsl");
    m_texture = Mystic::Texture::LoadFromFile("images/kruggsmash.png");
    m_renderer->Init();
    m_renderer->SetClearColor(COLOR_BLACK);
}

static int frameCount = 0;

void TestGame::Update(Mystic::GameTime *gametime) {
    Mystic::Game::Update(gametime);
    if (input.IsKeyPressed(GLFW_KEY_D)) {
        playerPosition = glm::vec2(playerPosition.x + 1.0f, playerPosition.y);
    }
    if (input.IsKeyPressed(GLFW_KEY_A)) {
        playerPosition = glm::vec2(playerPosition.x - 1.0f, playerPosition.y);
    }
    if (input.IsKeyPressed(GLFW_KEY_W)) {
        playerPosition = glm::vec2(playerPosition.x, playerPosition.y - 1.0f);
    }
    if (input.IsKeyPressed(GLFW_KEY_S)) {
        playerPosition = glm::vec2(playerPosition.x, playerPosition.y + 1.0f);
    }
    frameCount++;
}

void TestGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {
    m_texture->Use();
    m_renderer->Clear();
    glm::mat4 model = glm::translate(glm::mat4(1.0f), baseScreen);
    glm::mat4 mvp = proj * view * model;
    m_renderer->BeginBatch(mvp);
    Rectangle srcRect1 = Rectangle(32.0f, 32.0f, 32.0f, 32.0f);
    Rectangle srcRect2 = Rectangle(64.0f, 32.0f, 32.0f, 32.0f);
    Rectangle srcRect3 = Rectangle(96.0f, 32.0f, 32.0f, 32.0f);
    // m_renderer->Draw(glm::vec2(32.0f, 32.0f), m_texture, m_shader, &srcRect1, COLOR_WHITE);
    // m_renderer->Draw(glm::vec2(0.0f, 0.0f), m_texture, m_shader, &srcRect1, COLOR_RED);
    // m_renderer->Draw(glm::vec2(32.0f, 0.0f), m_texture, m_shader, &srcRect2, COLOR_GREEN);
    // m_renderer->Draw(glm::vec2(64.0f, 32.0f), m_texture, m_shader, &srcRect2, COLOR_BLUE);
    for(int i = 0; i < 15; i++) {
        m_renderer->Draw(glm::vec2(64.0f, 32.0f), m_texture, m_shader, &srcRect2, COLOR_BLUE);
    }
    // m_renderer->Draw(glm::vec2(64.0f, 64.0f), m_texture, m_shader, &srcRect3, COLOR_BLUE);
    //m_renderer->Draw(playerPosition, m_texture, m_shader, &srcRect3, COLOR_BLUE);
    m_renderer->EndBatch(m_shader);
}

void TestGame::UnloadContent() {
    m_va.Destroy();
    m_vb.Destroy();
    m_ib.Destroy();
    delete m_shader;
    delete m_texture;
    delete m_renderer;
}