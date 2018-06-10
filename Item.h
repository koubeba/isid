#ifndef __ITEM_H__
#define __ITEM_H__

#include "RenderedObject.h"

enum ItemType {HPOTION, MPOTION, WEAPON};

class Item : public RenderedObject {
    ItemType type;
public:
    Item( int x, int y, ItemType type);
    void setSprite(sf::Sprite *sprite);
    void setType(ItemType type);
    ItemType getType();
};

#endif