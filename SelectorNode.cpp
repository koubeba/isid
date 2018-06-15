#include "SelectorNode.h"

#include <iostream>

Status SelectorNode::processChildren() {
  // Go through all children and process these which haven't been visited yet or are running.
  for (std::vector<BehavioralNode*>::iterator child = children.begin(); child != children.end(); ++child) {
      Status result;
      if (!(*child)->wasVisited() || (*child)->getStatus() == RUNNING) {
        result = (*child)->process();
        if (result == SUCCESS) {
          setAllChildrenToUnvisited();
          status = SUCCESS;
          return status;
        } else {
          status = RUNNING;
          return status;
        }
    }
  }
  setAllChildrenToUnvisited();
  status = FAILURE;
  return status;
}

void SelectorNode::setNumber(int number) {
  i = number;
}

Status SelectorNode::processInit() {
  std::cout << std::endl;
  visited = true;
  Status result = processChildren();
  std::cout << std::endl;
  return result;
}

Status SelectorNode::processContinue() {
  std::cout << std::endl;
  Status result= processChildren();
  std::cout << std::endl;
  return result;
}
