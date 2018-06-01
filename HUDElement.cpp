#include "HUDElement.h"

HUDElement::HUDElement() {}

HUDElement::HUDElement(sf::Sprite* _sprite){
    sprite = _sprite;
} 

void HUDElement::render(sf::RenderWindow& window){
    window.draw(*sprite);
}

void HUDElement::setPosition(int x, int y){
    sprite->setPosition( sf::Vector2f(x, y) );
}

Vec2D HUDElement::getPosition(){
    return Vec2D( (int)sprite->getPosition().x, (int)sprite->getPosition().y );
}