#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/Buffer.h"
#include "../core/content/Shader.h"
#include "../core/content/Texture.h"
//#include "../core/Input.h"
#include "../core/render/Renderer.h"
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
    // glm::vec3 baseScreen = glm::vec3(200, 200, 0);
    glm::vec2 playerPosition = glm::vec2(0.0f, 0.0f);
    glm::vec3 baseScreen = glm::vec3(0, 0, 0);
    glm::mat4 ident = glm::mat4(1.0f);
    glm::vec3 trvec = glm::vec3(0, 0, 0);
    glm::mat4 view = glm::translate(ident, trvec);
    //glm::mat4 proj;
    // glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 540.0f, 0.0f, -1.0f, 1.0f);
    VertexArray m_va;
    VertexBuffer m_vb;
    IndexBuffer m_ib;

    std::random_device rd;  // Seed generator
    std::mt19937 rng;       // Mersenne Twister random number generator
    std::uniform_int_distribution<int> dist;  // Distribution
    int generate() {
        return dist(rng);
    }

    // Renderer* m_renderer = nullptr;
    Shader* m_shader = nullptr;
    Texture* m_texture = nullptr;
    TempSpriteData m_spriteData[25 * 25];
};

#endif