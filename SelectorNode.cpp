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
  std::cout << "Initialize the selector process." << i << "Setting to visited. Status: ";
  switch (status) {
    case RUNNING: std::cout << "running ";
    break;
    case SUCCESS: std::cout << "success ";
    break;
    case FAILURE: std::cout << "failure ";
    break;
  }
  std::cout << std::endl;
  visited = true;
  Status result = processChildren();

  std::cout << "Result of selector's children process: ";
  switch (result) {
    case RUNNING: std::cout << "running ";
    break;
    case SUCCESS: std::cout << "success ";
    break;
    case FAILURE: std::cout << "failure ";
    break;
  }
  std::cout << std::endl;
  return result;
}

Status SelectorNode::processContinue() {
  std::cout << "Continue the selector process." << i << " Status: ";
  switch (status) {
    case RUNNING: std::cout << "running ";
    break;
    case SUCCESS: std::cout << "success ";
    break;
    case FAILURE: std::cout << "failure ";
    break;
  }
  std::cout << std::endl;
  Status result= processChildren();
  std::cout << "Result of selector's children process: ";
  switch (result) {
    case RUNNING: std::cout << "running ";
    break;
    case SUCCESS: std::cout << "success ";
    break;
    case FAILURE: std::cout << "failure ";
    break;
  }
  std::cout << std::endl;
  return result;
}
