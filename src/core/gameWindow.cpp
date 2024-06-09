#include "gameWindow.h"

namespace mystic {
    gameWindow::gameWindow(const std::string &windowName, int width, int height) {
        glfwInit();
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
}