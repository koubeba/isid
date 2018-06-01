#include "Pawn.h"

Pawn::Pawn(){
    alive = true;
    health = 100;
    mana = 100;
    direction = DOWN; //hehehe he he  he   he
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

void Pawn::move(Direction dir){
    switch(dir){
        case UP:
            this->setPosition( this->getPosition() + Vec2D(0, -1) );
            break;
        case DOWN:
            this->setPosition( this->getPosition() + Vec2D(0, 1) );
            break;
        case LEFT:
            this->setPosition( this->getPosition() + Vec2D(-1, 0) );
            break;
        case RIGHT:
            this->setPosition( this->getPosition() + Vec2D(1, 0) );
            break;
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