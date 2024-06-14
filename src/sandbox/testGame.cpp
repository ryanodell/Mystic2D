#include "testGame.h"

void TestGame::loadContent() {

}

void TestGame::update(Mystic::GameTime *gametime) {
    std::cout << "update from testGame.cpp" << std::endl;
    Mystic::Game::update(gametime);
}

void TestGame::draw(Mystic::GameTime *gameTime, Mystic::SpriteBatch *spriteBatch) {

}
