#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

namespace Mystic {
class InputManager {
   public:
    InputManager() { }
    InputManager(GLFWwindow* window);
    bool IsKeyPressed(int key) const;

   private:
    GLFWwindow* window;
};

}

#endif