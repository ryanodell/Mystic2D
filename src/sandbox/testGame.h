#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/spriteBatch.h"

class TestGame : public mystic::game {    
    void loadContent();
    void update(mystic::gameTime* gametime);
    void draw(mystic::gameTime* gameTime, mystic::spriteBatch* spriteBatch);
};

#endif