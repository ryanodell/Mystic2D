#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H

namespace Mystic {
    class SpriteBatch {
    public:
        SpriteBatch() { };
        ~SpriteBatch() { };
        void begin();
        void end();
    private:
        bool test;
    };
}

#endif