#include "Enemy.h"

#include "SelectorNode.h"
#include "WalkNode.h"
#include "WaitNode.h"

Enemy::Enemy() {
}

Enemy::Enemy(sf::Sprite* _sprite){
    sprite = _sprite;
}

void Enemy::update(Pawn& player){
    Pawn::update();
    if (health <= 0) alive = false;

    behavioralTree->iterate();

    //... 'ere be dragons
}

void Enemy::runAway(Pawn& player, GraphMap& gmap, TiledMap& map) {
  Pawn::update();
  Node playerNode = gmap.findNode(player.getPosition().x, player.getPosition().y);
  Node enemyNode = gmap.findNode(this->getPosition().x, this->getPosition().y);
  Direction dire;
  if(!moving){
      int dir = gmap.aStar(&map, &playerNode, &enemyNode);
      //Direction dire = RIGHT;
      Vec2D pos = this->getPosition();
      //std::cout << dir << "\n";
      dire = static_cast<Direction>(dir);
      if(dire >= 0) {
          if(dire == UP) pos = pos + Vec2D(0, -1);
          if(dire == DOWN) pos = pos + Vec2D(0, 1);
          if(dire == LEFT) pos = pos + Vec2D(-1, 0);
          if(dire == RIGHT) pos = pos + Vec2D(1, 0);
          if( pos.x >= 0 && pos.x < GridMap::getSize().x && pos.y >= 0 && pos.y < GridMap::getSize().y)
          if (map.getTileType(pos) == FLOOR) this->move(dire);
      }
  }
}

void Enemy::findDir(Pawn& player, GraphMap& gmap, TiledMap& map){
    Pawn::update();
    Node playerNode = gmap.findNode(player.getPosition().x, player.getPosition().y);
    Node enemyNode = gmap.findNode(this->getPosition().x, this->getPosition().y);
    Direction dire;
    if(!moving){
        int dir = gmap.aStar(&map, &enemyNode, &playerNode);
        //Direction dire = RIGHT;
        Vec2D pos = this->getPosition();
        //std::cout << dir << "\n";
        dire = static_cast<Direction>(dir);
        if(dire >= 0) {
            if(dire == UP) pos = pos + Vec2D(0, -1);
            if(dire == DOWN) pos = pos + Vec2D(0, 1);
            if(dire == LEFT) pos = pos + Vec2D(-1, 0);
            if(dire == RIGHT) pos = pos + Vec2D(1, 0);
            if( pos.x >= 0 && pos.x < GridMap::getSize().x && pos.y >= 0 && pos.y < GridMap::getSize().y)
            if (map.getTileType(pos) == FLOOR) this->move(dire);
        }
    }
}

void Enemy::initializeBehaviorTree(Player* player, GraphMap* gmap, TiledMap* map) {
  // create a selector master node //
  SelectorNode* masterNode = new SelectorNode();

  // add a walk node to a master node
  WalkNode* walkNode = new WalkNode(player, this, gmap, map);
  masterNode->addChild(walkNode);

  // add a wait node to a master node
  WaitNode* waitNode = new WaitNode();
  masterNode->addChild(waitNode);

  behavioralTree = new BehavioralTree(masterNode);
}
