#include <stdlib.h>
#include <iostream>
#include "GameManager.h"
#include "TiledMap.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define WINDOW_L 800
#define WINDOW_H 600

#define SPRITES_PATH "sprites.json"

int main() {

	// construct the renderManager. There should only be one renderManager per window.
	RenderManager renderManager = RenderManager();

	FileManager fileManager = FileManager();
	fileManager.init(SPRITES_PATH);
	// construct the gameManager. There will only be this one instance during the execution of this program
	GameManager gameManager = GameManager(&renderManager, &fileManager);
	gameManager.initPlayer();
	gameManager.initEnemies();
	gameManager.initHUD();
	gameManager.initGraphMap();
	gameManager.loadBiome("grassland.json");

	sf::RenderWindow window(sf::VideoMode(WINDOW_L, WINDOW_H), "GAMEEEE");
	window.setKeyRepeatEnabled(false);

	// game loop: the program runs as long as the window is open
	while (window.isOpen()) {
		sf::Event event;
		// check all the window's events
		while (window.pollEvent(event)) {
			if( (event.type >= 7 && event.type <= 13) || event.type == sf::Event::LostFocus || event.type == sf::Event::GainedFocus ) continue;
			// close the window on close request
			if (event.type == sf::Event::Closed) window.close();
			// receive user input
			gameManager.receiveUserInput(event);
		}

		if(gameManager.getGameState() == QUIT){
			window.close();
			return 0;
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// here we will draw everything
		gameManager.loop(window);
		window.display();

	}
	
	return 0;
}
