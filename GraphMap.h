#ifndef __GRAPHMAP_H__
#define __GRAPHMAP_H__

#include <vector>
#include <iostream>

#include "TiledMap.h"
#include <float.h>
#include "Tile.h"
#include "Pawn.h"



class Node{
public:
    std::vector< Node* > neighbours;
    Node* parent;
    Vec2D position;
    double f, g, h;
    Node();
    Node(Vec2D pos);

    Node* getParent();
    void setParent(Node* node);

    Node* getNeighbour(Direction dir);
    void setNeighbour(Direction dir, Node* node);
};

typedef std::pair<double, Node*> pPair;

class GraphMap{
private:
    Node** nodes;
public:
    GraphMap();

    Node findNode(int x, int y);
    int aStar(TiledMap* map, Node* start, Node* finish);

    void restructureGraph(TiledMap* map);
};

bool isInBounds(float x, float y);

bool movementPossible(Node& node, Direction dir);

bool isObstacle(Node& node, TiledMap& map);

bool isGoal(Node& node, Node& goal);

float manhattanDist(Node& node, Node& goal);



#endif