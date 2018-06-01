#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Pawn.h"

class Player : public Pawn {
    //slots, pots, and so on
public:
    Player();
    Player(sf::Sprite* _sprite);

    void useHealthPotion();
    void useManaPotion();
    //void useSkill(?);

    void update();
};

#endif