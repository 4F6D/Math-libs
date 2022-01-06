#include <cmath>

#include "Utils.hpp"

//- Checking if two floats are equal
bool isEqual (float x, float y) {
	return fabsf(x - y) < EPSILON;
}

//- Checking if to floats are greater or equal
bool isGreaterThanOrEqual(float x, float y) {
	return x > y || isEqual(x,y);
}

//- Checking if to floats are less or equal
bool isLessThanOrEqual(float x, float y) {
	return x < y || isEqual(x,y);
}