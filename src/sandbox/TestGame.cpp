#include "testGame.h"

void TestGame::LoadContent() {

}

void TestGame::Update(Mystic::GameTime *gametime) {
    std::cout << "update from testGame.cpp" << std::endl;
    Mystic::Game::Update(gametime);
}

void TestGame::Draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {

}
