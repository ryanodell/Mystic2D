#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/spriteBatch.h"

class TestGame : public Mystic::Game {    
    void loadContent();
    void update(Mystic::GameTime* gametime);
    void draw(Mystic::GameTime* gameTime, Mystic::SpriteBatch* spriteBatch);
};

#endif