#include "TiledMap.h"

TiledMap::TiledMap(){
    Vec2D size = GridMap::getSize();
    tiles = new Tile*[int(size.x)];
    for(int i=0; i<size.x; i++){
        tiles[i] = new Tile[int(size.y)];
    }
}

TileType TiledMap::getTileType(int x, int y){
    return tiles[x][y].getTileType();
}

void TiledMap::load(FileManager& fileManager){
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
            tiles[i][j].loadSprite(fileManager.getSprite( type_name ));
        }
    }
    for(int i=0; i<items.size(); i++){
        switch(items[i]->getType()){
            case HPOTION:
                type_name = "hpotion";
                break;
            case MPOTION:
                type_name = "mpotion";
                break;
            case WEAPON:
                type_name = "sword_tile";
                break;
        }
        items[i]->setSprite( fileManager.getSprite( type_name ));
    }
}

void TiledMap::render(sf::RenderWindow& _window){
    Vec2D size = GridMap::getSize();
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            tiles[i][j].render(_window);
        }
    }
    for(int i=0; i<items.size(); i++){
        items[i]->render(_window);
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
    
    items.push_back( new Item(10, 10, HPOTION) );
    items.push_back( new Item(12, 10, MPOTION) );
    items.push_back( new Item(13, 9, WEAPON) );
    

    int density, groupity;
    density = values["density"].asInt();
    groupity = values["groupity"].asInt();
    //... 'ere be magic
}