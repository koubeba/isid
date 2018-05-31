#include "Tile.h"

Tile::Tile(){
    tileType = FLOOR;
}

void Tile::loadSprite(sf::Sprite* _sprite){
    this->sprite = _sprite;
}

void Tile::setTileType(TileType _tileType){
    tileType = _tileType;
}

TileType Tile::getTileType(){
    return tileType;
}