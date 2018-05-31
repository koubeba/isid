#include "TiledMap.h"

TiledMap::TiledMap(){
    Vec2D size = GridMap::getSize();
    tiles = new Tile*[size.x];
    for(int i=0; i<size.x; i++){
        tiles[i] = new Tile[size.y];
    }
}

void TiledMap::load(GameManager& gameManager){
    Vec2D size = GridMap::getSize();
    std::string type_name;
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            tiles[i][j].setPosition( Vec2D(i, j) );

            switch(tiles[i][j].getTileType()){
                case FLOOR:
                    type_name = "floor";
                    break;
                case OBSTACLE:
                    type_name = "obstacle";
                    break;
                case LIQUID:
                    type_name = "liquid";
                    break;
                case CHEST:
                    type_name = "chest";
                    break;
            }
            tiles[i][j].loadSprite(gameManager.getSprite( type_name ));
        }
    }
}

void TiledMap::render(sf::RenderWindow& _window){
    Vec2D size = GridMap::getSize();
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            tiles[i][j].render(_window);
        }
    }
}

void TiledMap::generate(const char* biome){
    std::ifstream ifs(biome);
	Json::Reader reader;
	Json::Value values;
	reader.parse(ifs, values);

    tiles[4][2].setTileType(OBSTACLE);
    tiles[6][6].setTileType(OBSTACLE);
    tiles[12][3].setTileType(OBSTACLE);
	tiles[14][12].setTileType(OBSTACLE);

    int density, groupity;
    density = values["density"].asInt();
    groupity = values["groupity"].asInt();
    //... 'ere be magic
}