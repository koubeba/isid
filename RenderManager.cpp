#include "RenderManager.h"


// trzeba potem zrobic zeby te referencje byly const ;)
void RenderManager::render(RenderedObject& renderedObject, sf::RenderWindow& window) {
	renderedObject.render(window);
}


void RenderManager::render(std::vector<RenderedObject*>& objects, sf::RenderWindow& window) {
	for (std::vector<RenderedObject*>::iterator rO = objects.begin(); rO != objects.end() ; rO++) {
		(*rO)->render(window);
	}
}
