#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "HUDElement.h"
#include "RenderManager.h"
#include "FileManager.h"
#include "HUD.h"
#include "TiledMap.h"
#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>

enum GameState{INGAME, PAUSE, MENU, QUIT};

class GameManager {
	
	GameState gameState;	
	RenderManager* renderManager;
	FileManager* fileManager;

	sf::Clock userInputTime;
	int userInputInterval;

	TiledMap map;
	Player player;
	HUD* hud;

	public:
	GameManager(RenderManager* _renderManager, FileManager* _fileManager); //POMYSLEC: Czy gameManager ma byc singletonem albo klasa statyczna?
	
	// funkcje inicjalizujace 
	void initPlayer();
	void initHUD();
	void loadBiome(const char* biome);	

	void receiveUserInput(sf::Event event);

	sf::Sprite* getSprite(std::string name);

	GameState getGameState();
	void setGameState(GameState _gameState);

	// trzeba tu zrobic referencje const
	void loop(sf::RenderWindow& _window);
};


#endif
