#include "GridMap.h"

Vec2D GridMap::size = Vec2D(48, 27);
Vec2D GridMap::tileSize = Vec2D(40, 40);

void GridMap::setSize(Vec2D _size) {
	GridMap::size = _size;
}

Vec2D GridMap::getSize(){
	return GridMap::size;
}

void GridMap::setTileSize(Vec2D _tileSize) {
	GridMap::tileSize = _tileSize;
}

Vec2D GridMap::toGridCoords(Vec2D toConvert) {
	return toConvert/tileSize;
}

Vec2D GridMap::toWindowCoords(Vec2D toConvert) {
	return toConvert*tileSize;
}
