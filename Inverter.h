#ifndef INVERTER_H
#define INVERTER_H

#include "DecoratorNode.h"

class Inverter: public DecoratorNode {
public:
  Status processInit();
  Status processContinue();
};

#endif
