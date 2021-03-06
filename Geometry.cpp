#include "Geometry.h"

Vector2::Vector2() : x(0.0f), y(0.0f) {};

Vector2::Vector2(float x, float y) : x(x), y(y) {};

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 Vector2::operator*(const float other)
{
	return Vector2(x*other, y*other);
}