#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Windows.h>
#include "Context.h"
#include <vector>
#include "IModule.h"
#include "module/GUIDemo.h"
#include "module/GLDrawQuad.h"

using namespace std;


vector<IModule *> *modules = nullptr;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
//    glViewport(0, 0, width, height);
//    ImGui::SetNextWindowPos(ImVec2(0, 0));
//    ImGui::SetNextWindowSize(ImVec2(width, height));
    Context::ScreenWidth = width;
    Context::ScreenHeight = height;
    for (auto &module : *modules)
        module->OnWindowResize();
}


GLFWwindow *initWindows() {
    // In the main function we first initialize GLFW with glfwInit,
    // after which we can configure GLFW using glfwWindowHint.
    if (!glfwInit()) {
        std::cout << "Failed to init GLFW " << std::endl;
        return NULL;
    }

    // The first argument of glfwWindowHint tells us what option we want to configure
    //  The second argument is an integer that sets the value of our option.

    // We set the major and minor version both to 3. We also tell GLFW we want to explicitly use the core-profile.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Note that on Mac OS X you need to add glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); to your initialization code for it to work
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(Context::ScreenWidth, Context::ScreenHeight, "Mini-Engine", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    // initialize GLAD before we call any OpenGL function:
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }


    // the moment a user resizes the window the viewport should be adjusted as well.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

void CreateModules() {
    modules = new vector<IModule *>();
    modules->push_back(new GLDrawQuad());
    modules->push_back(new GUIDemo());
}

int main() {
//    FreeConsole();

    CreateModules();

    auto window = initWindows();

    if (window == NULL)
        return -1;

    Context::CurWindow = window;

    for (auto &module : *modules)
        module->Init();

    while (!glfwWindowShouldClose(window)) {

        for (auto &module : *modules)
            module->Update();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (auto &module : *modules)
            module->Draw();

        glfwSwapBuffers(window);

        // Checks if any events are triggered (like keyboard input or mouse movement events)
        glfwPollEvents();
    }

    for (auto &module : *modules)
        module->Destroy();

    glfwDestroyWindow(window);

    // As soon as we exit the render loop we would like to properly clean/delete all resources that were allocated.
    glfwTerminate();

    return 0;
}