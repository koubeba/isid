#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "RenderedObject.h"

class HUD {
	RenderedObject* manaBar, healthBar, toolBar;
	
	HUD(RenderedObject* mB, RenderedObject* hB, RenderedObject* tB);
	public void render(sf::RenderWindow& window);
}

#endif
