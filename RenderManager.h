#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "RenderedObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

class RenderManager {
public:
	void render(std::vector<RenderedObject*>& objects, sf::RenderWindow window);
};

#endif
