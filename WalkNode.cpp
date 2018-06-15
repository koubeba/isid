#include "WalkNode.h"


WalkNode::WalkNode(Player* _player, Enemy* _enemy, GraphMap* _gmap, TiledMap* _map) {
  player = _player;
  enemy = _enemy;
  gmap = _gmap;
  map = _map;

  tooFarAway = 20;
  tooClose = 3;
}

WalkNode::WalkNode(Player* _player, Enemy* _enemy, GraphMap* _gmap, TiledMap* _map, int _far, int _close) {
  player = _player;
  enemy = _enemy;
  gmap = _gmap;
  map = _map;

  tooFarAway = _far;
  tooClose = _close;

}

Status WalkNode::processInit() {
  visited = true;

  // Look if the player isn't too far away
  Node playerNode = gmap->findNode(player->getPosition().x, player->getPosition().y);
  Node enemyNode = gmap->findNode(enemy->getPosition().x, enemy->getPosition().y);
  if (manhattanDist(playerNode, enemyNode) > tooFarAway) {
    status = FAILURE;
    return status;
  } else {
    status = RUNNING;
    return status;
  }
}

Status WalkNode::processContinue() {

  Node playerNode = gmap->findNode(player->getPosition().x, player->getPosition().y);
  Node enemyNode = gmap->findNode(enemy->getPosition().x, enemy->getPosition().y);
  if (manhattanDist(playerNode, enemyNode) < tooClose) {
    status = SUCCESS;
    return status;
  } else if (manhattanDist(playerNode, enemyNode) > tooFarAway){
    status = FAILURE;
    return status;
  } else {
    enemy->findDir(*player, *gmap, *map);
    return RUNNING;
  }

}
