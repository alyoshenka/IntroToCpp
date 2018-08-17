// math_utils.cpp
#include "math_utils.h"
#include <iostream>
#include <cmath>

int sum(int a, int b) {
	return a + b;
}

float sum(float a, float b) {
	return a + b;
}

// closed
void func1(float a, float b) {
	std::cout << a << ", " << b << std::endl;
}

int sumOfThree(int a, int b, int c) {
	return a + b + c;
}

//open
float returnMin(float a, float b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

float returnMax(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

float clamp(float min, float max, float num) {
	if (num < min) {
		return min;
	}
	else if (num > max) {
		return max;
	}
	else {
		return num;
	}
}

float dist(float x1, float y1, float x2, float y2) {
	return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float eta(int x1, int y1, int x2, int y2, int speed) {
	return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) / speed;
}

float linInt(int a, int b, float c) {
	int dif = b - a;
	return a + dif * c;
}

float clamp2(float min, float max, float num) {

}

int hiLo() {

}

void upLo() {

}

