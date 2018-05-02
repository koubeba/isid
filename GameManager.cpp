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

void GameManager::receiveUserInput(sf::Event event) {
	if (userInputTime.getElapsedTime().asMilliseconds() >= userInputInterval) {
		
		if (event.key.code == sf::Keyboard::D) 
			player.setPosition(player.getPosition() + Vec2D(1, 0));
		else if (event.key.code == sf::Keyboard::A)
			player.setPosition(player.getPosition() + Vec2D(-1, 0));
		else if (event.key.code == sf::Keyboard::W)
			player.setPosition(player.getPosition() + Vec2D(0, -1));
		else if (event.key.code == sf::Keyboard::S)
			player.setPosition(player.getPosition() + Vec2D(0, 1));
		userInputTime.restart();
	}
}

GameState GameManager::getGameState() {
	return this->gameState;

}

void GameManager::setGameState(GameState _gameState) {
	this->gameState = _gameState;
}

void GameManager::loop(sf::RenderWindow& _window) {
	renderPlayer(_window);
	
}
