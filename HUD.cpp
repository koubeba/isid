#include "HUD.h"

HUD::HUD(RenderedObject* mB, RenderedObject* hB, RenderedObject* tB) {
	manaBar = mB;
	healthBar = hB;
	toolBar = tB;
}

public void HUD::render(sf::RenderWindow& window) {
	// draw shit
}
