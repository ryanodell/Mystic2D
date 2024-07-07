#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <iostream>
#include "../pch.h"
#include <../../vendor/GLAD/include/glad.h>
#include <GLFW/glfw3.h>
#include "Debug.h"

namespace Mystic {
    class GameWindow {
    public:
        GameWindow(const std::string& windowName, int width, int height);
        ~GameWindow() {
            if(m_internalWindow != NULL) {
                glfwDestroyWindow(m_internalWindow);
            }
            glfwTerminate();
        }
        bool WindowShouldClose();
        void SwapBuffers() { 
            glfwSwapBuffers(m_internalWindow);
            glfwPollEvents();
        }
        GLFWwindow* GetInternalWindow() { return m_internalWindow; }
    private:
        GLFWwindow* m_internalWindow;
        std::string m_windowName;
        int m_width, m_height;
        void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
    };
}

#endif