#ifndef RENDEREDOBJECT_H
#define RENDEREDOBJECT_H

#include <SFML/Graphics.hpp>
#include "Vec2D.h"

// a rendered object is a game object that has its sprite

class RenderedObject {
	sf::Sprite* sprite;
	Vec2D position;
public:
	RenderedObject();
	RenderedObject(sf::Sprite* sprite);
	void render(sf::RenderWindow& window);	
	
	void setPosition(Vec2D _position);
	Vec2D getPosition();
};

#endif

