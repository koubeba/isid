#ifndef WAIT_NODE_H
#define WAIT_NODE_H

#include "LeafNode.h"

class WaitNode: public LeafNode {
public:
  WaitNode();
  Status processInit();
  Status processContinue();
};

#endif
