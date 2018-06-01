#include <iostream>
#include <stdlib.h>
#include "GameManager.h"


void GameManager::renderPlayer(sf::RenderWindow& _window) {
	renderManager->render(player, _window);
}


GameManager::GameManager(RenderManager* _renderManager, FileManager* _fileManager) {
	this->gameState = MENU;
	renderManager = _renderManager;
	fileManager = _fileManager;

	userInputInterval = 150;
}

void GameManager::initPlayer() {
	player = Player( fileManager->getSprite("player") );
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
	if (userInputTime.getElapsedTime().asMilliseconds() >= userInputInterval) {
		Vec2D player_position = player.getPosition();

		if (event.key.code == sf::Keyboard::D) {
			player.setDirection(RIGHT);
			if( player_position.x + 1 < GridMap::getSize().x && map.getTileType(player_position.x + 1, player_position.y) == FLOOR )
				player.move(RIGHT);
		}
		else if (event.key.code == sf::Keyboard::A){
			player.setDirection(LEFT);
			if( player_position.x > 0 && map.getTileType(player_position.x - 1, player_position.y) == FLOOR )
				player.move(LEFT);
		}
		else if (event.key.code == sf::Keyboard::W){
			player.setDirection(UP);
			if( player_position.y > 0 && map.getTileType(player_position.x, player_position.y - 1) == FLOOR )
				player.move(UP);
		}
		else if (event.key.code == sf::Keyboard::S){
			player.setDirection(DOWN);
			if(player_position.y + 1 < GridMap::getSize().y && map.getTileType(player_position.x, player_position.y + 1) == FLOOR )
				player.move(DOWN);
		}
		userInputTime.restart();
	}

	if(event.key.code == sf::Keyboard::O){ player.takeDamage(7); }
	if(event.key.code == sf::Keyboard::P){ player.drainMana(7); }
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
	player.update();

	map.render(_window);
	renderPlayer(_window);
	hud->render(_window);	
}
