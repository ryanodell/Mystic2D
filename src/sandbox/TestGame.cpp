#include "testGame.h"

#include "../core/Debug.h"
#include "../core/content/Shader.h"
#include "../core/content/Texture.h"

TestGame::TestGame() : m_vb(nullptr, 0), m_ib(nullptr, 0), m_renderer(nullptr) { }

void TestGame::LoadContent() {
    static Renderer renderInstance;
    m_renderer = &renderInstance;
    float positions[] = {
        -50.0f, -50.0f, 0.0f, 0.0f,  // 0
        50.0f, -50.0f, 1.0f, 0.0f,   // 1
        50.0f, 50.0f, 1.0f, 1.0f,    // 2
        -50.0f, 50.0f, 0.0f, 1.0f    // 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0};
    m_shader = Shader::LoadFromFile("shaders/basic_color_texture.glsl");
    m_texture = Texture::LoadFromFile("images/kruggsmash.png");
    m_va = VertexArray();
    m_vb = VertexBuffer(positions, 4 * 4 * sizeof(float));
    m_ib = IndexBuffer(indices, 6);

    //Projection Matrix
    glm::mat4 proj = glm::ortho(0.0f, 960.f, 0.0f, 540.0f, -1.0f, 1.0f);
}

void TestGame::Update(GameTime *gametime) {
    Mystic::Game::Update(gametime);
}

void TestGame::Draw(GameTime *gameTime, SpriteBatch *spriteBatch) {
    GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
    m_renderer->Clear();
    //GLCall(glClear(GL_COLOR_BUFFER_BIT));
    GLCall(glActiveTexture(GL_TEXTURE0));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_texture->GetId()));
    GLCall(glUseProgram(m_shader->GetId()));
    GLCall(glBindVertexArray(VAO));
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void TestGame::UnloadContent() {
    GLCall(glDeleteVertexArrays(1, &VAO));
    GLCall(glDeleteBuffers(1, &VBO));
    GLCall(glDeleteBuffers(1, &EBO));
    GLCall(glDeleteProgram(m_shader->GetId()));
    delete m_shader;
}
