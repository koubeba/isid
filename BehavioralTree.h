#ifndef BEHAVIORAL_TREE_H
#define BEHAVIORAL_TREE_H

#include "CompositeNode.h"
#include "Repeater.h"

class BehavioralTree {
  Repeater* masterNode;
public:
  BehavioralTree(CompositeNode* _masterNode);
  virtual void iterate();
};
#endif
