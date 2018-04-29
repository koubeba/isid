#include "RenderManager.h"

void RenderManager::render(std::vector<RenderedObject*>& objects, sf::RenderWindow window) {
	for (std::vector<RenderedObject*>::iterator rO = objects.begin(); rO != objects.end() ; rO++) {
		(*rO)->render(window);
	}
}
