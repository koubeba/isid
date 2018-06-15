#ifndef __PAWN_H__
#define __PAWN_H__

#include "RenderedObject.h"

enum Direction{UP, DOWN, LEFT, RIGHT};

const float PAWN_SPEED = .015f;  // set this to a right value, please
                                  // ok

class Pawn : public RenderedObject{
protected:
    bool alive;
    Direction direction;
    int health;
    int mana;
    Vec2D animTarget;
    bool moving;

public:
    Pawn();
    Pawn(sf::Sprite* sprite);
    void takeDamage(int damage);
    void drainMana(int amount);
    int getHealth();
    int getMana();
    bool isMoving();
    virtual void update();

    void move(Direction);

    Direction getDirection();
    void setDirection(Direction dir);

    bool Alive();
};


#endif
