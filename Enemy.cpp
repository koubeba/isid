#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(sf::Sprite* _sprite){
    sprite = _sprite;
}

void Enemy::update(){
    Pawn::update();
    if (health <= 0) alive = false;

    //... 'ere be dragons
}