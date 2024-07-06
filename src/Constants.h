#ifndef CONSTANTS_H
#define CONSTANTS_H

constexpr unsigned int MAX_OBJECTS = 150;
constexpr unsigned int VERT_SIZE = 8;
constexpr unsigned int IND_SIZE = 6;

constexpr unsigned int MAX_VERTICES = VERT_SIZE * MAX_OBJECTS;
constexpr unsigned int MAX_INDICES = IND_SIZE * MAX_OBJECTS;

enum Color {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_WHITE,
    COLOR_BLACK
};

#endif