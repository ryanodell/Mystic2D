#include "testGame.h"

#include "../core/Debug.h"
#include "../core/content/Shader.h"
#include "../core/content/Texture.h"

// TestGame::TestGame() : m_vb(nullptr, 0), m_ib(nullptr, 0), m_renderer(nullptr) {}
TestGame::TestGame() :m_va(false) { }

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
    m_shader = Shader::LoadFromFile("shaders/basic_color_position.glsl");
    m_texture = Texture::LoadFromFile("images/kruggsmash.png");
    m_va = VertexArray(true);
    m_vb = VertexBuffer(positions, 4 * 4 * sizeof(float));
    m_ib = IndexBuffer(indices, 6);
    m_ib.Create();
    // Projection Matrix
    proj = glm::ortho(0.0f, 960.f, 0.0f, 540.0f, -1.0f, 1.0f);

    // View matrix
    ident = glm::mat4(1.0f);
    trvec = glm::vec3(0, 0, 0);
    view = glm::translate(ident, trvec);

    VertexBufferLayout layout;
    layout.AddFloat(2);
    layout.AddFloat(4);
    m_va.AddBuffer(m_vb, layout);
    m_shader->Use();
    m_shader->setVec4("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);
    m_texture->Use();
    m_shader->setInt("u_Texture", 0);

    //!!IMPORTANT!!
    // Need to make this a member:
    m_translationA = glm::vec3(200, 200, 0);
    m_translationB = glm::vec3(400, 200, 0);
    //!!IMPORTANT!!
}

void TestGame::Update(GameTime *gametime) {
    Mystic::Game::Update(gametime);
}

void TestGame::Draw(GameTime *gameTime, SpriteBatch *spriteBatch) {
    GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
    m_renderer->Clear();
    {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
        glm::mat4 mvp = proj * view * model;
        m_shader->Use();
        m_shader->setMat4("u_MVP", mvp);
        m_renderer->Draw(&m_va, m_ib, *m_shader);
    }

    {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);
        glm::mat4 mvp = proj * view * model;
        m_shader->Use();
        m_shader->setMat4("u_MVP", mvp);
        m_renderer->Draw(&m_va, m_ib, *m_shader);
    }

    // GLCall(glClear(GL_COLOR_BUFFER_BIT));
    //  GLCall(glActiveTexture(GL_TEXTURE0));
    //  GLCall(glBindTexture(GL_TEXTURE_2D, m_texture->GetId()));
    //  GLCall(glUseProgram(m_shader->GetId()));
    //  GLCall(glBindVertexArray(VAO));
    //  GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void TestGame::UnloadContent() {
    GLCall(glDeleteVertexArrays(1, &VAO));
    GLCall(glDeleteBuffers(1, &VBO));
    GLCall(glDeleteBuffers(1, &EBO));
    GLCall(glDeleteProgram(m_shader->GetId()));
    delete m_shader;
}
