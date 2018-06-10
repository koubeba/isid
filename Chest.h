#ifndef __CHEST_H__
#define __CHEST_H__

//#include <vector>
#include "Item.h"

class Chest : public Item {
    std::vector<Item*> contents;
public:
    std::vector<Item*>& getContents();
};

#endif