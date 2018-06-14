#include "GraphMap.h"
#include <iostream>
#include <utility>
#include <set>
Node::Node(){
    neighbours = {nullptr, nullptr, nullptr, nullptr};
    position = Vec2D(0,0);
    parent = nullptr;
    f = FLT_MAX;
    g = FLT_MAX;
    h = FLT_MAX;
}

Node::Node(Vec2D pos){
    neighbours = {nullptr, nullptr, nullptr, nullptr};
    position = pos;
    parent = nullptr;
    f = FLT_MAX;
    g = FLT_MAX;
    h = FLT_MAX;
}

Node* Node::getParent(){
    return parent;
}

void Node::setParent(Node* node){
    if ( abs(this->position.x - node->position.x) <= 1.01 && abs(this->position.y - node->position.y) <= 1.01 ) parent = node;
}

Node* Node::getNeighbour(Direction dir){
    return neighbours[dir];
}

void Node::setNeighbour(Direction dir, Node* node){
    neighbours[dir] = node;
}

GraphMap::GraphMap(){
    Vec2D size = GridMap::getSize();
    nodes = new Node*[int(size.x)];
    for(int i=0; i<size.x; i++){
        nodes[i] = new Node[int(size.y)];
    }

    for(int i=0; i<size.x; i++){
        for(int j=0; j<size.y; j++){
            nodes[i][j].position = Vec2D(i,j);
        }
    }
}

Node GraphMap::findNode(int x, int y){

    return nodes[x][y];
}


void GraphMap::restructureGraph(TiledMap* map){
    Vec2D size = GridMap::getSize();
    Tile* tile;
    for(int i = 0; i < size.x; i++){
        for(int j = 0; j < size.y; j++){
            if( i - 1 >= 0){   
                tile = map->getTile(i-1,j);   // left neighbour

                if (tile != nullptr && map->getTileType(i-1, j) == FLOOR){
                    nodes[i][j].setNeighbour(LEFT, &nodes[i-1][j]);
                    nodes[i-1][j].setNeighbour(RIGHT, &nodes[i][j]);
                }
            }
            if( j - 1 >= 0){
                tile = map->getTile(i,j-1);   // upper neighbour

                if (tile != nullptr && map->getTileType(i, j-1) == FLOOR){
                    nodes[i][j].setNeighbour(UP, &nodes[i][j-1]);
                    nodes[i][j-1].setNeighbour(DOWN, &nodes[i][j]);
                }
            }
            if( i + 1 < size.x){
                tile = map->getTile(i+1,j);   // right neighbour

                if (tile != nullptr && map->getTileType(i+1, j) == FLOOR){
                    nodes[i][j].setNeighbour(RIGHT, &nodes[i+1][j]);
                    nodes[i+1][j].setNeighbour(LEFT, &nodes[i][j]);
                }
            }
            
            if ( j + 1 < size.y){
                tile = map->getTile(i,j+1);   // down neighbour
                if (tile != nullptr && map->getTileType(i, j+1) == FLOOR){
                    nodes[i][j].setNeighbour(DOWN, &nodes[i][j+1]);
                    nodes[i][j+1].setNeighbour(UP, &nodes[i][j]);
                }
            }
        }
    }
}

bool isInBounds(float x, float y){
    Vec2D size = GridMap::getSize();
    return (x >= 0) && (x < size.x) && (y >= 0) && (y < size.y);
}

bool movementPossible(Node& node, Direction dir){
    return node.neighbours[dir] != nullptr;
}

bool isObstacle(Node* node, TiledMap& map){
    if(map.getTileType(node->position) == FLOOR) return false;
    else return true;
}

bool isGoal(Node& node, Node& goal){
    return node.position.x == goal.position.x && node.position.y == goal.position.y;
}

float manhattanDist(Node& node, Node& goal){
    return abs(node.position.x - goal.position.x) + abs(node.position.y - goal.position.y);
}

int GraphMap::aStar(TiledMap* map, Node* start, Node* finish) {
    
    if (!isInBounds(start->position.x, start->position.y)) return -1;
    if (!isInBounds(finish->position.x, finish->position.y)) return -1;
    if (isObstacle(start, *map) || isObstacle(finish, *map)) return -1;
    if (isGoal(*start, *finish)) return -1;

    int width = GridMap::getSize().x;
    int height = GridMap::getSize().y;

    bool closedList[width][height];
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            closedList[i][j] = false;
        }
    }

    std::set<pPair> openList;

    start->f = 0.0;
    start->g = 0.0;
    start->h = 0.0;
    start->parent = start;

    openList.insert(std::make_pair (0.0, start));

    bool foundDest = false;

    int x,y;
    Node* neighbour;

    while(!openList.empty()){
        pPair p = *openList.begin();
        //
        openList.erase(openList.begin());

        x = p.second->position.x;
        y = p.second->position.y;
        

        closedList[x][y] = true;

        float newF, newG, newH;

        // UP

        if (isInBounds(x, y+1)){
            
            neighbour = p.second->getNeighbour(DOWN);
            if(neighbour == nullptr){}
            else if(isGoal(*neighbour, *finish)){
                finish->setParent(p.second);
                foundDest = true;
                break;
            }
            else if(closedList[x][y+1] == false && !isObstacle(neighbour, *map)){
                newG = p.second->g + 1.0;
                newH = manhattanDist(*neighbour, *finish); 
                newF = newG + newH;

                if (neighbour->f == FLT_MAX || neighbour->f > newF){
                    openList.insert(std::make_pair(newF, neighbour));
                    neighbour->f = newF;
                    neighbour->g = newG;
                    neighbour->h = newH;
                    neighbour->setParent(p.second);
                }
            }
        }

        // UP

        if (isInBounds(x, y-1)){
            
            neighbour = p.second->getNeighbour(UP);
            if(neighbour == nullptr){}
            else if(isGoal(*neighbour, *finish)){
                finish->setParent(p.second);
                foundDest = true;
                break;
            }
            else if(closedList[x][y-1] == false && !isObstacle(neighbour, *map)){
                newG = p.second->g + 1.0;
                newH = manhattanDist(*neighbour, *finish);
                newF = newG + newH;

                if (neighbour->f == FLT_MAX || neighbour->f > newF){
                    openList.insert(std::make_pair(newF, neighbour));
                    neighbour->f = newF;
                    neighbour->g = newG;
                    neighbour->h = newH;
                    neighbour->setParent(p.second);
                }
            }
        }


        // LEFT

        if (isInBounds(x-1, y)){
            
            neighbour = p.second->getNeighbour(LEFT);
            if(neighbour == nullptr){}
            else if(isGoal(*neighbour, *finish)){
                finish->setParent(p.second);
                foundDest = true;
                break;
            }
            else if(closedList[x-1][y] == false && !isObstacle(neighbour, *map)){
                newG = p.second->g + 1.0;
                newH = manhattanDist(*neighbour, *finish);
                newF = newG + newH;

                if (neighbour->f == FLT_MAX || neighbour->f > newF){
                    openList.insert(std::make_pair(newF, neighbour));
                    neighbour->f = newF;
                    neighbour->g = newG;
                    neighbour->h = newH;
                    neighbour->setParent(p.second);
                }
            }
        }


        // RIGHT

        if (isInBounds(x+1, y)){
            
            neighbour = p.second->getNeighbour(RIGHT);
            if(neighbour == nullptr){}
            else if(isGoal(*neighbour, *finish)){
                finish->setParent(p.second);
                foundDest = true;
                break;
            }
            else if(closedList[x+1][y] == false && !isObstacle(neighbour, *map)){
                newG = p.second->g + 1.0;
                newH = manhattanDist(*neighbour, *finish);
                newF = newG + newH;

                if (neighbour->f == FLT_MAX || neighbour->f > newF){
                    openList.insert(std::make_pair(newF, neighbour));
                    neighbour->f = newF;
                    neighbour->g = newG;
                    neighbour->h = newH;
                    neighbour->setParent(p.second);
                }
            }
        }
    }
    if (foundDest == false) return -1;
    
    int difX = finish->position.x - finish->parent->position.x;
    int difY = finish->position.y - finish->parent->position.y;

    if(difX > 0)   { return RIGHT; }
    if(difX < 0)    { return LEFT;  }
    if(difY > 0)   { return DOWN;  }
    if(difY < 0)    { return UP;    }

    return -1;

}
