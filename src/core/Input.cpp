#include "Input.h"

namespace Mystic {

InputManager::InputManager(GLFWwindow* window) : window(window) {
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, keyCallback);
}

void InputManager::Update() {
    for (auto& [key, pressed] : m_keyPressed) {
        if (pressed) {
            pressed = false;
        }
    }
}

bool InputManager::IsKeyPressed(int key) const {
    auto it = m_keyPressed.find(key);
    if (it != m_keyPressed.end()) {
        return it->second;
    }
    return false;
}

bool InputManager::IsKeyHeld(int key) const {
        auto it = m_keyHeld.find(key);
        if (it != m_keyHeld.end()) {
            return it->second;
        }
        return false;
    }
}