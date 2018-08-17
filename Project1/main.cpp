#include <iostream>;


int main() {


	// Evaluate
	// A) 30
	int numberA = 15;
	if (numberA > 10)
	{
		numberA = numberA * 2;
	}
	std::cout << "A) " << numberA << std::endl;

	//B) 15
	int numberB = 15;
	if (numberB < 15)
	{
		numberB = numberB * 3;
	}
	std::cout << "B) " << numberB << std::endl;

	// Number Judging
	std::cout << "Enter a number between 1 and 100:" << std::endl;
	int num = 0;
	std::cin >> num;
	// input validation
	while (num > 100 || num < 1) {
		std::cout << "Bad input." << std::endl;
		std::cout << "Enter a number between 1 and 100:" << std::endl;
		std::cin >> num;
	}
	std::cout << num;
	if (num > 50) {
		std::cout << " is a large number." << std::endl;
	}
	else if (num == 50) {
		std::cout << " is a balanced number." << std::endl;
	}
	else {
		std::cout << " is a small number." << std::endl;
	}


	system("pause");
	return 0;
}