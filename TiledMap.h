#ifndef __TILEDMAP_H__
#define __TILEDMAP_H__

#include "Tile.h"
#include "Vec2D.h"
#include "FileManager.h"
#include "Item.h"

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>

class TiledMap {
    Tile** tiles;
    std::vector<Item*> items;
public:
    TiledMap();
    TileType getTileType(int x, int y);
    void generate(const char* biome);
    void load(FileManager& fileManager);
    void render(sf::RenderWindow& _window);
};


#endif