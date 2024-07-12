#include "gameWindow.h"

namespace Mystic {
    GameWindow::GameWindow(const std::string &windowName, int width, int height) {
        m_internalWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
        if(m_internalWindow == NULL) {
            glfwTerminate();
        }
        glfwMakeContextCurrent(m_internalWindow);        
        glfwSetWindowUserPointer(m_internalWindow, this);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to load GLAD. Shut down" << std::endl;
        }
        glfwSetFramebufferSizeCallback(m_internalWindow, [](GLFWwindow* window, int width, int height) {
            GameWindow* gw = static_cast<GameWindow*>(glfwGetWindowUserPointer(window));
            if (gw != NULL) {
                gw->frameBufferSizeCallback(window, width, height);
            }
        });
        //Enable vsync... I think
        glfwSwapInterval(1);
    }
    bool GameWindow::WindowShouldClose() {
        bool shouldClose = glfwWindowShouldClose(m_internalWindow);
        return shouldClose;
    }
    void GameWindow::frameBufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        GLCall(glViewport(0, 0, width, height));
        m_width = width;
        m_height = height;
    }
}