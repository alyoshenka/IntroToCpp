#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <string>


int program1() {
	/*std::cout << "Provide two numbers and you will be given the sum." << std::endl;

	int numA = -1;
	int numB = -1;
	std::cin >> numA >> numB;

	std::cout << "The sum of the two numbers is << (numA + numB) << "." << std::endl;

	return 0*/

	// Problems:
	// 1) no closing quotation ( " ) after "is"
	// 2) no ; after "return 0"

	std::cout << "Provide two numbers and you will be given the sum." << std::endl; // 1

	int numA = -1;
	int numB = -1;
	std::cin >> numA >> numB;

	std::cout << "The sum of the two numbers is " << (numA + numB) << "." << std::endl;

	return 0; // 2
}

int program2() {
	/*std::cout << "-=xXx FOUR FUNCTION CALCULATOR PUNCH xXx=-" << std::endl;

	std::cout << "What are your two numbers?" << std::endl;

	double numA = -1.0;
	double numB = -1.0;
	double result = -1.0;

	std::cin >> numA >> numB;

	std::cout << "What operation would you like to perform? (+, -, /, *)" << std::endl;

	char operation = ' ';
	std::cin >> operation;

	switch (operation)
	{
	case '+':
		result = numA + numB;
	case '-':
		result = numA + numB;
	case '/':
		result = numA + numB;
	case '*':
		result = numA + numB;
	default:
		std::cout << "Sorry, that isn't a recognized operation." << std::endl;
	}

	std::cout << "Your final result was << result << std::endl;

		return 0;*/

	// Problems
	// 1) no " after "was"
	// 2) no break after switch statements
	// 3) numerical operations are all +
	// 4) says "result = -1" even if bad input
	// 5) no number input validation

	std::cout << "-=xXx FOUR FUNCTION CALCULATOR PUNCH xXx=-" << std::endl;

	std::cout << "What are your two numbers?" << std::endl;

	double numA = -1.0;
	double numB = -1.0;
	double result = -1.0;

	std::cin >> numA >> numB; // 5

	std::cout << "What operation would you like to perform? (+, -, /, *)" << std::endl;

	char operation = ' ';
	std::cin >> operation; 

	switch (operation)
	{
	case '+':
		result = numA + numB; 
		break; // 2
	case '-':
		result = numA - numB; // 3
		break; // 2
	case '/':
		result = numA / numB; // 3
		break; // 2
	case '*':
		result = numA * numB; // 3
		break; // 2
	default:
		std::cout << "Sorry, that isn't a recognized operation." << std::endl;
		return 0; // 4
	}

	std::cout << "Your final result was " << result << std::endl; // 1

	return 0;
}

int program3() {

	// time.h needs to be included
	
	srand(time(NULL)); // random time seed is not initialized

	std::string names[10] =
	{
		"Terry Nguyen",
		"Johnny Collins",
		"Taerrance Tooker",
		"Kristen Uguudesu",
		"Nisha Williera",
		"Davin Jobbson",
		"Michael Pascal",
		"Jamison Cardigan",
		"Charles Hernia",
		"Reggie Grawcannon"
	};

	size_t index = rand() % 10;

	std::cout << "Your random name is " << names[index] << std::endl; // space after is for clarity

	return 0;
}

bool containsValue(int value, int * arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++) // doesn't increment i
	{
		if (arr[i] == value)
		{
			return true;
		}
	}

	return false;
}

int program4() {
	int nums[] = { 0, 5, 7, 1, 2, 3 };

	bool result = containsValue(-1, nums, 6);
	std::string isFound = ""; // include string
	isFound = result ? "found" : "not found";

	// cannot be used like this because it needs an enumerator
	// std::cout << "The value was " << result ? "found" : "not found" << "!" << std::endl; 
	std::cout << "The value was " << isFound << "!" << std::endl;

	// system("pause"); // no pause to see output

	return 0;
}

int main() {

	// program1();
	// program2();
	// program3();
	// program4();

	system("pause");
	return 0;
}