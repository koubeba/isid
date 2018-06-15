#include "Vec2D.h"

Vec2D::Vec2D() {
	x = 0;
	y = 0;
}

Vec2D::Vec2D(float _x, float _y) {
	x = _x;
	y = _y;
}

Vec2D Vec2D::operator+(Vec2D other) {
	return Vec2D(this->x + other.x, this->y + other.y);
}

Vec2D Vec2D::operator%(Vec2D other) {
	return Vec2D(int(this->x) % int(other.x), int(this->y) % int(other.y)); // hackssss
}

Vec2D Vec2D::operator*(Vec2D other) {
	return Vec2D(this->x*other.x, this->y*other.y);
}

Vec2D Vec2D::operator/(Vec2D other) {
	if (other.x != 0 || other.y != 0)
		return Vec2D(this->x/other.x, this->y/other.y);
	return other;
}

float distance(const Vec2D& a, const Vec2D& b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}