#include "Vec2.h"

Vec2 Vec2::Zero(0.0f, 0.0f);
Vec2 Vec2::One(1.0f, 1.0f);
Vec2 Vec2::UnitX(1.0f, 0.0f);
Vec2 Vec2::UnitY(0.0f, 1.0f);

Vec2::Vec2(void) : x(0), y(0) {

}

Vec2::Vec2(float xArg, float yArg) : x(xArg), y(yArg) {

}

Vec2::Vec2(float value) : x(value), y(value) {

}

Vec2::Vec2(const Vec2i &copy) : x(copy.x), y(copy.y) {

}

float Vec2::Length(void) {
	return sqrt(LengthSquared());
}

float Vec2::LengthSquared(void) {
	return (x * x) + (y + y);
}

// Static.
float Vec2::Distance(const Vec2& value1, const Vec2& value2) {
	return Vec2(value1 - value2).Length();
}


// Overload some operators..
bool Vec2::operator==(const Vec2& v) const {
	return x == v.x && y == v.y;
}

bool Vec2::operator!=(const Vec2& v) const {
	return !(*this == v);
}

Vec2 Vec2::operator-(void) const {
	return Vec2::Zero - *this;
}

Vec2 Vec2::operator-(const Vec2& v) const {
	return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator+(const Vec2& v) const {
	return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator/(float divider) const {
	return Vec2(x / divider, y / divider);
}

Vec2 Vec2::operator*(float scaleFactor) const {
	return Vec2(x * scaleFactor, y * scaleFactor);
}

Vec2& Vec2::operator+=(const Vec2& v) {
	x += v.x, y += v.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& v) {
	x -= v.x, y -= v.y;
	return *this;
}

Vec2& Vec2::operator*=(float scaleFactor) {
	x *= scaleFactor, y *= scaleFactor;
	return *this;
}

Vec2& Vec2::operator/=(float scaleFactor) {
	x /= scaleFactor, y /= scaleFactor;
	return *this;
}
