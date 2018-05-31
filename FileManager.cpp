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


	return NULL;
}

void FileManager::loadBiomeSprites(const char* _biome){
	std::ifstream ifs(_biome);
	Json::Reader reader;
	Json::Value biome;
	reader.parse(ifs, biome);
	const Json::Value& new_sprites = biome["sprites"];

	sf::Texture* tex;
	for (int i=0; i<sprites.size(); i++){
		tex = new sf::Texture();
		tex->loadFromFile(new_sprites[i]["path"].asString());
		sprites.erase(new_sprites[i]["name"].asString());
		sprites.insert(std::pair<std::string, sf::Texture*>(new_sprites[i]["name"].asString(), tex));
	}
}

sf::Sprite* FileManager::getSprite(std::string name) {
	// if (sprites.empty())
	//	throw; // throw a FileManagerException here
	return new sf::Sprite(*(sprites.find(name)->second));
	// if (toReturn == sprites.end())
	//	throw; // throw a FileManagerException here
	//return toReturn;
}
