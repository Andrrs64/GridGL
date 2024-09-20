#ifndef GRIDGL_HPP
#define GRIDGL_HPP

#include "input/input.hpp"
#include <GLFW/glfw3.h>

namespace ggl {

class Game {
public:
    Game(
        int screen_size_x,
        int screen_size_y,
        bool* success,
        std::string* log
    );

    ~Game();

    GLFWwindow* window_ptr;

    InputService input_service;
private:
};

}

#endif // !GRIDGL_HPP
