#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H

namespace mystic {
    class spriteBatch {
    public:
        spriteBatch();
        ~spriteBatch();
        void begin();
        void end();
    private:
        bool test;
    };
}

#endif