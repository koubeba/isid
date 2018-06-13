#include "CompositeNode.h"

CompositeNode::CompositeNode() : BehavioralNode() {
  children = std::vector<BehavioralNode*>();
}

void CompositeNode::addChild(BehavioralNode* node) {
  children.push_back(node);
}

void CompositeNode::processChildren() {
  // ...
}
