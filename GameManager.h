#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "RenderManager.h"

enum GameState{INGAME, PAUSE, MENU};

class GameManager {
	
	GameState gameState;	
	RenderManager* renderManager;

	public:
	GameManager(RenderManager* _renderManager); //POMYSLEC: Czy gameManager ma byc singletonem albo klasa statyczna?
	
	GameState getGameState();
	void setGameState(GameState _gameState);
	void loop();
};


#endif
