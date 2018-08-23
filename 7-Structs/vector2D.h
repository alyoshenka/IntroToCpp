#pragma once

struct vector2 {
	float x;
	float y;
};

// returns sum of two vectors
vector2 vecSum(vector2 v1, vector2 v2);

// returns difference between two vecors
vector2 vecDif(vector2 v1, vector2 v2);

// returns difference between two vectors
float vecDist(vector2 v1, vector2 v2);

