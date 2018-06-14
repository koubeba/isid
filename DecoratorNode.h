#ifndef DECORATOR_NODE_H
#define DECORATOR_NODE_H

#include "BehavioralNode.h"

// A decorator node can have only one child and transforms the result of child

class DecoratorNode: public BehavioralNode {
protected:
  BehavioralNode* child;
public:
  DecoratorNode(BehavioralNode* _child);
};

#endif
