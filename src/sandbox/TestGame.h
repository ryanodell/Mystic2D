#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/Buffer.h"
#include "../core/content/Shader.h"
#include "../core/content/Texture.h"
#include "../core/render/Renderer.h"
#include "../core/render/TextRenderer.h"
#include "../core/OrthographicCamera.h"
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"
#include <optional>
#include <GLFW/glfw3.h>
#include <random>

using namespace Mystic;

struct TempSpriteData {
    TempSpriteData() { }
    ~TempSpriteData() {}
    glm::vec2 Position;
    Texture* Texture;
    Rectangle SrcRect;
    Color SpriteColor;
    TempSpriteData(glm::vec2 position, Mystic::Texture* texture, Rectangle rect, Color color) 
        : Position(position), Texture(texture), SrcRect(rect), SpriteColor(color) { }
};

class TestGame : public Game {
   public:
    TestGame();
    void LoadContent();
    void Update(GameTime* gametime);
    void Draw(GameTime* gameTime, Renderer* renderer);
    void UnloadContent();

   private:
    //These 2 floats will be managed by game for now. Will eventually move to controller or part of the camera    
    float m_aspectRatio = 16.0f / 9.0f;
    float m_zoom = 1.0f;
    OrthographicCamera m_camera;
    
    glm::vec2 playerPosition = glm::vec2(0.0f, 0.0f);
    glm::vec3 baseScreen = glm::vec3(0, 0, 0);
    glm::mat4 ident = glm::mat4(1.0f);
    glm::vec3 trvec = glm::vec3(0, 0, 0);
    glm::mat4 view = glm::translate(ident, trvec);
    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 540.0f, 0.0f, -1.0f, 1.0f);
    Random rnd;
    Shader* m_shader = nullptr;
    Texture* m_texture = nullptr;
    TempSpriteData m_spriteData[25 * 25];
    TextRenderer* m_textRenderer;
};

#endif