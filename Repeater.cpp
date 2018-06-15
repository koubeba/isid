#include "Repeater.h"

Repeater::Repeater(BehavioralNode* child): DecoratorNode(child) {
  
}

Status Repeater::processInit() {
  visited = false;
  Status result;
  if (child->getStatus() == RUNNING) {
    result = child->processContinue();
    if (result != RUNNING) {
      // Reprocess the child
      child->setVisited(false);
    }
  } else {
    result = child->processInit();
  }
  status = RUNNING;
  return status;
}

Status Repeater::processContinue() {
  // nothing
}
