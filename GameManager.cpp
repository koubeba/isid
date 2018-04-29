#include <iostream>
#include <stdlib.h>
#include "GameManager.h"

GameManager::GameManager(RenderManager* _renderManager) {
	this->gameState = MENU;
	renderManager = _renderManager;
}

GameState GameManager::getGameState() {
	return this->gameState;

}

void GameManager::setGameState(GameState _gameState) {
	this->gameState = _gameState;
}

void GameManager::loop() {
	// here everything will be drawn
}
