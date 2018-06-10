#include "Item.h"

Item::Item(int x, int y, ItemType _type){
    this->setPosition( Vec2D(x, y) );
    type = _type;
}


void Item::setSprite(sf::Sprite *_sprite){
    sprite = _sprite;
}

void Item::setType(ItemType _type){
    type = _type;
}

ItemType Item::getType(){
    return type;
}