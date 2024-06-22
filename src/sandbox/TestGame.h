#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/Buffer.h"
#include "../core/render/spriteBatch.h"
#include "../core/content/Shader.h"
#include "../core/content/Texture.h"
#include "../core/render/Renderer.h"
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include <optional>
#include <GLFW/glfw3.h>
using namespace Mystic;

class TestGame : public Game {
   public:
    TestGame();
    void LoadContent();
    void Update(GameTime* gametime);
    void Draw(GameTime* gameTime, SpriteBatch* spriteBatch);
    void UnloadContent();

   private:
    glm::vec3 m_translationA, m_translationB;
    glm::mat4 ident;
    glm::vec3 trvec;
    glm::mat4 view ;
    glm::mat4 proj;
    
    unsigned int VBO, VAO, EBO;
    
    // VertexArray m_va;
    // VertexBuffer m_vb;
    // IndexBuffer m_ib;

    Renderer* m_renderer = nullptr;
    Shader* m_shader = nullptr;
    Texture* m_texture = nullptr;
};

#endif