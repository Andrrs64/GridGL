#include <GridGL.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>

ggl::Enviroment::Enviroment(
    std::vector<Tile> _tileTypes,
    std::unordered_map<int, std::unordered_map<int, int>> _tiles
) {
    tileTypes = _tileTypes;
    tiles = _tiles;
    int arrSize = 0;
    std::vector<float> items;

    for (auto& column : tiles) {
        int x = column.first;
        
        for (auto& pair : column.second) {
            int y = pair.first;
            Tile type = tileTypes[pair.second];

            // TODO: Generate triangles from x, y and type
        }
    }

    positionData = new float[arrSize];
    std::copy(items.begin(), items.end(), positionData);
}

ggl::Enviroment::~Enviroment() {
    delete[] positionData;
}
