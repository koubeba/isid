#ifndef TUBAMAN_H
#define TUBAMAN_H

#include "Enemy.h"

class Tubaman: public Enemy {
public:
  Tubaman(sf::Sprite* sprite);
  void initializeBehaviorTree(Player* player, GraphMap* gmap, TiledMap* map);
};

#endif
