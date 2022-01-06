#pragma once
#include <iostream>

class Vec2D {
public:
	static const Vec2D Zero;

	Vec2D(): Vec2D(0,0) {}
	Vec2D(float x, float y): mX(x),mY(y){}

	inline void setX(float x) {mX = x;}
	inline void setY(float y) {mY = y;}
	inline float getX() const {return mX;}
	inline float getY() const {return mY;}

	friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);

	bool operator==(const Vec2D& vec2) const;
	bool operator!=(const Vec2D& vec2) const;

	Vec2D operator-() const;
	Vec2D operator*(float scale) const;
	Vec2D operator/(float scale) const;
	Vec2D& operator*=(float scale);
	Vec2D& operator/=(float scale);
	Vec2D operator+(const Vec2D& vec) const;
	Vec2D operator-(const Vec2D& vec) const;
	Vec2D& operator+=(const Vec2D& vec);
	Vec2D& operator-=(const Vec2D& vec);

	float mag2() const;
	float mag() const;

	Vec2D getUnitVec() const;
	Vec2D& normalize();

	float distance(const Vec2D& vec) const;
	float dot(const Vec2D& vec) const;
	Vec2D projectOnto(const Vec2D& vec) const;
	float angleBetween(const Vec2D& vec) const;
	Vec2D reflect(const Vec2D& normal) const;

	friend Vec2D operator*(float scale, const Vec2D& vec);

private:
	float mX,mY;
};

