#include <iostream>
int main() {
	
	// 1
	int z = 1;
	std::cout << z << std::endl;
	z = 2;
	std::cout << z << std::endl;
	z = 3;
	std::cout << z << std::endl;

	// 2
	int a = 5;
	int b = 2;
	int c = a + b;
	std::cout << c << std::endl;
	a = 7.5f;
	b = 1.2f;
	c = a + b;
	std::cout << c << std::endl;

	// 3
	float d = 1.3f;
	float e = 4.9f;
	float f = d + e;
	std::cout << f << std::endl;
	d = 1;
	e = 4;
	f = d + e;
	std::cout << f << std::endl;

	// 4
	int userVal = -1;
	std::cout << "Input integer:" << std::endl;
	std::cin >> userVal;
	std::cout << "Value is: " << userVal << std::endl;

	// Final Form 
	// A) 14
	int numberA = 5;

	numberA = 9;
	numberA = 11;
	numberA = 14;

	std::cout << "A) " << numberA << std::endl;

	// B) 9
	int numberB = 10;
	numberB = 9;

	int thingB = 55;
	thingB = 22;

	std::cout << "B) " << numberB << std::endl;

	// C) 21
	int numberC = 3;
	numberC = 7;
	numberC = 1;
	int somethingC = 23;
	somethingC = 21;
	numberC = somethingC;
	std::cout << "C) " << numberC << std::endl;

	// D) 1
	int numberD = 1;
	int somethingD = 3;

	numberD = somethingD;

	std::cout << "D) " << somethingD << std::endl;

	// E) 6
	int x = 13;

	x = x / 2;

	std::cout << "E) " << x << std::endl;

	// F) 6.5
	float y = 13;

	y = y / 2;

	std::cout << "F)" << y << std::endl;
	// no space

	// C to F
	float degC = 78.0f;
	float degF = 0.0f;

	std::cout << "Input temp(C):" << std::endl;
	std::cin >> degC;

	degF = degC * 1.8 + 32;

	std::cout << "Celsius to Fahrenheit)" << std::endl;
	std::cout << "Celsius:   " << degC << std::endl;
	std::cout << "Fahrenheit:   " << degF << std::endl;
	
	// Area of Rect
	std::cout << "Area of Rectangle)" << std::endl;
	float rectW = 0.0f;
	float rectH = 0.0f;
	float rectA = 0.0f;
	rectA = rectW * rectH;
	std::cout << "Input width:" << std::endl;
	std::cin >> rectW;
	std::cout << "Input height: " << std::endl;
	std::cin >> rectH;
	rectA = rectW * rectH;
	std::cout << "H: " << rectH << " W: " << rectW << std::endl;
	std::cout << "Area: " << rectA << std::endl;

	// Average of 5
	float g, h, i, j, k;
	float avg;
	avg = g = h = i = j = k = 0.0f;
	
	std::cout << "Input float:" << std::endl;
	std::cin >> g;
	std::cout << "Input float:" << std::endl;
	std::cin >> h;
	std::cout << "Input float:" << std::endl;
	std::cin >> i;
	std::cout << "Input float:" << std::endl;
	std::cin >> j;
	std::cout << "Input float:" << std::endl;
	std::cin >> k;
	
	avg = (g + h + i + j + k) / 5;

	std::cout << "Average of Five)" << std::endl;
	std::cout << g << "," << h << "," << i << "," << j << "," << k << std::endl;
	std::cout << "avg: " << avg << std::endl;

	// Number Swap
	int m = 0;
	int n = 0;
	int swap = 0;

	std::cout << "Input integer:" << std::endl;
	std::cin >> m;
	std::cout << "Input integer:" << std::endl;
	std::cin >> n;

	std::cout << "Number Swap)" << std::endl;
	std::cout << "m is " << m << std::endl;
	std::cout << "n is " << n << std::endl;

	swap = m;
	m = n;
	n = swap;
	std::cout << "Swap" << m << std::endl;
	std::cout << "m is " << m << std::endl;
	std::cout << "n is " << n << std::endl;

	// Fun Age Facts
	int age = 0;
	std::cout << "Input age(integer):" << std::endl;
	std::cin >> age;
	int months = age * 12;
	std::cout << "You have been alive for " << months << " months!" << std::endl;
	if (age > 50) {
		std::cout << "You have beat the life expectancy for Sierra Leone!" << std::endl;
	}
	float scores = 0.0f;
	scores = age / 20;
	std::cout << "You have been alive for " << scores << " scores!" << std::endl;

	// Challenge

	// Conforming to Conventions
	// age
	// bullet_count
	// dog_years
	// qty
	// sheild_value
	// defense_matrix_cooldown
	// red_armor_value
	// red_armor_ratio
	// happiness
	// gandhi_aggression

	// Right Tool Right Job
	bool isTrue = true;
	double o = 9.5;
	char p = 1;
	short q = 2;
	long r = 3;

	// Num Swap (pt 2)
	int t = 0;
	int u = 1;

	std::cout << "Num1 = " << t << std::endl;
	std::cout << "Num2 = " << u << std::endl;
	std::cout << "Swap" <<  std::endl;

	// swap
	t = t + u;
	u = t - u;
	t = t - u;

	std::cout << "Num1 = " << t << std::endl;
	std::cout << "Num2 = " << u << std::endl;
	

	// Errors
	/*
	float s = 2.0f;
	std::cout << "Input  number:" << std::endl;
	bool isNum = false;
	std::cout << "0 = F: " << isNum << std::endl;
	std::cin >> s; // doesn't do anything if not a number
	std::cout << "s: " << s << std::endl;

	while (! isNum) {
		if (s >= 0 || s < 0) { // check if s is number
			isNum = true;
		} else {
			std::cout << "Not a number. Try Again." << std::endl;
			std::cout << "Input  number:" << std::endl;
			std::cin >> s;
		}
	}
	std::cout << "1 = T: " << isNum << std::endl;
	std::cout << "Your number is: " << s << std::endl;
	*/

	system("pause");
	return 0;
}