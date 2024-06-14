#include "gameWindow.h"

namespace mystic {
    gameWindow::gameWindow(const std::string &windowName, int width, int height) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        m_internalWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
        if(m_internalWindow == NULL) {
            //MYSTIC_CRITICAL("Failed to create Glfw window.");
            glfwTerminate();
        }
        glfwMakeContextCurrent(m_internalWindow);        
        glfwSetWindowUserPointer(m_internalWindow, this);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to load GLAD. Shut down" << std::endl;
        }
        glfwSetFramebufferSizeCallback(m_internalWindow, [](GLFWwindow* window, int width, int height) {
            gameWindow* gw = static_cast<gameWindow*>(glfwGetWindowUserPointer(window));
            if (gw != NULL) {
                gw->frameBufferSizeCallback(window, width, height);
            }
        });
        //MYSTIC_INFO("Successfully created Glfw window");
    }
    bool gameWindow::windowShouldClose() {
        bool shouldClose = glfwWindowShouldClose(m_internalWindow);
        return shouldClose;
        //return glfwWindowShouldClose(m_internalWindow);
    }
    void gameWindow::frameBufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
        m_width = width;
        m_height = height;
    }
}