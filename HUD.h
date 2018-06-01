#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "HUDElement.h"

class HUD {
	HUDElement *manaBar, *healthBar, *toolBar;
	
public:
	HUD(HUDElement* mB, HUDElement* hB, HUDElement* tB);
	void render(sf::RenderWindow& window);
};

#endif
