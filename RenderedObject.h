#ifndef RENDEREDOBJECT_H
#define RENDEREDOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "GridMap.h"

// a rendered object is a game object that has its sprite

class RenderedObject {
	// this is the position in GRID COORDS: (not window coords. They need to be ultiplied by grid size in order to be rendered!)
	Vec2D position;
protected:
	sf::Sprite* sprite;
public:
	RenderedObject();
	RenderedObject(sf::Sprite* sprite);
	void render(sf::RenderWindow& window);
	// the position is in GRID COORDINATES!!!
	void setPosition(Vec2D _position);
	Vec2D getPosition();

	void setTextureRect(int, int, int, int);
	sf::IntRect getTextureRect();
};

#endif
