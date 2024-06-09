#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <GLFW/glfw3.h>

namespace mystic{

class gameWindow {
public:
    gameWindow();
    ~gameWindow() {
        if(m_internalWindow) {
            glfwDestroyWindow(m_internalWindow);
        }
    }

private:
    GLFWwindow* m_internalWindow;
};

}

#endif