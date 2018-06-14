#ifndef RANDOM_SELECTOR_NODE_H
#define RANDOM_SELECTOR_NODE_H

// A node that chooses a random child.

#include "CompositeNode.h"

class RandomSelectorNode: public CompositeNode {
  int i;
public:
  Status processChildren();

  // setters
  void setNumber(int number);

  // overrides
  Status processInit();
  Status processContinue();
};

#endif
