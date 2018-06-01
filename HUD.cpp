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

void HUD::update(Player player){
	int health = player.getHealth();
	if(health >= 95 ) healthBar->setTextureRect(0, 0, 240, 40);
	else if(health >= 85) healthBar->setTextureRect(0, 40, 240, 40);
	else if(health >= 75) healthBar->setTextureRect(0, 80, 240, 40);
	else if(health >= 65) healthBar->setTextureRect(0, 120, 240, 40);
	else if(health >= 55) healthBar->setTextureRect(0, 160, 240, 40);
	else if(health >= 45) healthBar->setTextureRect(0, 200, 240, 40);
	else if(health >= 35) healthBar->setTextureRect(0, 240, 240, 40);
	else if(health >= 25) healthBar->setTextureRect(0, 280, 240, 40);
	else if(health >= 15) healthBar->setTextureRect(0, 320, 240, 40);
	else if(health >= 5) healthBar->setTextureRect(0, 360, 240, 40);
	else healthBar->setTextureRect(0, 400, 240, 40);

	health = player.getMana(); //I know, I know, I have no dignity. I'm sorry. But also, this saves 4B of memory!
	if(health >= 95 ) manaBar->setTextureRect(0, 0, 240, 40);
	else if(health >= 85) manaBar->setTextureRect(0, 40, 240, 40);
	else if(health >= 75) manaBar->setTextureRect(0, 80, 240, 40);
	else if(health >= 65) manaBar->setTextureRect(0, 120, 240, 40);
	else if(health >= 55) manaBar->setTextureRect(0, 160, 240, 40);
	else if(health >= 45) manaBar->setTextureRect(0, 200, 240, 40);
	else if(health >= 35) manaBar->setTextureRect(0, 240, 240, 40);
	else if(health >= 25) manaBar->setTextureRect(0, 280, 240, 40);
	else if(health >= 15) manaBar->setTextureRect(0, 320, 240, 40);
	else if(health >= 5) manaBar->setTextureRect(0, 360, 240, 40);
	else manaBar->setTextureRect(0, 400, 240, 40);
}