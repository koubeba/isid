#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

enum GameState{INGAME, PAUSE, MENU};

class GameManager {
	
	GameState gameState;	

	public:
	GameManager(); //POMYSLEC: Czy gameManager ma byc singletonem albo klasa statyczna?
	
	GameState getGameState();
	void setGameState(GameState _gameState);
};


#endif
