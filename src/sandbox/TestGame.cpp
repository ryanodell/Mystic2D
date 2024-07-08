#include "testGame.h"

#include "../core/content/Shader.h"

TestGame::TestGame() : rng(rd()), dist(0, 2) {

}

void TestGame::LoadContent() {
    // m_renderer = new Renderer();
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_4.glsl");
    m_texture = Mystic::Texture::LoadFromFile("images/kruggsmash.png");
    // m_renderer->Init();
    // m_renderer->SetClearColor(COLOR_BLACK);

    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 10.0); // range [1.0, 10.0]
    Rectangle srcRect1 = Rectangle(32.0f, 32.0f, 32.0f, 32.0f);
    Rectangle srcRect2 = Rectangle(64.0f, 32.0f, 32.0f, 32.0f);
    Rectangle srcRect3 = Rectangle(96.0f, 32.0f, 32.0f, 32.0f);
    int tileIndex = 0;
    float tileSize = 32.0f;
    for(int y = 0; y < 25; y++) {
        for(int x = 0; x < 25; x++) {
            int randomNumber = generate();
            Rectangle recToUse;
            Color colorToUse = COLOR_WHITE;
            if(randomNumber == 0) {
                recToUse = srcRect1;
                colorToUse = COLOR_RED;
            }
            if(randomNumber == 1) {
                recToUse = srcRect2;
                colorToUse = COLOR_GREEN;
            }
            if(randomNumber == 2) {
                recToUse = srcRect3;
                colorToUse = COLOR_BLUE;
            }
            m_spriteData[tileIndex] = TempSpriteData({x * tileSize, y * tileSize }, m_texture, recToUse, colorToUse);
            tileIndex++;
        }
    }
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


void TestGame::Draw(Mystic::GameTime *gameTime, Renderer* renderer) {
    m_texture->Use();
    renderer->Clear();
    glm::mat4 model = glm::translate(glm::mat4(1.0f), baseScreen);
    glm::mat4 mvp = proj * view * model;
    renderer->BeginBatch(m_shader, mvp);
    for(int i = 0; i < 25 * 25; i++) {
        TempSpriteData current = m_spriteData[i];
        renderer->Draw(current.Position, current.Texture, &current.SrcRect, current.SpriteColor);
    }
    renderer->EndBatch();
}

void TestGame::UnloadContent() {
    m_va.Destroy();
    m_vb.Destroy();
    m_ib.Destroy();
    delete m_shader;
    delete m_texture;
}