#include "RepeatUntilFail.h"

Status RepeatUntilFail::processInit() {
  visited = false;
  Status result;
  result = child->process();
  if (result == SUCCESS) {
    // repeat
    child->setVisited(false);
    status = RUNNING;
  } else {
    status = result;
    return status;
  }
}

Status RepeatUntilFail::processContinue() {
  // nothing
}
