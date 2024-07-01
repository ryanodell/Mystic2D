#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>

namespace Mystic {
class InputManager {
   public:
    InputManager(GLFWwindow* window) : window(window) {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, keyCallback);
    }

    void Update() {
        // Reset keyPressed states each frame
        for (auto& [key, pressed] : m_keyPressed) {
            if (pressed) {
                pressed = false;  // Reset after handling
            }
        }
    }

    bool IsKeyPressed(int key) const {
        auto it = m_keyPressed.find(key);
        if (it != m_keyPressed.end()) {
            return it->second;
        }
        return false;
    }

    bool IsKeyHeld(int key) const {
        auto it = m_keyHeld.find(key);
        if (it != m_keyHeld.end()) {
            return it->second;
        }
        return false;
    }

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

}  // namespace Mystic

#endif