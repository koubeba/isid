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

void Player::update(TiledMap &map){
    Pawn::update();
	if (!moving) {
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
			setDirection(RIGHT);
			if( getPosition().x + 1 < GridMap::getSize().x && map.getTileType(getPosition().x + 1, getPosition().y) == FLOOR )
				move(RIGHT);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ){
			setDirection(LEFT);
			if( getPosition().x > 0 && map.getTileType(getPosition().x - 1, getPosition().y) == FLOOR )
				move(LEFT);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
			setDirection(UP);
			if( getPosition().y > 0 && map.getTileType(getPosition().x, getPosition().y - 1) == FLOOR )
				move(UP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
			setDirection(DOWN);
			if(getPosition().y + 1 < GridMap::getSize().y && map.getTileType(getPosition().x, getPosition().y + 1) == FLOOR )
				move(DOWN);
        }
    }
    
    if(health <= 0) alive = false;

    Item* pickup;
    while(pickup = map.getItem( getPosition() ) ){
        if(pickup != NULL) {
            equipment.push_back(pickup);
            map.removeItem( getPosition() );
        }    
    }
    
}