#include <cassert>
#include <cstddef>
#include <glad/glad.h>
#include <input/input.hpp>
#include <iostream>
#include <GLFW/glfw3.h>
#include <renderLoop.hpp>
#include "GridGL.hpp"

ggl::Game::Game(
        int screen_size_x,
        int screen_size_y,
        bool* success
) {
    std::cout << "initializing game" << "\n";
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window_ptr = glfwCreateWindow(1280, 720, "Isometric", NULL, NULL);
    if (window_ptr == NULL) {
        std::cout << "GridGL: Failed to create a GLFW window" << std::endl;
        glfwTerminate();
        *success = false;
        return;
    }

    glfwMakeContextCurrent(window_ptr);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GridGL: Failed to initialize GLAD" << std::endl;
        *success = false;
        return;
    }

    glViewport(0, 0, screen_size_x, screen_size_y);

    *success = true;
}

void ggl::Game::start() {
    RenderLoop(this);
}
void ggl::Game::quit() {
    glfwSetWindowShouldClose(window_ptr, true);
}

ggl::Game::~Game() {
    glfwTerminate();
}
