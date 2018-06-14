#include "FileManager.h"

FileManager::FileManager() {
}

void FileManager::init(const char* filename){
	std::ifstream ifs(filename);

	// add file stream exceptions here..
	Json::Reader reader;
	Json::Value obj;

	reader.parse(ifs, obj);

	// add filemanager exceptions ...
	// check if the object isn't empty, if required members exist etc.

	Json::Value sprites;

	sprites = obj["player"];
	this->readSpritesFromJson(sprites);

	sprites = obj["HUD"];
	this->readSpritesFromJson(sprites);

	sprites = obj["items"];
	this->readSpritesFromJson(sprites);

	sprites = obj["enemies"];
	this->readSpritesFromJson(sprites);

	//...

}

void FileManager::loadBiomeSprites(const char* filename){
	std::ifstream ifs(filename);
	Json::Reader reader;
	Json::Value biome;

	reader.parse(ifs, biome);

	Json::Value new_sprites = biome["sprites"];
	this->readSpritesFromJson(new_sprites);
}

void FileManager::readSpritesFromJson(Json::Value& object) {

	// read the sprites:

	sf::Texture* tex;
	for (int i=0; i<object.size(); i++){
		tex = new sf::Texture();
		tex->loadFromFile(object[i]["path"].asString());
		sprites.insert(std::pair<std::string, sf::Texture*>(object[i]["name"].asString(), tex));
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
