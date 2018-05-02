#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "RenderedObject.h"
#include "RenderManager.h"
#include "FileManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>

enum GameState{INGAME, PAUSE, MENU};

class GameManager {
	
	GameState gameState;	
	RenderManager* renderManager;
	FileManager* fileManager;

	sf::Clock userInputTime;
	int userInputInterval;

	RenderedObject player;

	// trzeba zrobic tu referencje const
	void renderPlayer(sf::RenderWindow& _window);

	public:
	GameManager(RenderManager* _renderManager, FileManager* _fileManager); //POMYSLEC: Czy gameManager ma byc singletonem albo klasa statyczna?
	
	void initPlayer();

	void receiveUserInput(sf::Event event);

	GameState getGameState();
	void setGameState(GameState _gameState);

	// trzeba tu zrobic referencje const
	void loop(sf::RenderWindow& _window);
};


#endif
