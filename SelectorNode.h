#ifndef SELECTOR_NODE_H
#define SELECTOR_NODE_H

// A selector is a node that stops at the first child that returns
// a positive value. Think of an OR gate

#include "CompositeNode.h"

class SelectorNode : public CompositeNode {
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
