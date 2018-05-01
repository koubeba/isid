#include "RenderedObject.h"

RenderedObject::RenderedObject() {}

RenderedObject::RenderedObject(sf::Sprite*_sprite) {
	sprite = _sprite;
}

void RenderedObject::render(sf::RenderWindow& window) {
	window.draw(*sprite);
}
