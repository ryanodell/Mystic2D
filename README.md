# Mystic2D
Yet another attempt to make a 2D engine using OpenGL - I have a bad case of restart-itus

# Features to implement:
    - Implement a geniune camera
    - Implement text rendering
    - Implement an ECS of sorts
    - Create an event system
    - Start outfitting "core" as a static library
    - Create REAL precompiled headers - pch is NOT a precompiled header, it was a failed idea...
    - Create a "common" header file
    - Implement lightweight logger

# Usage
```c++
// Create a class that inherits from "Game" and override these methods
// This class requires maintaining the renderer shader and texture. no defaults are provided
class MyGame : public Game {
public:
    TestGame();
    void LoadContent();
    void Update(GameTime* gametime);
    void Draw(GameTime* gameTime, SpriteBatch* spriteBatch);
    void UnloadContent();
private:
    Renderer* m_renderer = nullptr;
    Shader* m_shader = nullptr;
    Texture* m_texture = nullptr;
}

// In load content, load your shaders, textures, etc. For example:
void MyGame::LoadContent() {
    m_renderer = new Renderer();
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_4.glsl");
    m_texture = Mystic::Texture::LoadFromFile("images/kruggsmash.png");
    m_renderer->Init();
    m_renderer->SetClearColor(COLOR_BLACK);
}

// Example of using the renderer's sprite batching functionality
// Use Renderer's BeginBatch, provide shader and any matrix transforms
// Call draw method to provide a position, texture, source rect (optional), and a color
// EndBatch to flush and draw the vertex data withing the renderer
void MyGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {
    Rectangle exampleRect = Rectangle(32.0f, 32.0f, 32.0f, 32.0f);
    m_renderer->BeginBatch(m_shader, mvp);
    m_renderer->Draw(glm::vec2(32.0f, 64.0f), m_texture, &exampleRect, COLOR_WHITE);
    m_renderer->EndBatch();
}

// Finally, unload to clear up resources
void MyGame::UnloadContent() {
    delete m_shader;
    delete m_texture;
    delete m_renderer;
}


// In the main class, create instance of your class and call "Run()"
// Eventually, none of the glfw code will need to be called in main. This is temporary
int main() {
    std::cout << "Init" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    MyGame mainGame;
    mainGame.Run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}

```

# VSCode Settings for reference:
C_Cpp.clang_format_fallbackStyle = {BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}