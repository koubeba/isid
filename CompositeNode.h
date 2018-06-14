#ifndef COMPOSITE_NODE_H
#define COMPOSITE_NODE_H

// A composite node is a node that processes its child nodes

#include "BehavioralNode.h"
#include <vector>

class CompositeNode: public BehavioralNode {
protected:
  std::vector<BehavioralNode*> children;
public:
  CompositeNode();
  void addChild(BehavioralNode* node);
  virtual Status processChildren();
protected:
  void setAllChildrenToUnvisited();
};

#endif
