#ifndef __TILEDMAP_H__
#define __TILEDMAP_H__

#include "Tile.h"
#include "Vec2D.h"
#include "GameManager.h"

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>

class TiledMap {
    Tile** tiles;
public:
    TiledMap();
    void generate(const char* biome);
    void load(GameManager& gameManager);
    void render(sf::RenderWindow& _window);
};


#endif