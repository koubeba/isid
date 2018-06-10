#include "Pawn.h"
#include <iostream>

Pawn::Pawn(){
    alive = true;
    health = 100;
    mana = 100;
    direction = DOWN;
    moving = false;
}

Pawn::Pawn(sf::Sprite* _sprite){
    sprite = _sprite;
}

void Pawn::takeDamage(int damage){
    health -= damage;
}

int Pawn::getHealth(){
    return health;
}

void Pawn::drainMana(int amount){
    mana -= amount;
}

int Pawn::getMana(){
    return mana;
}

bool Pawn::isMoving(){
    return moving;
}

void Pawn::move(Direction dir){
    switch(dir){
        case UP:
            this->animTarget = Vec2D(this->getPosition() + Vec2D(0, -1));
            break;
        case DOWN:
            this->animTarget = Vec2D(this->getPosition() + Vec2D(0, 1));
            break;
        case LEFT:
            this->animTarget = Vec2D(this->getPosition() + Vec2D(-1, 0));
            break;
        case RIGHT:
            this->animTarget = Vec2D(this->getPosition() + Vec2D(1, 0));
            break;
    }
    moving = true;
}

void Pawn::update() {
    if (moving && distance(this->animTarget, this->getPosition()) > PAWN_SPEED) {
        float dx = this->animTarget.x - this->getPosition().x;
        float dy = this->animTarget.y - this->getPosition().y;
        float angle = atan2(dy, dx);
        float xVelocity = PAWN_SPEED * cos(angle);
        float yVelocity = PAWN_SPEED * sin(angle);
        this->setPosition(this->getPosition() + Vec2D(xVelocity, yVelocity));
    } else if (moving) {
        // distance < PAWN_SPEED
        moving = false;
        this->setPosition(this->animTarget);
    }
}

void Pawn::setDirection(Direction dir){
    this->direction = dir;
}

Direction Pawn::getDirection(){
    return this->direction;
}

bool Pawn::Alive(){
    return alive;
}

float distance(const Vec2D& a, const Vec2D& b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}