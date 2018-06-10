#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Pawn.h"
#include "Item.h"
#include "TiledMap.h"

class Player : public Pawn {
    std::vector<Item*> equipment;
    //slots, pots, and so on
public:
    Player();
    Player(sf::Sprite* _sprite);

    void useHealthPotion();
    void useManaPotion();
    //void useSkill(?);

    void update(TiledMap &map);
};

#endif