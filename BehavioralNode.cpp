#include "BehavioralNode.h"

BehavioralNode::BehavioralNode() {
  status = RUNNING;
  visited = false;
}

Status BehavioralNode::getStatus() {
  return status;
}

bool BehavioralNode::wasVisited() {
  return visited;
}

void BehavioralNode::setVisited(bool _visited) {
  visited = _visited;
}

void BehavioralNode::setStatus(Status _status) {
  status = _status;
}

Status BehavioralNode::process() {
  if (visited)  return processContinue();
  else return processInit();
}

Status BehavioralNode::processInit() {
  // nothing
  return status;
}

Status BehavioralNode::processContinue() {
  // nothing
  return status;
}
