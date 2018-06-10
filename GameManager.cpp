#include <iostream>
#include <stdlib.h>
#include "GameManager.h"



GameManager::GameManager(RenderManager* _renderManager, FileManager* _fileManager) {
	this->gameState = MENU;
	renderManager = _renderManager;
	fileManager = _fileManager;
}

void GameManager::initPlayer() {
	player = Player( fileManager->getSprite("player") );
	player.setPosition( Vec2D(0, 3) );
}

void GameManager::loadBiome(const char* biome){
	fileManager->loadBiomeSprites(biome);
	map.generate(biome);
	map.load(*fileManager);
}

void GameManager::initHUD() {
	HUDElement* mB;
	HUDElement* hB;
	HUDElement* tB;

	hB = new HUDElement( fileManager->getSprite("healthbar") );
	mB = new HUDElement( fileManager->getSprite("manabar") );
	tB = new HUDElement( fileManager->getSprite("toolbar") );

	hB->setTextureRect(0, 0, 240, 40);
	hB->setPosition(0, 0);

	mB->setTextureRect(0, 0, 240, 40);
	mB->setPosition(0, 40);

	tB->setPosition( GridMap::toWindowCoords(GridMap::getSize()).x / 2 - 180, GridMap::toWindowCoords(GridMap::getSize()).y - 90 );
	
	hud = new HUD(mB, hB, tB);
}

void GameManager::receiveUserInput(sf::Event event) {
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O){ player.takeDamage(10); }
	else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P){ player.drainMana(10); }
	else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { gameState = QUIT; }	
}

sf::Sprite* GameManager::getSprite(std::string name){
	return fileManager->getSprite(name);
}

GameState GameManager::getGameState() {
	return this->gameState;

}

void GameManager::setGameState(GameState _gameState) {
	this->gameState = _gameState;
}

void GameManager::loop(sf::RenderWindow& _window) {
	player.update(map);
	hud->update(player);

	map.render(_window);
	player.render(_window);
	hud->render(_window);
}
