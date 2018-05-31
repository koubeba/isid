#ifndef GRIDMAP_H
#define GRIDMAP_H

#include "Vec2D.h"

class GridMap {

	// these should probably be consts...
	
	static Vec2D size;
	static Vec2D tileSize;
public:
	static void setSize(Vec2D _size);

	static void setTileSize(Vec2D _tileSize);

	static Vec2D getSize();
	
	static Vec2D toGridCoords(Vec2D toConvert);
	static Vec2D toWindowCoords(Vec2D toConvert);
};

#endif
