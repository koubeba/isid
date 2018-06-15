#include "SequenceNode.h"

#include <iostream>

Status SequenceNode::processChildren() {
  for (std::vector<BehavioralNode*>::iterator child = children.begin(); child != children.end(); ++child) {
    Status result;
    if (!(*child)->wasVisited() || (*child)->getStatus() == RUNNING) {
      result = (*child)->process();
      if (result == SUCCESS) {
        setAllChildrenToUnvisited();
        status = SUCCESS;
        return status;
      } else if (result == RUNNING) {
        status = RUNNING;
        return status;
      } else {
        setAllChildrenToUnvisited();
        status = FAILURE;
        return status;
      }
    }
  }
  setAllChildrenToUnvisited();
  status = FAILURE;
  return status;
}

Status SequenceNode::processInit() {
  std::cout << std::endl;
  visited = true;
  Status result = processChildren();
  std::cout << std::endl;
}

void SequenceNode::setNumber(int number) {
  i = number;
}

Status SequenceNode::processContinue() {
  std::cout << std::endl;
  Status result= processChildren();
  std::cout << std::endl;
}
