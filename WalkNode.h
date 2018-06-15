#ifndef WALK_NODE_H
#define WALK_NODE_H

#include "LeafNode.h"
#include "Player.h"
#include "Enemy.h"
#include "GraphMap.h"

class WalkNode: public LeafNode {
  Player* player;
  Enemy* enemy;
  GraphMap* gmap;
  TiledMap* map;
public:
  WalkNode(Player* _player, Enemy* _enemy, GraphMap* _gmap, TiledMap* _map);
  Status processInit();
  Status processContinue();
};

#endif
