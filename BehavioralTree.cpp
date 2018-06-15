#include "BehavioralTree.h"

#include <iostream>

BehavioralTree::BehavioralTree(CompositeNode* _masterNode) {
  masterNode = new Repeater(_masterNode);
}

void BehavioralTree::iterate() {
  // The master node is always unvisited and running
  masterNode->process();
}
