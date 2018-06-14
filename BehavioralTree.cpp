#include "BehavioralTree.h"

#include <iostream>

BehavioralTree::BehavioralTree(CompositeNode* _masterNode) {
  masterNode = _masterNode;
}

void BehavioralTree::iterate() {
  std::cout << "Behavioral Tree iteration" << std::endl;
  // The master node is always unvisited and running
  masterNode->setVisited(false);
  masterNode->setStatus(RUNNING);
  masterNode->process();
}
