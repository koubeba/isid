#include "Vec2D.h"

Vec2D::Vec2D() {
	x = 0;
	y = 0;
}

Vec2D::Vec2D(int _x, int _y) {
	x = _x;
	y = _y;
}

Vec2D Vec2D::operator+(Vec2D other) {
	return Vec2D(this->x + other.x, this->y + other.y);
}

Vec2D Vec2D::operator%(Vec2D other) {
	return Vec2D(this->x % other.x, this->y % other.y);
}
