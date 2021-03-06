#include "TiledMap.h"
#include "Player.h"
#include "Enemy.h"

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

TileType TiledMap::getTileType(Vec2D position){
    return getTileType(position.x, position.y);
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



int TiledMap::countAliveNeighbours(int x, int y){
    int count = 0;
    int neighbour_x, neighbour_y;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            neighbour_x = x+i;
            neighbour_y = y+j;

            if(i == 0 && j == 0) continue;
            else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= GridMap::getSize().x || neighbour_y >= GridMap::getSize().y){
                count++;
            }
            else if(tiles[neighbour_x][neighbour_y].getTileType() == OBSTACLE){
                count++;
            }
        }
    }
    return count;
}

int TiledMap::countAliveNeighbours( Vec2D position ){
    return countAliveNeighbours(position.x, position.y);
}

void TiledMap::doSimulationStep(int starvationLimit, int overpopulationLimit, int birthThreshold){
    Vec2D mapsize = GridMap::getSize();
    bool** newMap = new bool*[(int)mapsize.x];
    for(int i=0; i<mapsize.x; i++){
        newMap[i] = new bool[(int)mapsize.y];
    }

    for(int i=0; i<mapsize.x; i++){
        for(int j=0; j<mapsize.y; j++){
            int nbs = countAliveNeighbours(i, j);

            if(tiles[i][j].getTileType() == OBSTACLE){
                if(nbs < starvationLimit || nbs > overpopulationLimit){
                    newMap[i][j] = false;
                }
                else{
                    newMap[i][j] = true;
                }
            }
            else{
                if(nbs > birthThreshold){
                    newMap[i][j] = true;
                }
                else{
                    newMap[i][j] = false;
                }
            }
        }
    }

    for(int i=0; i<mapsize.x; i++){
        for(int j=0; j<mapsize.y; j++){
            if(newMap[i][j]) tiles[i][j].setTileType(OBSTACLE);
            else tiles[i][j].setTileType(FLOOR);
        }
        delete newMap[i];
    }

}

void TiledMap::generate(const char* biome, Player* player,std::vector<Enemy*>& enemies){
    std::ifstream ifs(biome);
	Json::Reader reader;
	Json::Value values;
	reader.parse(ifs, values);

    int density, smoothness, item_count;
    density = values["density"].asInt();
    smoothness = values["smoothness"].asInt();
    item_count = values["item_count"].asInt();

    Vec2D mapsize = GridMap::getSize();
    float chanceToStartAlive = density/100.0f;

    time_t tt;
    srand( time(&tt) );

    for(int i=0; i<mapsize.x; i++){
        for (int j=0; j<mapsize.y; j++){
            if(rand()/(RAND_MAX+1.0) < chanceToStartAlive) tiles[i][j].setTileType(OBSTACLE);
        }
    }

    for(int i=0; i<smoothness; ++i){
        doSimulationStep(3, 10, 4);
    }

    std::vector<Tile*> free_tiles;
    Vec2D size = GridMap::getSize();
    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            tiles[i][j].setPosition( Vec2D(i, j) );
            if(tiles[i][j].getTileType() == FLOOR) free_tiles.push_back(&tiles[i][j]);
        }
    }

    std::vector<Tile*>::iterator it;

    int player_pos = random(0, free_tiles.size());
    it = free_tiles.begin();
    for ( int i=0; i<player_pos; i++) it++;
    player->setPosition( (*it)->getPosition() );
    free_tiles.erase(it);

    std::vector<Tile*> treasure_tiles;
    for(it = free_tiles.begin(); it!=free_tiles.end(); ++it){
        if( countAliveNeighbours( (*it)->getPosition().x, (*it)->getPosition().y ) > 4  && countAliveNeighbours( (*it)->getPosition() ) < 9) treasure_tiles.push_back( (*it) );
    }

    for(int i=0; i<item_count; ++i){
        do{
          int item_pos = random(0, treasure_tiles.size());
            it = treasure_tiles.begin();
            for ( int i=0; i<item_pos; i++) it++;
        }
        while( it != treasure_tiles.begin() && distance((*it)->getPosition(), player->getPosition()) < 7 );
        items.push_back(new Item((*it)->getPosition().x, (*it)->getPosition().y, ItemType( random(0, 3) )) );
    }

    for (std::vector<Enemy*>::iterator itr = enemies.begin(); itr != enemies.end(); ++itr) {
      do{
          int enemy_pos = random(0, free_tiles.size());
            it = free_tiles.begin();
            for ( int i=0; i<enemy_pos; i++) it++;
            (*itr)->setPosition( (*it)->getPosition() );
        }
        while(distance((*itr)->getPosition(), player->getPosition()) < 7);
      free_tiles.erase(it);
    }

}
