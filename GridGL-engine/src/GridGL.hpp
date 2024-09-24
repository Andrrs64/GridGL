#ifndef GRIDGL_HPP
#define GRIDGL_HPP

#include "input/input.hpp"
#include <GLFW/glfw3.h>

namespace ggl {

struct Game {
    Game(
        int screen_size_x,
        int screen_size_y,
        bool* success
    );

    ~Game();

    void start();
    void quit();

    GLFWwindow* window_ptr;

    InputService input_service;
};

}

#endif // !GRIDGL_HPP
