#include <cassert>
#include <cstddef>
#include <glad/glad.h>
#include <input/input.hpp>
#include <iostream>
#include <GLFW/glfw3.h>
#include "GridGL.hpp"

ggl::Game::Game(
        int screen_size_x,
        int screen_size_y,
        bool* success,
        std::string* log
) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window_ptr = glfwCreateWindow(1280, 720, "Isometric", NULL, NULL);
    if (window_ptr == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window_ptr);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, screen_size_x, screen_size_y);
}

ggl::Game::~Game() {
    glfwTerminate();
}
