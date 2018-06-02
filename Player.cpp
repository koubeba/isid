#include "Player.h"

Player::Player() {}

Player::Player(sf::Sprite* _sprite){
    sprite = _sprite;
}

void Player::useHealthPotion(){
    health += 30; //some value
}

void Player::useManaPotion(){
    mana += 30;
}

void Player::update(){
    Pawn::update();
    if(health <= 0) alive = false;
}