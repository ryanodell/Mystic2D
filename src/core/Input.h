#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

namespace Mystic {
class Input {
   public:
    Input() { }
    Input(GLFWwindow* window);
    bool IsKeyPressed(int key) const;

   private:
    GLFWwindow* window;
};

}

#endif