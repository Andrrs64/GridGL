#include "renderLoop.hpp"
#include <GridGL.hpp>
#include <input/input.hpp>
#include <GLFW/glfw3.h>

void RenderLoop(ggl::Game* game) {
    GLFWwindow* window = game->window_ptr;
    ggl::InputService inputService = game->input_service;

    while(!glfwWindowShouldClose(window)) {
        inputService.processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. world space function
        // 2. Run shaders
        // 3. screen space function

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
