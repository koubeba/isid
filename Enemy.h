#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Pawn.h"
#include "GraphMap.h"
#include <SFML/Graphics.hpp>
#include "BehavioralTree.h"

class Enemy : public Pawn {
protected:
    int damage;
    BehavioralTree* behavioralTree;
public:
    Enemy();
    Enemy(sf::Sprite* sprite);

    void Damage(Pawn& pawn);

    // setters
    virtual void initializeBehaviorTree(Player* player, GraphMap* gmap, TiledMap* map);

    // Here we will execute the behaviour tree decision
    void update(Pawn& player);
    void findDir(Pawn& player, GraphMap& gmap, TiledMap& map);
    void runAway(Pawn& player, GraphMap& gmap, TiledMap& map);
private:

};

#endif
