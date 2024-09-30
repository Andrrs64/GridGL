#ifndef GRIDGL_HPP
#define GRIDGL_HPP

#include "input/input.hpp"
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <vector>
#include <glm/glm.hpp>
#include <string>

namespace ggl {

struct Tile {
    glm::vec2 textureCoords[4];
    float height;
};

struct Enviroment {
    Enviroment(
        std::vector<Tile> _tileTypes,
        std::unordered_map<int, std::unordered_map<int, int>> _tiles
    );
    ~Enviroment();

    float* positionData;

    std::vector<Tile> tileTypes;
    std::unordered_map<int, std::unordered_map<int, int>> tiles;

    std::vector<float> vertices;
    std::vector<int> indicies;
};

struct Game {
    Game(
        int screen_size_x,
        int screen_size_y,
        bool* success
    );

    ~Game();

    void start();
    void quit();

    void loadData(std::string filePath);

    GLFWwindow* window_ptr;

    InputService input_service;

    std::string currentEnviroment;

    std::unordered_map<std::string, unsigned int> textures;
    std::unordered_map<std::string, Enviroment> enviroments;
};

}

#endif // !GRIDGL_HPP
