# Mystic2D
Yet another attempt to make a 2D game framework/engine using OpenGL, heavily insprited by C#'s Monogame Framework

# Features:
    - Abstracted away OpenGL's API for rendering 2D graphics
    - Manages windowing and user input
    - Structures for managing resources like shaders and textures
    - Functional game loop, rendering loop, loading & unloading assets
    - A sprite batch approach to rendering
    - Program crashes in debug mode when OpenGL encounters an error
    - Uses GLM for vector & matrix math
    - Gametime structure for calculating elapsed time between frames

# Features Being Added:
    - Implement a geniune camera
    - Implement text rendering
    - Implement an ECS of sorts
    - Create an event system
    - Start outfitting "core" as a static library
    - Create REAL precompiled headers - pch is NOT a precompiled header, it was a failed idea...
    - Create a "common" header file
    - Implement lightweight logger

# TODO
    - Create TODO list

# Usage
```c++
// Create a class that inherits from "Game" and override these methods
// This class requires maintaining the renderer shader and texture. no defaults are provided
class MyGame : public Game {
public:
    TestGame();
    void LoadContent();
    void Update(GameTime* gametime);
    void Draw(GameTime* gameTime, Renderer* renderer);
    void UnloadContent();
private:
    Renderer* m_renderer = nullptr;
    Shader* m_shader = nullptr;
    Texture* m_texture = nullptr;
    glm::vec2 m_playerPosition = glm::vec2(0.0f, 0.0f);
}

// In load content, load your shaders, textures, etc. For example:
void MyGame::LoadContent() {
    m_shader = Mystic::Shader::LoadFromFile("shaders/basic_4.glsl");
    m_texture = Mystic::Texture::LoadFromFile("images/kruggsmash.png");
}

// Do your updates within the update gameloop
// For example, handling user input
// NOTE: Shoulda always call the base class' Update method before doing anything else
void MyGame::Update(Mystic::GameTime *gametime) {
    Mystic::Game::Update(gametime);
    if (input.IsKeyPressed(GLFW_KEY_D)) {
        m_playerPosition = glm::vec2(m_playerPosition.x + 1.0f, m_playerPosition.y);
    }
    if (input.IsKeyPressed(GLFW_KEY_A)) {
        m_playerPosition = glm::vec2(m_playerPosition.x - 1.0f, m_playerPosition.y);
    }
    if (input.IsKeyPressed(GLFW_KEY_W)) {
        m_playerPosition = glm::vec2(m_playerPosition.x, m_playerPosition.y - 1.0f);
    }
    if (input.IsKeyPressed(GLFW_KEY_S)) {
        m_playerPosition = glm::vec2(m_playerPosition.x, m_playerPosition.y + 1.0f);
    }
}

// Example of using the renderer's sprite batching functionality
// Use Renderer's BeginBatch, provide shader and any matrix transforms
// Call draw method to provide a position, texture, source rect (optional), and a color
// EndBatch to flush and draw the vertex data withing the renderer
void MyGame::Draw(Mystic::GameTime *gameTime, Renderer* renderer) {
    Rectangle exampleRect = Rectangle(32.0f, 32.0f, 32.0f, 32.0f);
    renderer->BeginBatch(m_shader, mvp);
    renderer->Draw(glm::vec2(32.0f, 64.0f), m_texture, &exampleRect, COLOR_WHITE);
    renderer->EndBatch();
}

// Finally, unload to clear up resources
void MyGame::UnloadContent() {
    delete m_shader;
    delete m_texture;
}


// In the main class, create instance of your class and call "Run()"
int main() {
    std::cout << "Init" << std::endl;
    MyGame mainGame;
    mainGame.Run();
    std::cout << "Shut Down" << std::endl;
    return 0;
}

```

# VSCode Settings for auto-formatting:
C_Cpp.clang_format_fallbackStyle = {BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}