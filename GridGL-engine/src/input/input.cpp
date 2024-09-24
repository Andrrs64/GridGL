#include <input/input.hpp>
#include <GLFW/glfw3.h>
#include <functional>

void ggl::InputService::mapMethod(
    unsigned int glfwButton,
    std::function<void()> method
) {
    mappings[glfwButton] = method;
}

void ggl::InputService::processInput(GLFWwindow* window) {
    for (auto& pair : mappings) {
        if (glfwGetKey(window, pair.first) == GLFW_PRESS) {
            pair.second();
        }
    }
}
