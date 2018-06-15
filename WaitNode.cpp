#include "WaitNode.h"

WaitNode::WaitNode(): LeafNode() {
  // nothing
}

Status WaitNode::processInit() {
  visited = false;

  // just wait

  status = SUCCESS;
  return status;
}

Status WaitNode::processContinue() {
  // nothing
  status = SUCCESS;
  return status;
}
