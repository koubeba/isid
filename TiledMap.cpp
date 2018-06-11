#include "TiledMap.h"
#include "Player.h"

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

Item* TiledMap::getItem(Vec2D position){
    for(std::vector<Item*>::iterator i=items.begin(); i != items.end(); i++){
        if( (*i)->getPosition().x == position.x && (*i)->getPosition().y == position.y) return *i;
    }
    return NULL;
}

void TiledMap::removeItem(Vec2D position){
    for(std::vector<Item*>::iterator i=items.begin(); i != items.end(); i++){
        if( (*i)->getPosition().x == position.x && (*i)->getPosition().y == position.y){
            items.erase(i);
            break;
        }
    }
}

void TiledMap::load(FileManager& fileManager){
    Vec2D size = GridMap::getSize();
    std::string type_name;
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
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

int random(int min, int max){
    if (max<min){
        int temp = max;
        max = min;
        min = temp;
    }
    return ( rand()/(RAND_MAX+1.0) )*(max-min) + min;
}


void TiledMap::generate(const char* biome, Player* player){
    std::ifstream ifs(biome);
	Json::Reader reader;
	Json::Value values;
	reader.parse(ifs, values);

    int density, groupity;
    density = values["density"].asInt();
    groupity = values["groupity"].asInt();

    /*
    tiles[4][2].setTileType(OBSTACLE);
    tiles[6][6].setTileType(OBSTACLE);
    tiles[12][3].setTileType(OBSTACLE);
	tiles[14][12].setTileType(OBSTACLE);

    tiles[8][7].setTileType(CHEST);
    
    items.push_back( new Item(10, 10, HPOTION) );
    items.push_back( new Item(12, 10, MPOTION) );
    items.push_back( new Item(13, 9, HPOTION) );
    items.push_back( new Item(13, 9, WEAPON) );
    */

    time_t tt;
    srand( time(&tt) );

    std::vector<Tile*> free_tiles;

    Vec2D size = GridMap::getSize();
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            tiles[i][j].setPosition( Vec2D(i, j) );
            if(tiles[i][j].getTileType() == FLOOR) free_tiles.push_back(&tiles[i][j]);
        }
    }

    std::vector<Tile*>::iterator it;

    int obstacle_num = random( 13, 15 );

    for(int i=0; i<obstacle_num; i++){
        it = free_tiles.begin();
        int temp = random( 0, free_tiles.size() );
        for(int j=0; j<temp; j++) it++;
        (*it)->setTileType(OBSTACLE);
        free_tiles.erase(it);
    }

    int player_pos = random(0, free_tiles.size());
    it = free_tiles.begin();
    for ( int i=0; i<player_pos; i++) it++;
    player->setPosition( (*it)->getPosition() );
    
}