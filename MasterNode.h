#ifndef MASTER_NODE_H
#define MASTER_NODE_H

#include "CompositeNode.h"

class MasterNode: public CompositeNode {
public:
  Status processInit();
  Status processContinue();
};

#endif
