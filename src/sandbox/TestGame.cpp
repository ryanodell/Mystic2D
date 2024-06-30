#include "testGame.h"

#include "../core/content/Shader.h"

TestGame::TestGame() { }

void TestGame::LoadContent() {
    m_renderer = new Renderer();
    float vertices[] = {
        /*       Color       */
        // Position     //R   //G   //B   //A       //TexCoords
         50.f, 50.0f,    1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 1.0f,   // top right
         50.0f, -50.f,   1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 0.0f,   // bottom right
        -50.0f, -50.0f,  1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 0.0f,   // bottom left
        -50.0f, 50.0f,   1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 1.0f    // top left
    };
    unsigned int indices[6] = {
        // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_4.glsl");
    m_texture = Mystic::Texture::LoadFromFile("images/kruggsmash.png");
    m_renderer->Init();
    // m_va = VertexArray::Create();
    // m_vb = VertexBuffer::Create(vertices, sizeof(vertices), GL_STATIC_DRAW);
    // m_ib = IndexBuffer::Create(indices, 6);
    // m_va.Bind();
    // m_vb.Bind();
    // m_ib.Bind();
    // m_ib.ApplyData();

    // VertexBufferLayout vbLayout;
    // vbLayout.AddFloat(2);
    // vbLayout.AddFloat(4);
    // vbLayout.AddFloat(2);
    // m_va.ApplyBufferLayout(vbLayout);

    // m_va.Unbind();
    // m_vb.Unbind();
    // m_ib.Unbind();
    // end of m_renderer->Init();
    m_renderer->SetClearColor(COLOR_BLACK);
}

static int frameCount = 0;

void TestGame::Update(Mystic::GameTime *gametime) {
    Mystic::Game::Update(gametime);
    std::cout << "Frame Count: " << frameCount << std::endl;
    translationA.x += 0.1f;
    translationB.y += 0.1f;
    frameCount++;
}

void TestGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {
    m_texture->Use();
    m_renderer->Clear();
    // glm::mat4 model = glm::translate(glm::mat4(1.0f), baseScreen);
     glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200.0f, 200.0f, 0.0f));
    glm::mat4 mvp = proj * view * model;
    m_renderer->BeginBatch(mvp);
    Rectangle srcRect = Rectangle(0.0f, 0.0f, 32.0f, 32.0f);
    m_renderer->Draw(glm::vec2(0.0f, 0.0f), m_texture, m_shader, nullptr, COLOR_WHITE);
    m_renderer->EndBatch(m_shader);
    
    // {
    //     glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
    //     glm::mat4 mvp = proj * view * model;
    //     m_shader->Use();
    //     m_shader->setMat4("transform", mvp);
    //     m_va.Bind();
    //     GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, 0));
    // }
    // {
    //     glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
    //     glm::mat4 mvp = proj * view * model;
    //     m_shader->Use();
    //     m_shader->setMat4("transform", mvp);
    //     m_va.Bind();
    //     GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, 0));
    // }
}

void TestGame::UnloadContent() {
    m_va.Destroy();
    m_vb.Destroy();
    m_ib.Destroy();
    delete m_shader;
    delete m_texture;
    delete m_renderer;
}