#include "FileManager.h"

FileManager::FileManager() {
}

RenderedObject* FileManager::readRenderedObject(const char* filename) {

	std::ifstream ifs(filename);
		
	// add file stream exceptions here..
	Json::Reader reader;
	Json::Value obj;

	reader.parse(ifs, obj);

	// add filemanager exceptions ...
	// check if the object isn't empty, if required members exist etc.

	// read the player sprite:
	
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile(obj["player"].asString());

	sprites.insert(std::pair<std::string, sf::Texture*>("player", tex));
	
	//sprites.add(std::pair<std::string);


	return NULL;
}	

sf::Sprite* FileManager::getSprite(std::string name) {
	// if (sprites.empty())
	//	throw; // throw a FileManagerException here
	return new sf::Sprite(*(sprites.find(name)->second));
	// if (toReturn == sprites.end())
	//	throw; // throw a FileManagerException here
	//return toReturn;
}
