#include "Cymbalman.h"

#include "RandomSelectorNode.h"
#include "SelectorNode.h"
#include "WalkNode.h"
#include "RunAwayNode.h"
#include "WaitNode.h"

Cymbalman::Cymbalman(sf::Sprite* sprite): Enemy(sprite) {

}

void Cymbalman::initializeBehaviorTree(Player* player, GraphMap* gmap, TiledMap* map) {
  // create a selector master node //
  RandomSelectorNode* masterNode = new RandomSelectorNode();
  // add a walk node to a master node
  WalkNode* walkNode = new WalkNode(player, this, gmap, map, 30, 1);
  masterNode->addChild(walkNode);

  // add a wait node to a master node
  WaitNode* waitNode = new WaitNode();
  masterNode->addChild(waitNode);


  behavioralTree = new BehavioralTree(masterNode);
}
