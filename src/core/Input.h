#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

namespace Mystic {
class InputManager {
   public:
    InputManager(GLFWwindow* window);
    void Update();
    bool IsKeyPressed(int key) const;
    bool IsKeyHeld(int key) const;

   private:
    GLFWwindow* window;
    std::unordered_map<int, bool> m_keyPressed;
    std::unordered_map<int, bool> m_keyHeld;

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
        if (action == GLFW_PRESS) {
            inputManager->m_keyPressed[key] = true;
            inputManager->m_keyHeld[key] = true;
        } else if (action == GLFW_RELEASE) {
            inputManager->m_keyPressed[key] = false;
            inputManager->m_keyHeld[key] = false;
        }
    }
};

}

#endif