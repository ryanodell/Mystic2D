#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "../pch.h"
#include <GLFW/glfw3.h>

namespace mystic {
    class gameWindow {
    public:
        gameWindow(const std::string& windowName, int width, int height);
        ~gameWindow() {
            if(m_internalWindow) {
                glfwDestroyWindow(m_internalWindow);
            }
        }

    private:
        GLFWwindow* m_internalWindow;
        std::string m_windowName;
        int m_width, m_height;
    };

}

#endif