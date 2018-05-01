#include "GridMap.h"

Vec2D GridMap::size = Vec2D(48, 27);
Vec2D GridMap::gridSize = Vec2D(40, 40);

void GridMap::setSize(Vec2D _size) {
	GridMap::size = _size;
}

void GridMap::setGridSize(Vec2D _gridSize) {
	GridMap::gridSize = _gridSize;
}

Vec2D GridMap::toGridCoords(Vec2D toConvert) {
	return toConvert/gridSize;
}

Vec2D GridMap::toWindowCoords(Vec2D toConvert) {
	return toConvert*gridSize;
}
