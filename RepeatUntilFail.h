#ifndef REPEAT_UNTIL_FAIL_H
#define REPEAT_UNTIL_FAIL_H

#include "DecoratorNode.h"

class RepeatUntilFail: public DecoratorNode {
public:
  Status processInit();
  Status processContinue();
};

#endif
