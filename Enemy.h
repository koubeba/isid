#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Pawn.h"
#include <SFML/Graphics.hpp>

class Enemy : public Pawn {
public:
    Enemy();
    Enemy(sf::Sprite* sprite);
    void update();
};

#endif
