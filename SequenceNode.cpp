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
  std::cout << "Initialize the sequence process." << i << "Setting to visited. Status: ";
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
}

void SequenceNode::setNumber(int number) {
  i = number;
}

Status SequenceNode::processContinue() {
  std::cout << "Continue the sequence process." << i << " Status: ";
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
  std::cout << "Result of sequence's children process: ";
  switch (result) {
    case RUNNING: std::cout << "running ";
    break;
    case SUCCESS: std::cout << "success ";
    break;
    case FAILURE: std::cout << "failure ";
    break;
  }
  std::cout << std::endl;
}
