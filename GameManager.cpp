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
}

void GameManager::initPlayer() {
	player = RenderedObject(fileManager->getSprite("player"));
}

void GameManager::receiveUserInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.setPosition(player.getPosition() + Vec2D(1, 0));
	}
}

GameState GameManager::getGameState() {
	return this->gameState;

}

void GameManager::setGameState(GameState _gameState) {
	this->gameState = _gameState;
}

void GameManager::loop(sf::RenderWindow& _window) {
	receiveUserInput();
	renderPlayer(_window);
	
	std::cerr << player.RenderedObject::getPosition() << std::endl;
	
	// here everything will be adrawn
}
