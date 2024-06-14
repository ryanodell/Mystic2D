#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <iostream>
#include "../pch.h"
#include <../../vendor/GLAD/include/glad.h>
#include <GLFW/glfw3.h>

namespace mystic {
    class gameWindow {
    public:
        gameWindow(const std::string& windowName, int width, int height);
        ~gameWindow() {
            if(m_internalWindow != NULL) {
                glfwDestroyWindow(m_internalWindow);
            }
            glfwTerminate();
        }
        bool windowShouldClose();
        void render() { 
            glfwSwapBuffers(m_internalWindow);
            glfwPollEvents();
        }
    private:
        GLFWwindow* m_internalWindow;
        std::string m_windowName;
        int m_width, m_height;
        void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
    };
}

#endif