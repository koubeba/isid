#ifndef __TILEDMAP_H__
#define __TILEDMAP_H__

#include "Tile.h"
#include "Vec2D.h"
#include "FileManager.h"
#include "Item.h"

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include <vector>

class Player;
class Enemy;

int random(int min, int max);

class TiledMap {
    Tile** tiles;
    std::vector<Item*> items;

    //cellular automaton functions
    int countAliveNeighbours(int x, int y);


public:
    void doSimulationStep(int starvationLimit, int overpopulationLimit, int birthThreshold);
    TiledMap();
    TileType getTileType(int x, int y);
    TileType getTileType( Vec2D position);
    Item* getItem(Vec2D position);
    void removeItem(Vec2D position);

    Tile* getTile(int x, int y){ return &tiles[x][y]; }

    void generate(const char* biome, Player* player, std::vector<Enemy*>& enemies);
    void load(FileManager& fileManager);
    void render(sf::RenderWindow& _window);
};


#endif
