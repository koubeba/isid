#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "HUDElement.h"
#include "Player.h"

class HUD {
	HUDElement *manaBar, *healthBar, *toolBar;
	
public:
	HUD(HUDElement* mB, HUDElement* hB, HUDElement* tB);
	void update(Player player);
	void render(sf::RenderWindow& window);
};

#endif
