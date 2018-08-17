// main.cpp
#include <iostream>
#include "math_utils.h"
// #include <cmath> // for sqrt

int main() {

	int val = sum(5, 2);
	float fVal = sum(5.5f, 1.2f);

	func1(1, 2);
	std::cout << sumOfThree(1, 2, 3) << std::endl;
	std::cout << returnMin(9, 6) << std::endl;
	std::cout << returnMax(7, 10) << std::endl;
	std::cout << clamp(5, 10, 4) << std::endl;
	std::cout << dist(0, 0, 2, 5) << std::endl;
	std::cout << eta(0, 0, 0, 4, 2) << std::endl;
	std::cout << linInt(2, 4, 0.5) << std::endl;

	system("pause");
	return 0;
}



