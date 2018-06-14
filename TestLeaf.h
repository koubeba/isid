#ifndef TEST_LEAF_H
#define TEST_LEAF_H

#include "LeafNode.h"

class TestLeaf: public LeafNode {
  int i;
public:
  TestLeaf(int number);
  Status processInit();
  Status processContinue();
};

#endif
