#include "RandomSelectorNode.h"

#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
Status RandomSelectorNode::processChildren() {
  Status result;
  srand(time(NULL));

  int childIndex = rand() % children.size();
  result = (children[childIndex])->process();

  // if the status is terminal (not RUNNING), set all children to setAllChildrenToUnvisited
  if (result != RUNNING) setAllChildrenToUnvisited();

  status = result;
  return status;
}

// setters
void RandomSelectorNode::setNumber(int number) {

}

// overrides
Status RandomSelectorNode::processInit() {
  visited = true;
  Status result = processChildren();
  return result;
}
Status RandomSelectorNode::processContinue() {
  return processChildren();
}
