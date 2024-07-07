#ifndef CONSTANTS_H
#define CONSTANTS_H

constexpr unsigned int MAX_OBJECTS = 100;
constexpr unsigned int VERT_QUAD_SIZE = 32;
constexpr unsigned int IND_QUAD_SIZE = 6;

constexpr unsigned int MAX_VERTICES = VERT_QUAD_SIZE * MAX_OBJECTS;
constexpr unsigned int MAX_INDICES = IND_QUAD_SIZE * MAX_OBJECTS;

enum Color {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_WHITE,
    COLOR_BLACK
};

#endif