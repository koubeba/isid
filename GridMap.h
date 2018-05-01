#ifndef GRIDMAP_H
#define GRIDMAP_H


#include "RenderedObject.h"
#include "Vec2D.h"

class GridMap {

	// these should probably be consts...
	
	static Vec2D size;
	static Vec2D gridSize;
public:
	static void setSize(Vec2D _size);

	static void setGridSize(Vec2D _gridSize);

	// returns the grid index: 1, 1 etc...
	// przejrzyste komentarze to nie jest moja mocna strona
	static Vec2D getGrid(RenderedObject& rO);

	// return the rendered object's new position
	static Vec2D moveToGrid(RenderedObject* rO, int x, int y);
	static Vec2D moveToGrid(RenderedObject* rO, Vec2D destination);
	
	static Vec2D moveBy(RenderedObject* rO, int deltaX, int deltaY);
	static Vec2D moveBy(RenderedObject* rO, Vec2D delta);
};

#endif
