#ifndef __TILE_H__
#define __TILE_H__

#include "RenderedObject.h" 

enum TileType{FLOOR, OBSTACLE, LIQUID, CHEST};

class Tile : public RenderedObject {
    TileType tileType;
public:
    Tile();
    void loadSprite(sf::Sprite* _sprite);
    void setTileType(TileType _tileType);
    TileType getTileType();
};

#endif