#ifndef REPEATER_H
#define REPEATER_H

#include "DecoratorNode.h"

// A repeater is always running and reprocesses a child everytime it
// returns a result

class Repeater: public DecoratorNode {
public:
  Status processInit();
  Status processContinue();
};

#endif
