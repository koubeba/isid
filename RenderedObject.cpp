#include "RenderedObject.h"

RenderedObject::RenderedObject() {}

RenderedObject::RenderedObject(sf::Sprite*_sprite) {
	sprite = _sprite;
}

void RenderedObject::render(sf::RenderWindow& window) {
	Vec2D windowPosition = GridMap::toWindowCoords(position);
	sprite->setPosition(windowPosition.x, windowPosition.y);
	window.draw(*sprite);
}

void RenderedObject::setPosition(Vec2D _position) {
	position = _position;
}

Vec2D RenderedObject::getPosition() {
	return position;
}
