#ifndef __PAWN_H__
#define __PAWN_H__

#include "RenderedObject.h"

#include <cmath>

enum Direction{UP, DOWN, LEFT, RIGHT};

const float PAWN_SPEED = .001f;

float distance(const Vec2D& a, const Vec2D& b);

class Pawn : public RenderedObject{
protected:
    bool alive;
    Direction direction;
    int health;
    int mana;
    Vec2D animTarget;
    bool isMoving;

public:
    Pawn();
    Pawn(sf::Sprite* sprite);
    void takeDamage(int damage);
    void drainMana(int amount);
    int getHealth();
    int getMana();
    virtual void update();

    void move(Direction);

    Direction getDirection();
    void setDirection(Direction dir);

    bool Alive();
};


#endif