#include <GridGL.hpp>
#include <vector>
#include <glm/glm.hpp>

ggl::Enviroment::Enviroment(
    std::vector<Tile> _tileTypes,
    std::unordered_map<int, std::unordered_map<int, int>> _tiles
) {
    tileTypes = _tileTypes;
    tiles = _tiles;

    for (auto& column : tiles) {
        const int x = column.first;
        
        for (auto& pair : column.second) {
            const int z = pair.first;
            Tile type = tileTypes[pair.second];

            vertices.insert(vertices.end(), {
                x + 0.5f,
                type.height,
                z + 0.5f,

                type.textureCoords[0].x,
                type.textureCoords[0].y
            });

            vertices.insert(vertices.end(), {
                x + 0.5f,
                type.height,
                z - 0.5f,

                type.textureCoords[1].x,
                type.textureCoords[1].y
            });

            vertices.insert(vertices.end(), {
                x - 0.5f,
                type.height,
                z - 0.5f,

                type.textureCoords[2].x,
                type.textureCoords[2].y
            });

            vertices.insert(vertices.end(), {
                x - 0.5f,
                type.height,
                z + 0.5f,

                type.textureCoords[2].x,
                type.textureCoords[2].y
            });

            int iOffset = (vertices.size() / 5) - 4;

            indicies.insert(indicies.end(), {
                iOffset,
                iOffset + 1,
                iOffset + 2,

                iOffset,
                iOffset + 3,
                iOffset + 2
            });
        }
    }
}

ggl::Enviroment::~Enviroment() {
    delete[] positionData;
}
