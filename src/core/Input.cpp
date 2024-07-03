#include "Input.h"

namespace Mystic {

Input::Input(GLFWwindow* window) : window(window) { }

bool Input::IsKeyPressed(int key) const {
    auto state = glfwGetKey(window, key);
    return state == GLFW_PRESS;
}
}  // namespace Mystic