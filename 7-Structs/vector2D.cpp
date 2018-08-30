#include <iostream>
#include "vector2D.h"
#include "math.h"


// returns sum of two vectors
vector2 vecSum(vector2 v1, vector2 v2) {
	vector2 vecSum = {};
	vecSum.x += v1.x + v2.x;
	vecSum.y += v1.y + v2.y;
	return vecSum;
}

// returns difference between two vectors
vector2 vecDif(vector2 v1, vector2 v2) {
	vector2 vecDif = {};
	vecDif.x = v2.x - v1.x;
	vecDif.y = v2.y - v1.y;
	return vecDif;
}

// returns difference between two vectors
float vecDist(vector2 v1, vector2 v2) {
	float vecDist = 0.0f;
	vecDist = sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y));
	return vecDist;
}