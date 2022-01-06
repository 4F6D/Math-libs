#include <cmath>
#include <cassert>

#include "Vec2D.hpp"
#include "Utils.hpp"

const Vec2D Vec2D::Zero;

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec) {
	consoleOut << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
	return consoleOut;
}

//- Overloading the equal operator
bool Vec2D::operator==(const Vec2D& vec2) const {
	return isEqual(mX, vec2.mX) && (mY, vec2.mY);
}

//- Overloading the not equal operator
bool Vec2D::operator!=(const Vec2D& vec2) const {
	return !(*this == vec2);
}

//- Overloading the unary negation operator
Vec2D Vec2D::operator-() const {
	return Vec2D(-mX,-mY);
}

//- Overloading times operator
Vec2D Vec2D::operator*(float scale) const {
	return Vec2D(mX * scale, mY * scale);
}

//- Overloading the divide operator
Vec2D Vec2D::operator/(float scale) const {
	assert(fabsf(scale) > EPSILON);
	return Vec2D(mX / scale, mY / scale);
}

//- Overloading the times-equals operator
Vec2D& Vec2D::operator*=(float scale) {
	*this = *this * scale;
	return *this;
}

//- Overloading the divide-equals operator
Vec2D& Vec2D::operator/=(float scale) {
	assert(fabsf(scale) > EPSILON);
	*this = *this / scale;
	return *this;
}

Vec2D operator*(float scale, const Vec2D& vec) {
	return vec * scale;
}

//- Overloading the addition operator
Vec2D Vec2D::operator+(const Vec2D& vec) const {
	return Vec2D(mX + vec.mX, mY + vec.mY);
}

Vec2D Vec2D::operator-(const Vec2D& vec) const {
	return Vec2D(mX - vec.mX, mY - vec.mY);
}

Vec2D& Vec2D::operator+=(const Vec2D& vec) {
	*this = *this + vec;
	return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& vec) {
	*this = *this - vec;
	return *this;
}

//- Calculating the magnitude of two vectors
float Vec2D::mag2() const {
	return dot(*this);
}

float Vec2D::mag() const {
	return sqrt(mag2());
}

//- Getting the unit vector
Vec2D Vec2D::getUnitVec() const {
	float magnitude = mag();

	if(magnitude > EPSILON) {return *this/magnitude;}
	return Vec2D::Zero;
}

//- normalizing the unit vector
Vec2D& Vec2D::normalize() {
	float magnitude = mag();

	if(magnitude > EPSILON) {return *this/=magnitude;}
	return *this;
}

//- Calculating the distance between two points
float Vec2D::distance(const Vec2D& vec) const {
	return(vec - *this).mag();
}

//- vector dot product multiplication
float Vec2D::dot(const Vec2D& vec) const {
	return (mX * vec.mX) + (mY * vec.mY);
}

Vec2D Vec2D::projectOnto(const Vec2D& vec) const {
	float mag2 = vec.mag();

	if(isLessThanOrEqual(mag2, EPSILON)) { return Vec2D::Zero; }

	float dot1 = dot(vec); 

	return vec * (dot1 / mag2);
}

float Vec2D::angleBetween(const Vec2D& vec) const {
	return acosf(getUnitVec().dot(vec.getUnitVec()));
}

Vec2D Vec2D::reflect(const Vec2D& normal) const {
	return *this - 2 * projectOnto(normal);
}