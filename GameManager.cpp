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
	player = RenderedObject(fileManager->getSprite("player"));
}

void GameManager::loadBiome(const char* biome){
	fileManager->loadBiomeSprites(biome);
	map.generate(biome);
	map.load(*fileManager);
}

void GameManager::initHUD() {
	RenderedObject* mB;
	RenderedObject* hB;
	RenderedObject* tB;
	mB = new RenderedObject(fileManager->getSprite("manabar"));
	hB = new RenderedObject(fileManager->getSprite("healthbar"));
	tB = new RenderedObject(fileManager->getSprite("toolbar"));
	hud = new HUD(mB, hB, tB);
}

void GameManager::receiveUserInput(sf::Event event) {
	if (userInputTime.getElapsedTime().asMilliseconds() >= userInputInterval) {
		Vec2D player_position = player.getPosition();

		if (event.key.code == sf::Keyboard::D) {
			if( player_position.x + 1 < GridMap::getSize().x && map.getTileType(player_position.x + 1, player_position.y) == FLOOR )
				player.setPosition(player_position + Vec2D(1, 0));
		}
		else if (event.key.code == sf::Keyboard::A){
			if( player_position.x > 0 && map.getTileType(player_position.x - 1, player_position.y) == FLOOR )
				player.setPosition(player_position + Vec2D(-1, 0));
		}
		else if (event.key.code == sf::Keyboard::W){
			if( player_position.y > 0 && map.getTileType(player_position.x, player_position.y - 1) == FLOOR )
				player.setPosition(player_position + Vec2D(0, -1));
		}
		else if (event.key.code == sf::Keyboard::S){
			if(player_position.y + 1 < GridMap::getSize().y && map.getTileType(player_position.x, player_position.y + 1) == FLOOR )
				player.setPosition(player_position + Vec2D(0, 1));
		}
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
	map.render(_window);
	renderPlayer(_window);
	
}
