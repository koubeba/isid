#ifndef __PAWN_H__
#define __PAWN_H__

#include "RenderedObject.h"

enum Direction{UP, DOWN, LEFT, RIGHT};

class Pawn : public RenderedObject{
protected:
    bool alive;
    Direction direction;
    int health;
    int mana;
public:
    Pawn();
    Pawn(sf::Sprite* sprite);
    void takeDamage(int damage);
    void drainMana(int amount);
    int getHealth();
    int getMana();

    void move(Direction);

    Direction getDirection();
    void setDirection(Direction dir);

    bool Alive();
};


#endif