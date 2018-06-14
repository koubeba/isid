#ifndef BEHAVIORAL_TREE_H
#define BEHAVIORAL_TREE_H

#include "CompositeNode.h"

class BehavioralTree {
  CompositeNode* masterNode;
public:
  BehavioralTree(CompositeNode* _masterNode);
  void iterate();
};
#endif
