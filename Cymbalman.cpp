#include "Cymbalman.h"

#include "SelectorNode.h"
#include "WalkNode.h"
#include "RunAwayNode.h"
#include "WaitNode.h"

Cymbalman::Cymbalman(sf::Sprite* sprite): Enemy(sprite) {

}

void Cymbalman::initializeBehaviorTree(Player* player, GraphMap* gmap, TiledMap* map) {
  // create a selector master node //
  SelectorNode* masterNode = new SelectorNode();

  // add a run away node to a mster Node
  RunAwayNode* runAwayNode = new RunAwayNode(player, this, gmap, map);
  masterNode->addChild(runAwayNode);

  // add a walk node to a master node
  WalkNode* walkNode = new WalkNode(player, this, gmap, map);
  masterNode->addChild(walkNode);



  // add a wait node to a master node
  WaitNode* waitNode = new WaitNode();
  masterNode->addChild(waitNode);


  behavioralTree = new BehavioralTree(masterNode);
}
