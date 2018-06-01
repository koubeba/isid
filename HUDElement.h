#ifndef __HUDELEMENT_H__
#define __HUDELEMENT_H__

#include <SFML/Graphics.hpp>
#include "RenderedObject.h"
#include "Vec2D.h"
#include "SFML/System/Vector2.hpp"

class HUDElement : public RenderedObject{
public:
    HUDElement();
    HUDElement(sf::Sprite* _sprite);
    void render(sf::RenderWindow& window);
    void setPosition(int x, int y); //The position here is in PIXELS, not grid coordinates
    Vec2D getPosition();
};

#endif