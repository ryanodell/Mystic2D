#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H

namespace Mystic {
    class SpriteBatch {
    public:
        SpriteBatch() { };
        ~SpriteBatch() { };
        void Begin();
        void End();
    private:
        bool test;
    };
}

#endif