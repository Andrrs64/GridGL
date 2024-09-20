#include <input/input.hpp>
#include <GLFW/glfw3.h>
#include <functional>

void InputService::mapMethod(unsigned int glfwButton, std::function<void()> method) {
    mappings[glfwButton] = method;
}

void InputService::processInput(GLFWwindow* window) {
    for (auto& pair : mappings) {
        if (glfwGetKey(window, pair.first) == GLFW_PRESS) {
            pair.second();
        }
    }
}
