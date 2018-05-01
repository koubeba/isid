#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "RenderedObject.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>


class FileManager {
	
	// all objects in the game will get sprites from this map
	// the sprites will be read from file at the start of the game
	std::map<std::string, sf::Texture*> sprites;
	
	// mozna dodac jakis parametr dotyczacy kodowania. na razie to zignorowalam

public:
	FileManager();
	RenderedObject* readRenderedObject(const char* filename);
	sf::Sprite* getSprite(std::string name);
};

#endif

// todo: exception classs, filemanaerexception or sth
