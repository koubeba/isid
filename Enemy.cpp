#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(sf::Sprite* _sprite){
    sprite = _sprite;
}

void Enemy::update(Pawn& player){
    Pawn::update();
    if (health <= 0) alive = false;

    //... 'ere be dragons
}

void Enemy::runAway(Pawn& player) {
    // ruuuuuun
}

void Enemy::chase(Pawn& player) {
    // go after him!!!
}
