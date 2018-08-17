#include <iostream>;


int main() {

	int num = 0;
	/*

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

	// Age Gate
	std::cout << "How old are you?" << std::endl;
	int age = 0;
	std::cin >> age;
	if (age < 18) {
		std::cout << "You are a minor." << std::endl;
	}
	else {
		std::cout << "You are an adult." << std::endl;
	}
	if (age >= 50) {
		std::cout << "You are eligible to join AARP." << std::endl;
	}
	if (age >= 65) {
		std::cout << "You are eligible for retirement benefits." << std::endl;
	}

	// Smallest of 3
	int i = 0;
	int small = INT_MAX;
	num = 0;
	std::cout << "Input a number:" << std::endl;
	for (i = 0; i < 3; i++) {
		std::cout << "Number " << i + 1 << ":" << std::endl;
		std::cin >> num;
		if (num < small) {
			small = num;
		}
	}
	std::cout << small << " was the smallest." << std::endl;

	// Open
	// Even or Odd
	std::cout << "Enter a whole number:" << std::endl;
	std::cin >> num;
	if (num % 2 == 0) {
		std::cout << "even" << std::endl;
	}
	else {
		std::cout << "odd" << std::endl;
	}

	// Clamp the Num
	std::cout << "Enter a value 15 - 30 (<15 or >30 to clamp):" << std::endl;
	std::cin >> num;
	std::cout << "Clamped number: ";
	if (num > 30) {
		num = 30;
	}
	if (num < 50) {
		num = 15;
	}
	std::cout << num << std::endl;
	

	// Eval
	// Field:       Purchase Order for Cookies
	int cookies = 0;
	// Constraints: Must be ordered in multiples of 23. Only whole numbers.
	std::cout << "You must order in multiples of 23." << std::endl;
	std::cout << "How many cookies would you like?" << std::endl;
	std::cin >> cookies;
	//              Round down to the nearest multiple if not a multiple of 23.
	if(cookies % 23 != 0){
		int sub = 0;
		sub = cookies % 23;
		cookies -= sub;
		if (cookies % 23 != 0) {
			std::cout << "Error" << std::endl;
		}
	}
	//              If nearest multiple is zero, provide an error message.
	if (cookies == 0) {
		std::cout << "Error: you needed to buy more cookies." << std::endl;
	}
	else {
		std::cout << "You ordered " << cookies << " cookies." << std::endl;
	}


	// Field:       Purchase Order for Sketchbooks (3pk)
	int books = 0;
	std::cout << "How many sketchbooks would you like?" << std::endl;
	// Constraints: Must order at least 9 sketchbooks total.
	//              The total may not exceed 30 sketchbooks ordered.
	std::cout << "You must order at least 9 and no more athn 30 sketchbooks." << std::endl;
	std::cin >> books;
	//              If the total number of sketchbooks ordered does not meet
	//              the minimum order count or exceeds the maximum order count,
	//              provide an error message.
	if (books < 9 || books > 30) {
		std::cout << "Error: bad value, sorry." << std::endl;
	}
	else {
		std::cout << "You ordered " << books << " sketchbooks." << std::endl;
	}

	// Field:       Enable Motion Blur
	char motion = 'a';
	std::cout << "Enable motion blur? (y or n)" << std::endl;
	std::cin >> motion;
	// Constraints: Must be a 'y' or 'n' value.
	if (motion == 'y') {
		std::cout << "Motion blur enabled." << std::endl;
	}
	else if (motion == 'n') {
		std::cout << "Motion blur disabled." << std::endl;
	}
	//              Provide an error message if any other value.
	else {
	std::cout << "Error: bad value." << std::endl;
	}

	// Four Function Disposable Calculator
	int num1 = 0;
	int num2 = 0;
	char oper = '+';
	std::cout << "Enter two ingegers and an operator:" << std::endl;
	std::cout << "Num 1: ";
	std::cin >> num1;
	std::cout << "Num 2: ";
	std::cin >> num2;
	std::cout << "Operator: ";
	std::cin >> oper;
	// std::cout << std::endl;
	switch (oper) {
		case 43: 
			num = num1 + num2;
			break;
		case 45: 
			num = num1 - num2;
			break;
		case 42: 
			num = num1 * num2;
			break;
		case 47: 
			if (num2 == 0) {
				std::cout << "Cannot divide by 0." << std::endl;
			}
			else {
				num = num1 / num2;
			}
			break;
		default:
			std::cout << "Error" << std::endl;
			break;
	}
	if (num2 != 0) {
		std::cout << num1 << oper << num2 << "=" << num << std::endl;
	}

	// A Battle of Prehistoric Proportions
	int dino = 0;
	int person = 0;
	// strength
	std::cout << "What is your strength?" << std::endl;
	int strength = 0;
	std::cin >> strength;
	if (strength > 4) {
		person++;
	}
	else if (strength < 4) {
		dino++;
	}
	std::cout << "Person: " << person << " Dino: " << dino << std::endl;
	//RPS
	char rps = 'a';
	std::cout << "Rock, paper, or scissors? (r, p, s)" << std::endl;
	std::cin >> rps;
	switch (rps) {
		case 'r':
			dino++;
			break;
		case 'p':
			// tie
			break;
		case 's':
			person++;
			break;
		default:
			std::cout << "You didn't play rock, paper, or scissors." << std::endl;
			break;
	}
	std::cout << "Person: " << person << " Dino: " << dino << std::endl;
	// battles
	std::cout << "How many battles have you fought?" << std::endl;
	int battles = 0;
	std::cin >> battles;
	if (strength > 2) {
		person++;
	}
	else if (strength < 2) {
		dino++;
	}
	std::cout << "Person: " << person << " Dino: " << dino << std::endl;
	// sleep
	char sleep = 'a';
	std::cout << "Did you get enough sleep last night? (y or n)" << std::endl;
	std::cin >> sleep;
	switch(sleep){
		case 'y':
			person++;
			break;
		case 'n':
			dino++;
			break;
		default:
			std::cout << "Obviously not." << std::endl;
			break;
	}
	std::cout << "Person: " << person << " Dino: " << dino << std::endl;
	// vit C
	std::cout << "How much vitamin C have you had today? (mg)" << std::endl;
	int vitC = 0;
	std::cin >> vitC;
	if (vitC >= 75) {
		person++;
	}
	else{
		dino++;
	}
	std::cout << "Person: " << person << " Dino: " << dino << std::endl;
	if (dino > person) {
		std::cout << "Dino wins." << std::endl;
	}
	else if (person > dino) {
		std::cout << "Person wins." << std::endl;
	}
	else {
		std::cout << "Tie. Sudden death question:" << std::endl;
		std::cout << "Type 'a' to win." << std::endl;
		char win = 'b';
		std::cin >> win;
		if (win == 'a') {
			std::cout << "Person wins." << std::endl;
		}
		else {
			std::cout << "Dino wins." << std::endl;
		}
	}
	*/

	// Challenge
	// Detecting Capitalization
	char letter = '+';
	// std::cout << "Input a letter:" << std::endl;


	system("pause");
	return 0;
}