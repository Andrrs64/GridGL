#include <GridGL.hpp>
#include <iostream>

int main() {
    bool success;
    ggl::Game game(1280, 720, &success);

    if (!success) {
        return -1;
    }

    game.input_service.mapMethod(
        GLFW_KEY_ESCAPE,
        [&game]() {
            game.quit();
        }
    );

    std::cout << "now starting" << "\n";

    game.start();

    return 0;
}
