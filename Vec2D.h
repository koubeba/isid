#ifndef VEC2D_H
#define VEC2D_H

class Vec2D {
public:
	float x;
	float y;
	Vec2D();
	Vec2D(float x, float y);
	
	Vec2D operator+(Vec2D other);
	Vec2D operator%(Vec2D other);
	Vec2D operator*(Vec2D other);
	Vec2D operator/(Vec2D other);
};

#endif
