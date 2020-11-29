//
// Created by Charles on 11/29/2020.
//

#ifndef MINIENGINE_CONTEXT_H
#define MINIENGINE_CONTEXT_H

#include <GLFW/glfw3.h>

class Context {
public:
    static int ScreenWidth();

    static int ScreenHeight();

    static GLFWwindow *GetWindow();

    static void SetWindow(GLFWwindow *window);

private:
    static GLFWwindow *CurWindow;

};


#endif //MINIENGINE_CONTEXT_H
