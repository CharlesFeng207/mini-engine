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


void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
//    ImGui::SetNextWindowPos(ImVec2(0, 0));
//    ImGui::SetNextWindowSize(ImVec2(width, height));
    std::cout << "test" << std::endl;
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

    GLFWwindow *window = glfwCreateWindow(Context::ScreenWidth(), Context::ScreenHeight(), "Mini-Engine", NULL, NULL);
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

    glViewport(0, 0, 800, 600);

    // the moment a user resizes the window the viewport should be adjusted as well.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}


vector<IModule *> CreateModules() {
    auto v = vector<IModule *>();
    v.push_back(new GLDrawQuad());
    v.push_back(new GUIDemo());
    return v;
}

int main() {
//    FreeConsole();

    auto modules = CreateModules();

    auto window = initWindows();

    if (window == NULL)
        return -1;

    Context::SetWindow(window);

    for (auto &module : modules)
        module->Init();

    while (!glfwWindowShouldClose(window)) {

        for (auto &module : modules)
            module->Update();

        for (auto &module : modules)
            module->Draw();

        // glBindVertexArray(0); // no need to unbind it every time

        // Double buffer
        // The front buffer contains the final output image that is shown at the screen,
        // while all the rendering commands draw to the back buffer.
        // As soon as all the rendering commands are finished we swap the back buffer to the front buffer,
        // so the image is instantly displayed to the user
        glfwSwapBuffers(window);

        //The glfwPollEvents function checks if any events are triggered (like keyboard input or mouse movement events),
        //updates the window state, and calls the corresponding functions (which we can set via callback methods).
        glfwPollEvents();
    }

    for (auto &module : modules)
        module->Destroy();

    glfwDestroyWindow(window);

    // As soon as we exit the render loop we would like to properly clean/delete all resources that were allocated.
    glfwTerminate();

    return 0;
}