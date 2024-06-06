#ifndef GAME_H
#define GAME_H
#include "../pch.h"

class game {
public:
    game() { 
        m_width = 5;
        m_height = 10;
    };
    ~game() { };
public:
    void print();
    void run();
    void shutdown();
private:
    int m_width, m_height;
};

#endif