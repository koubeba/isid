#include "DecoratorNode.h"

DecoratorNode::DecoratorNode(BehavioralNode* _child): BehavioralNode() {
  child = _child;
}
