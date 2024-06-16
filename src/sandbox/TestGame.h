#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/spriteBatch.h"
#include "../core/content/Shader.h"
#include "../core/content/Texture.h"

#include <GLFW/glfw3.h>

class TestGame : public Mystic::Game {    
public:
    void LoadContent();
    void Update(Mystic::GameTime* gametime);
    void Draw(Mystic::GameTime* gameTime, Mystic::SpriteBatch* spriteBatch);
    void UnloadContent();
private:
    // float vertices[12] = {
    //      0.5f,  0.5f, 0.0f,  // top right
    //      0.5f, -0.5f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f,  // bottom left
    //     -0.5f,  0.5f, 0.0f   // top left 
    // };
    // unsigned int indices[6] = {  // note that we start from 0!
    //     0, 1, 3,  // first Triangle
    //     1, 2, 3   // second Triangle
    // };
    unsigned int VBO, VAO, EBO;
    Mystic::Shader* m_shader;
    Mystic::Texture* m_texture;
};

#endif