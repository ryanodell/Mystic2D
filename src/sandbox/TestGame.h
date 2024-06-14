#ifndef TESTGAME_H
#define TESGAME_H
#include "../pch.h"
#include "../core/game.h"
#include "../core/gameWindow.h"
#include "../core/render/spriteBatch.h"

class TestGame : public Mystic::Game {    
    void LoadContent();
    void Update(Mystic::GameTime* gametime);
    void Draw(Mystic::GameTime* gameTime, Mystic::SpriteBatch* spriteBatch);
};

#endif