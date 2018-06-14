#include "CompositeNode.h"

CompositeNode::CompositeNode() : BehavioralNode() {
  children = std::vector<BehavioralNode*>();
}

void CompositeNode::addChild(BehavioralNode* node) {
  children.push_back(node);
}

Status CompositeNode::processChildren() {
  // nothing
}

void CompositeNode::setAllChildrenToUnvisited() {
  for (std::vector<BehavioralNode*>::iterator child = children.begin(); child != children.end(); ++child) {
    (*child)->setVisited(false);
  }
}
