#include "testGame.h"

void TestGame::loadContent() {

}

void TestGame::update(mystic::gameTime *gametime) {
    std::cout << "update from testGame.cpp" << std::endl;
    mystic::game::update(gametime);
}

void TestGame::draw(mystic::gameTime *gameTime, mystic::spriteBatch *spriteBatch) {

}
