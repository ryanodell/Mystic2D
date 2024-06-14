#include "testGame.h"

void testGame::loadContent() {

}

void testGame::update(mystic::gameTime *gametime) {
    std::cout << "update from testGame.cpp" << std::endl;
    mystic::game::update(gametime);
}

void testGame::draw(mystic::gameTime *gameTime, mystic::spriteBatch *spriteBatch) {

}
