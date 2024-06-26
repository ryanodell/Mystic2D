#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace Mystic {

struct Rectangle {
    Rectangle() { }
    Rectangle(float x, float y, float w, float h) 
        : X(x), Y(y), W(w), H(h) { }
    ~Rectangle() { }
    float X, Y, W, H;
};

}  // namespace Mystic

#endif