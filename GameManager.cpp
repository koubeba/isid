#include <iostream>
#include <stdlib.h>
#include "GameManager.h"



GameManager::GameManager(RenderManager* _renderManager, FileManager* _fileManager) {
	this->gameState = MENU;
	renderManager = _renderManager;
	fileManager = _fileManager;

	userInputInterval = 50;
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
	if (userInputTime.getElapsedTime().asMilliseconds() >= userInputInterval) {
		Vec2D player_position = player.getPosition();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
			player.setDirection(RIGHT);
			if( player_position.x + 1 < GridMap::getSize().x && map.getTileType(player_position.x + 1, player_position.y) == FLOOR )
				player.move(RIGHT);
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
			player.setDirection(LEFT);
			if( player_position.x > 0 && map.getTileType(player_position.x - 1, player_position.y) == FLOOR )
				player.move(LEFT);
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
			player.setDirection(UP);
			if( player_position.y > 0 && map.getTileType(player_position.x, player_position.y - 1) == FLOOR )
				player.move(UP);
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
			player.setDirection(DOWN);
			if(player_position.y + 1 < GridMap::getSize().y && map.getTileType(player_position.x, player_position.y + 1) == FLOOR )
				player.move(DOWN);
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O){ player.takeDamage(10); }
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P){ player.drainMana(10); }
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { gameState = QUIT; }
		userInputTime.restart();
	}
	
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
	hud->update(player);

	map.render(_window);
	player.render(_window);
	hud->render(_window);
}
