#include "Input.h"

namespace Mystic {

InputManager::InputManager(GLFWwindow* window) : window(window) { }

bool InputManager::IsKeyPressed(int key) const {
    auto state = glfwGetKey(window, key);
    return state == GLFW_PRESS;
}
}  // namespace Mystic