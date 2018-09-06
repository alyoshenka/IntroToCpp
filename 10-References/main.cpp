#include <iostream>

struct Aussiegochi {
	float happiness;
	float hunger;
	float thirst;
	float sanity;
};

void feedAussie(Aussiegochi& aus) {
	aus.hunger += 10;
}

void waterAussie(Aussiegochi& aus) {
	aus.thirst += 5;
}

void abuseAussie(Aussiegochi& aus) {
	aus.happiness -= 15;
}

void coddleAussie(Aussiegochi& aus) {
	aus.sanity += 10;
}

//Define a function that accepts three floating point numbers as 
//parameters.The first two parameters represent the two factors 
//of the multiplication operation, while the last one defines where 
//the product(i.e.the result of multiplying two numbers) will 
//be assigned to.
void product(float a, float b, float & prod) {
	prod = a * b;
}

// Define a function that accepts two float variables and swaps their values.
void swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

int main() {

	// Closed

	// Syntax for References
	int int1 = 10;
	int & intRef = int1;
	float float1 = 8.4f;
	float & floatRef = float1;
	bool bool1 = false;
	bool & boolRef = bool1;
	char char1 = 'h';
	char & charRef = char1;

	// Product of Two Floats
	float a = 0.5f;
	float b = 9.0f;
	float result = -1.0f;
	product(a, b, result);
	std::cout << result << std::endl;

	// Open

	// Swap
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	// Aussiegochi
	Aussiegochi aus = {80, 20, 25, 40};
	Aussiegochi &refToAus = aus;
	std::cout << aus.happiness << std::endl;
	std::cout << aus.hunger << std::endl;
	std::cout << aus.thirst << std::endl;
	std::cout << aus.sanity << std::endl;
	feedAussie(refToAus);
	waterAussie(refToAus);
	abuseAussie(refToAus);
	coddleAussie(refToAus);
	std::cout << aus.happiness << std::endl;
	std::cout << aus.hunger << std::endl;
	std::cout << aus.thirst << std::endl;
	std::cout << aus.sanity << std::endl;


	system("pause");
	return 0;
}