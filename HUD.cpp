#include "HUD.h"

HUD::HUD(HUDElement* mB, HUDElement* hB, HUDElement* tB) {
	manaBar = mB;
	healthBar = hB;
	toolBar = tB;
}

void HUD::render(sf::RenderWindow& window) {
	manaBar->render(window);
	healthBar->render(window);
	toolBar->render(window);
}
