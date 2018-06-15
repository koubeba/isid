#include "WaitNode.h"
#include <iostream>

WaitNode::WaitNode(): LeafNode() {
  // nothing
}

Status WaitNode::processInit() {
  visited = false;

std::cout << "Wait" << std::endl;
  // just wait

  status = SUCCESS;
  return status;
}

Status WaitNode::processContinue() {
  // nothing
  status = SUCCESS;
  return status;
}
