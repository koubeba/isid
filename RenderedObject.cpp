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

void RenderedObject::setTextureRect(int x1, int y1, int x2, int y2){
	sprite->setTextureRect( sf::IntRect(x1, y1, x2, y2) );
}

sf::IntRect RenderedObject::getTextureRect(){
	sprite->getTextureRect();
}