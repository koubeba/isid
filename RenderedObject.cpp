#include "RenderedObject.h"

void RenderedObject::render(sf::RenderWindow& window) {
	window.draw(*sprite);
}
