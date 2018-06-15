#ifndef RUN_AWAY_NODE_H
#define RUN_AWAY_NODE_H

#include "LeafNode.h"
#include "Player.h"
#include "Enemy.h"
#include "GraphMap.h"

class RunAwayNode: public LeafNode {
  Player* player;
  Enemy* enemy;
  GraphMap* gmap;
  TiledMap* map;
public:
  RunAwayNode(Player* _player, Enemy* _enemy, GraphMap* _gmap, TiledMap* _map);
  Status processInit();
  Status processContinue();
};

#endif
