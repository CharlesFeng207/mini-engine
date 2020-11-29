//
// Created by Charles on 11/28/2020.
//

#include <GLFW/glfw3.h>
#include "Context.h"

int Context::ScreenWidth() {
    return 800;
}

int Context::ScreenHeight() {
    return 600;
}

GLFWwindow* Context::CurWindow = nullptr;

GLFWwindow *Context::GetWindow() {
    return CurWindow;
}

void Context::SetWindow(GLFWwindow *window) {
    CurWindow = window;
}


