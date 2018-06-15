#include "RunAwayNode.h"

RunAwayNode::RunAwayNode(Player* _player, Enemy* _enemy, GraphMap* _gmap, TiledMap* _map) {
  player = _player;
  enemy = _enemy;
  gmap = _gmap;
  map = _map;
}

Status RunAwayNode::processInit() {
  visited =  true;

  // Look if the player isn't too close away
  Node playerNode = gmap->findNode(player->getPosition().x, player->getPosition().y);
  Node enemyNode = gmap->findNode(enemy->getPosition().x, enemy->getPosition().y);
  if (manhattanDist(playerNode, enemyNode) < 2) {
    status = RUNNING;
    return status;
  } else {
    status = FAILURE;
    return status;
  }
}

Status RunAwayNode::processContinue() {

  Node playerNode = gmap->findNode(player->getPosition().x, player->getPosition().y);
  Node enemyNode = gmap->findNode(enemy->getPosition().x, enemy->getPosition().y);
  if (manhattanDist(playerNode, enemyNode) > 3) {
    status = SUCCESS;
    return status;
  } else {
    enemy->runAway(*player, *gmap, *map);
    return RUNNING;
  }

}
