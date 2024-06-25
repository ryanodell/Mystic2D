#include "testGame.h"
#include "../core/content/Shader.h"

TestGame::TestGame() { }

void TestGame::LoadContent() {
    float vertices[] = {
                        /*       Color       */
         //Position     //R   //G   //B   //A
         0.5f,  0.5f,   1.0f, 0.0f, 0.0f, 1.0f, // top right
         0.5f, -0.5f,   1.0f, 0.0f, 0.0f, 1.0f, // bottom right
        -0.5f, -0.5f,   1.0f, 0.0f, 0.0f, 1.0f, // bottom left
        -0.5f,  0.5f,   1.0f, 0.0f, 0.0f, 1.0f  // top left 
    };
    unsigned int indices[6] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_3.glsl");
    m_va = VertexArray::Create();
    m_vb = VertexBuffer::Create(vertices, sizeof(vertices), GL_DYNAMIC_DRAW);
    m_ib = IndexBuffer::Create(indices, 6);
    m_va.Bind();
    m_vb.Bind();
    m_ib.Bind();
    m_ib.ApplyData();

    VertexBufferLayout vbLayout;
    vbLayout.AddFloat(2);
    vbLayout.AddFloat(4);
    m_va.ApplyBufferLayout(vbLayout);

    m_va.Unbind();
    m_vb.Unbind();
    m_ib.Unbind();
}

static int frameCount = 0;

void TestGame::Update(Mystic::GameTime *gametime) {
    Mystic::Game::Update(gametime);
    if(frameCount == 500) {
        float vertices[] = {
                            /*       Color       */
             //Position     //R   //G   //B   //A
             0.5f,  0.5f,   1.0f, 1.0f, 0.0f, 1.0f, // top right
             0.5f, -0.5f,   1.0f, 1.0f, 0.0f, 1.0f, // bottom right
            -0.5f, -0.5f,   1.0f, 1.0f, 0.0f, 1.0f, // bottom left
            -0.5f,  0.5f,   1.0f, 1.0f, 0.0f, 1.0f  // top left 
        };
        m_vb.UpdateVertexData(vertices, sizeof(vertices));
    }
    if(frameCount == 1000) {
        float vertices[] = {
                            /*       Color       */
             //Position     //R   //G   //B   //A
             0.5f,  0.5f,   1.0f, 0.0f, 1.0f, 1.0f, // top right
             0.5f, -0.5f,   1.0f, 0.0f, 1.0f, 1.0f, // bottom right
            -0.5f, -0.5f,   1.0f, 0.0f, 1.0f, 1.0f, // bottom left
            -0.5f,  0.5f,   1.0f, 0.0f, 1.0f, 1.0f  // top left 
        };
        m_vb.UpdateVertexData(vertices, sizeof(vertices));
    }
    frameCount++;
}

void TestGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {
    std::cout << "Frame Count: " << frameCount << std::endl;
    GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
    glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
    transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    GLCall(glUseProgram(m_shader->GetId()));
    unsigned int transformLoc = glGetUniformLocation(m_shader->GetId(), "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

    m_va.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, 0));
}

void TestGame::UnloadContent() {
    m_va.Destroy();
    m_vb.Destroy();
    m_ib.Destroy();
    GLCall(glDeleteProgram(m_shader->GetId()));
    delete m_shader;
}