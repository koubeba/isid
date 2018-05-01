#include "GridMap.h"

Vec2D GridMap::size = Vec2D(48, 27);
Vec2D GridMap::gridSize = Vec2D(40, 40);

void GridMap::setSize(Vec2D _size) {
	GridMap::size = _size;
}

void GridMap::setGridSize(Vec2D _gridSize) {
	GridMap::gridSize = _gridSize;
}

Vec2D GridMap::getGrid(RenderedObject& rO) {
	return rO.getPosition()%gridSize;
}

Vec2D GridMap::moveToGrid(RenderedObject* rO, int x, int y) {
	Vec2D newPosition = Vec2D(x, y);
	rO->setPosition(newPosition);
	return newPosition;
}

Vec2D GridMap::moveToGrid(RenderedObject* rO, Vec2D destination) {
	rO->setPosition(destination);
	return destination;
}

Vec2D GridMap::moveBy(RenderedObject* rO, int deltaX, int deltaY) {
	Vec2D delta = Vec2D(deltaX, deltaY);
	rO->setPosition(rO->getPosition() + delta);
	return rO->getPosition();
}

Vec2D GridMap::moveBy(RenderedObject* rO, Vec2D delta) {
	rO->setPosition(rO->getPosition() + delta);
	return rO->getPosition() + delta;
}
