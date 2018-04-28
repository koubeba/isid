#include <iostream>
#include <stdlib.h>
#include "GameManager.h"

GameManager::GameManager() {
	this->gameState = MENU;
}

GameState GameManager::getGameState() {
	return this->gameState;

}

void GameManager::setGameState(GameState _gameState) {
	this->gameState = _gameState;
}
