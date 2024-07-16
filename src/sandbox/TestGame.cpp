#include "testGame.h"

#include "../core/content/Shader.h"

TestGame::TestGame() : rnd(0, 2),
                       m_camera(0.0f, 960.0f, 540.0f, 0.0f, 2.0f) {
}

void TestGame::LoadContent() {
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_4.glsl");
    m_texture = Mystic::Texture::LoadFromFile("images/kruggsmash.png");

    Rectangle srcRect1 = Rectangle(32.0f, 32.0f, 32.0f, 32.0f);
    Rectangle srcRect2 = Rectangle(64.0f, 32.0f, 32.0f, 32.0f);
    Rectangle srcRect3 = Rectangle(96.0f, 32.0f, 32.0f, 32.0f);
    int tileIndex = 0;
    float tileSize = 32.0f;
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 25; x++) {
            int randomNumber = rnd.GetRandomNumber();
            Rectangle recToUse;
            Color colorToUse = COLOR_WHITE;
            if (randomNumber == 0) {
                recToUse = srcRect1;
                colorToUse = COLOR_RED;
            }
            if (randomNumber == 1) {
                recToUse = srcRect2;
                colorToUse = COLOR_GREEN;
            }
            if (randomNumber == 2) {
                recToUse = srcRect3;
                colorToUse = COLOR_BLUE;
            }
            m_spriteData[tileIndex] = TempSpriteData({x * tileSize, y * tileSize}, m_texture, recToUse, colorToUse);
            tileIndex++;
        }
    }
}

static int frameCount = 0;

void TestGame::Update(Mystic::GameTime *gametime) {
    Mystic::Game::Update(gametime);
    if (input.IsKeyPressed(GLFW_KEY_D)) {
        // playerPosition = glm::vec2(playerPosition.x + 1.0f, playerPosition.y);
        glm::vec3 current = m_camera.GetPosition();
        glm::vec3 target = glm::vec3(current.x + 1.0f, current.y, current.z);
        m_camera.SetPosition(target);
    }
    if (input.IsKeyPressed(GLFW_KEY_A)) {
        // playerPosition = glm::vec2(playerPosition.x - 1.0f, playerPosition.y);
        glm::vec3 current = m_camera.GetPosition();
        glm::vec3 target = glm::vec3(current.x - 1.0f, current.y, current.z);
        m_camera.SetPosition(target);
    }
    if (input.IsKeyPressed(GLFW_KEY_W)) {
        // playerPosition = glm::vec2(playerPosition.x, playerPosition.y - 1.0f);
        glm::vec3 current = m_camera.GetPosition();
        glm::vec3 target = glm::vec3(current.x, current.y - 1.0f, current.z);
        m_camera.SetPosition(target);
    }
    if (input.IsKeyPressed(GLFW_KEY_S)) {
        // playerPosition = glm::vec2(playerPosition.x, playerPosition.y + 1.0f);
        glm::vec3 current = m_camera.GetPosition();
        glm::vec3 target = glm::vec3(current.x, current.y + 1.0f, current.z);
        m_camera.SetPosition(target);
    }
    if (input.IsKeyPressed(GLFW_KEY_SPACE)) {
        if (m_camera.GetZoom() == 1.0f) {
            m_camera.SetZoom(2.0f);
        } else {
            m_camera.SetZoom(1.0f);
        }
    }
    frameCount++;
}

void TestGame::Draw(Mystic::GameTime *gameTime, Renderer *renderer) {
    m_texture->Use();
    renderer->Clear();
    glm::mat4 model = glm::translate(glm::mat4(1.0f), baseScreen);
    glm::mat4 mvp = proj * view * model;
    glm::mat4 testCamMat = m_camera.GetViewProjectionMatrix();
    // renderer->BeginBatch(m_shader, mvp);
    renderer->BeginBatch(m_shader, testCamMat);
    for (int i = 0; i < 25 * 25; i++) {
        TempSpriteData current = m_spriteData[i];
        renderer->Draw(current.Position, current.Texture, &current.SrcRect, current.SpriteColor);
    }
    renderer->EndBatch();
    
    GLTtext *text1 = gltCreateText();
    gltSetText(text1, "Hello World!");
    gltBeginDraw();

    gltColor(1.0f, 1.0f, 1.0f, 1.0f);
    gltDrawText(text1, (GLfloat*)&m_camera.GetViewProjectionMatrix());
    //gltDrawText2D(text1, 0.0f, 0.0f, 1.0f);  // x=0.0, y=0.0, scale=1.0

    gltEndDraw();
}

void TestGame::UnloadContent() {
    delete m_shader;
    delete m_texture;
}