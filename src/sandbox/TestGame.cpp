#include "testGame.h"
#include "../core/content/Shader.h"

void TestGame::LoadContent() {
    Mystic::Shader* shader = Mystic::Shader::LoadFromFile("shaders/basic.glsl");

    int test = 5;
}

void TestGame::Update(Mystic::GameTime *gametime) {
    std::cout << "update from testGame.cpp" << std::endl;
    Mystic::Game::Update(gametime);
}

void TestGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {

}
