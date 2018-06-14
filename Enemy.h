#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Pawn.h"
#include "GraphMap.h"
#include <SFML/Graphics.hpp>

class Enemy : public Pawn {
    int damage;
public:
    Enemy();
    Enemy(sf::Sprite* sprite);

    void Damage(Pawn& pawn);

    // Here we will execute the behaviour tree decision
    void update(Pawn& player);
    void findDir(Pawn& player, GraphMap& gmap, TiledMap& map);
private:
    void runAway(Pawn& player);
    void chase(Pawn& player);


};

#endif
