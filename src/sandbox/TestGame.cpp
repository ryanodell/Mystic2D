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
    // m_shader = Mystic::Shader::LoadFromFile("shaders/basic_1.glsl");
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_2.glsl");
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

    m_vb.Unbind();
    m_va.Unbind();
    m_ib.Unbind();
}

static int frameCount = 0;

void TestGame::Update(Mystic::GameTime *gametime) {
    Mystic::Game::Update(gametime);
    frameCount++;
}

void TestGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {
    std::cout << "Frame Count: " << frameCount << std::endl;
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
    GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
    GLCall(glUseProgram(m_shader->GetId()));
    m_va.Bind();
    //GLCall(glBindVertexArray(VAO));
    GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, 0));
}

void TestGame::UnloadContent() {
    m_va.Destroy();
    //GLCall(glDeleteVertexArrays(1, &VAO));

    m_vb.Destroy();
    //GLCall(glDeleteBuffers(1, &VBO));

    m_ib.Destroy();
    //GLCall(glDeleteBuffers(1, &EBO));

    GLCall(glDeleteProgram(m_shader->GetId()));
    delete m_shader;
}






// #include "testGame.h"

// #include "../core/Debug.h"
// #include "../core/content/Shader.h"
// #include "../core/content/Texture.h"

// // TestGame::TestGame() : m_vb(nullptr, 0), m_ib(nullptr, 0), m_renderer(nullptr) {}
// TestGame::TestGame() :m_va(false) { }

// void TestGame::LoadContent() {
//     static Renderer renderInstance;
//     m_renderer = &renderInstance;
//     float positions[] = {
//         // positions          // colors           // texture coords
//          0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//          0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//         -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//         -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//     };

//     unsigned int indices[] = {
//         0, 1, 2,
//         2, 3, 0
//     };
//     m_shader = Shader::LoadFromFile("shaders/basic_color_texture.glsl");
//     m_texture = Texture::LoadFromFile("images/kruggsmash.png");
//     /*
//     m_va = VertexArray(true);
//     m_va.Create();
//     m_vb = VertexBuffer(positions, 4 * 4 * sizeof(float));
//     m_vb.Create();
//     m_ib = IndexBuffer(indices, 6);
//     m_ib.Create();
//     // Projection Matrix
//     proj = glm::ortho(0.0f, 960.f, 0.0f, 540.0f, -1.0f, 1.0f);

//     // View matrix
//     ident = glm::mat4(1.0f);
//     trvec = glm::vec3(0, 0, 0);
//     view = glm::translate(ident, trvec);

//     VertexBufferLayout layout;
//     layout.AddFloat(2);
//     layout.AddFloat(4);
//     m_va.AddBuffer(m_vb, layout);
//     // m_shader->Use();
//     // m_shader->setVec4("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);
//     // m_texture->Use();
//     // m_shader->setInt("u_Texture", 0);

//     //!!IMPORTANT!!
//     // Need to make this a member:
//     m_translationA = glm::vec3(200, 200, 0);
//     m_translationB = glm::vec3(400, 200, 0);
//     //!!IMPORTANT!!
//     */
//        GLCall(glGenVertexArrays(1, &VAO));
//     GLCall(glGenBuffers(1, &VBO));
//     GLCall(glGenBuffers(1, &EBO));    
//     GLCall(glBindVertexArray(VAO));

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//     // position attribute
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     // color attribute
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);
//     // texture coord attribute
//     glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//     glEnableVertexAttribArray(2);

//     glBindBuffer(GL_ARRAY_BUFFER, 0); 
//     glBindVertexArray(0); 
//     m_shader->setInt("texture1", m_texture->GetId());
// }

// void TestGame::Update(GameTime *gametime) {
//     Mystic::Game::Update(gametime);
// }

// void TestGame::Draw(GameTime *gameTime, SpriteBatch *spriteBatch) {
//     // GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
//     // m_renderer->Clear();
//     // m_va.Bind();
//     GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
//     GLCall(glClear(GL_COLOR_BUFFER_BIT));
//     GLCall(glActiveTexture(GL_TEXTURE0));
//     GLCall(glBindTexture(GL_TEXTURE_2D, m_texture->GetId()));
//     GLCall(glUseProgram(m_shader->GetId()));
//     glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
//     //GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
//     // GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, nullptr));
//     //GLCall(glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, nullptr));
//     // {
//     //     glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
//     //     glm::mat4 mvp = proj * view * model;
//     //     m_shader->Use();
//     //     m_shader->setMat4("u_MVP", mvp);
//     //     m_renderer->Draw(&m_va, m_ib, *m_shader);
//     // }

//     // {
//     //     glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);
//     //     glm::mat4 mvp = proj * view * model;
//     //     m_shader->Use();
//     //     m_shader->setMat4("u_MVP", mvp);
//     //     m_renderer->Draw(&m_va, m_ib, *m_shader);
//     // }

//     // GLCall(glClear(GL_COLOR_BUFFER_BIT));
//     //  GLCall(glActiveTexture(GL_TEXTURE0));
//     //  GLCall(glBindTexture(GL_TEXTURE_2D, m_texture->GetId()));
//     //  GLCall(glUseProgram(m_shader->GetId()));
//     //  GLCall(glBindVertexArray(VAO));
//     //  GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
// }

// void TestGame::UnloadContent() {
//     // GLCall(glDeleteVertexArrays(1, &VAO));
//     // GLCall(glDeleteBuffers(1, &VBO));
//     // GLCall(glDeleteBuffers(1, &EBO));
//     m_va.Destroy();
//     m_vb.Destroy();
//     m_ib.Destroy();
//     GLCall(glDeleteProgram(m_shader->GetId()));
//     delete m_shader;
// }
