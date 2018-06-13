#ifndef COMPOSITE_NODE_H
#define COMPOSITE_NODE_H

#include "BehavioralNode.h"
#include <vector>

class CompositeNode: public BehavioralNode {
  std::vector<BehavioralNode*> children;
public:
  CompositeNode();
  void addChild(BehavioralNode* node);
  virtual void processChildren();
};

#endif
