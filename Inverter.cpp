#include "Inverter.h"

Status Inverter::processInit() {
  visited = true;
  Status result = child->processInit();
  if (result == RUNNING) {
    status = result;
    return status;
  } else {
    child->setVisited(false);
    status = result == SUCCESS ? FAILURE : SUCCESS;
    return status;
  }
}

Status Inverter::processContinue() {
  Status result = child->processContinue();
  if (result == RUNNING) {
    status = result;
    return status;
  } else {
    child->setVisited(false);
    status = result == SUCCESS ? FAILURE : SUCCESS;
    return status;
  }
}
