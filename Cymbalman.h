#ifndef CYMBALMAN_H
#define CYMBALMAN_H

#include "Enemy.h"

class Cymbalman: public Enemy {
public:
  Cymbalman(sf::Sprite* sprite);
  void initializeBehaviorTree(Player* player, GraphMap* gmap, TiledMap* map);
};

#endif
