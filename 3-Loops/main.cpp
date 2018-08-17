#include <iostream>
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */
#include <stdio.h>      /* printf, scanf, puts, NULL */

// Open

// X to Y
void printXY(int min, int max) {
	std::cout << "Print Xy:" << std::endl;
	min = 0;
	max = 0;
	std::cout << "Input minimum:" << std::endl;
	std::cin >> min;
	std::cout << "Input maximum:" << std::endl;
	std::cin >> max;
	std::cout << min;
	for (int i = min + 1; i <= max; i++) {
		std::cout << ", " << i;
	}
	std::cout << std::endl;
}

// Largest Num
int promptLargest(int count) {
	std::cout << "Prompt Largest:" << std::endl;
	int largest = 0; // what is the better implementaation?
	// count = 0;
	int num = 0;
	// std::cout << "How many numbers would you like to list?" << std::endl;
	// std::cin >> count;
	for (int i = 0; i < count; i++) {
		std::cout << "Input your number:" << std::endl;
		std::cin >> num;
		if (i == 0) {
			largest = num;
		}
		if (num > largest) {
			largest = num;
		}
	}
	std::cout << "The largest number was: " << largest << std::endl;
	return largest;
}

// Smallest Num
int promptSmallest(int count) {
	std::cout << "Prompt Smallest:" << std::endl;
	int smallest = 0; // what is the better implementaation?
	// count = 0;
	int num = 0;
	// std::cout << "How many numbers would you like to list?" << std::endl;
	// std::cin >> count;
	for (int i = 0; i < count; i++) {
		std::cout << "Input your number:" << std::endl;
		std::cin >> num;
		if (i == 0) {
			smallest = num;
		}
		if (num < smallest) {
			smallest = num;
		}
	}
	std::cout << "The largest number was: " << smallest << std::endl;
	return smallest;
}

// Electric Boogaloo
void evenOrOdd(int start, int end) {
	int i = 0;
	for (i = start; i < end; i++) {
		if (i % 2 == 0) {
			std::cout << "Even";
		}
		else {
			std::cout << "Odd";
		}
		std::cout << ", ";
	}
	// fencepost
	i++;
	if (i % 2 == 0) {
		std::cout << "Even.";
	}
	else {
		std::cout << "Odd.";
	}
}

// Fizz Buzz
void fizzBuzz(int start, int end) {
	for (int i = start; i <= end; i++) {
		if (i % 3 == 0) {
			if (i % 5 == 0) {
				std::cout << "FizzBuzz";
			}
			else {
				std::cout << "Fizz";
			}
			
		}
		else if (i % 5 == 0){
			std::cout << "Buzz";
		}
		else {
			std::cout << i;
		}
		if (i == end) {
			std::cout << std::endl;
			break;
		}
			std::cout << ", ";
	}
}

// Grid Generator
void gridGen(int x, int y) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			std::cout << "X";
		}
		std::cout << std::endl;
	}
}

// Higher or Lower
void guessTheNumber(int lower, int upper, int tryCount) {
	int tryNum = 1;
	int guessNum = 0;
	int randNum = rand() % (upper - lower - 1) + lower;
	std::cout << "Rand num = " << randNum << std::endl; // test
	std::cout << "I am going to generat a random number between " 
		<< lower << " and " << upper << ". You have " << tryCount 
		<< " tries to guess it." << std::endl;
	while (tryNum <= tryCount) {
		std::cout << "Round " << tryNum << " - Make your guess" << std::endl;
		std::cin >> guessNum;
		if (guessNum == randNum) {
			std::cout << "Congrats, you guessed it!" << std::endl;
			break;
		}
		else if (guessNum > randNum) {
			std::cout << "Your guess is too high." << std::endl;
		}
		else {
			std::cout << "Your guess is too low." << std::endl;
		}
		tryNum++;
	}
}

// Fibonacci
void fibi(int end) {
	int i = 1;
	int j = 0;
	int temp = 0;
	while (i <= end) {
		std::cout << i << std::endl;
		temp = i;
		i = temp + j;
		j = temp;
	}
}

// A - Z ASCII
void aToZ() {
	int i = 0;
	for (i = 65; i <= 90; i++) {
		std::cout << (char)i << std::endl;
	}
}

// Aa to Zz ASCII
void AaToZz() {
	int i = 0;
	int j = 97;
	for (i = 65; i <= 90; i++) {
		std::cout << (char)i << (char)j<< std::endl;
		j++;
	}
}


int main() {
	// initialize random seed
	srand(time(NULL));

	// For 1 - 100
	std::cout << "For: 1 - 100" << std::endl;
	int i = 0;
	for (i = 1; i <= 100; i++) {
		std::cout << i << std::endl;
	}

	// While 100 - 1
	std::cout << "While 100 - 1" << std::endl;
	i = 100;
	while (i >= 1) {
		std::cout << i << std::endl;
		i--;
	}

	// Do 1995 - 2017
	std::cout << "Do 1995 - 2017" << std::endl;
	i = 1995;
	do {
		std::cout << i << std::endl;
		i++;
	} while (i <= 2017);

	// Three fave nums
	float arr[3];
	std::cout << "What are your three favorite numbers?" << std::endl;
	for (i = 0; i < 3; i++) {
		std::cout << "List one of them:" << std::endl;
		std::cin >> arr[i];
		std::cout << "You input: " << arr[i] << std::endl;
	}
	std::cout << "Your favorite numbers are " << arr[0] << ", " << arr[1] << ", and " << arr[2] << "." << std::endl;

	printXY(5, 10);
	promptLargest(3);
	promptSmallest(3);
	evenOrOdd(5, 10);
	fizzBuzz(13, 25);
	gridGen(2, 5);
	guessTheNumber(1, 10, 5);
	fibi(200);
	aToZ();
	AaToZz();

	system("pause"); // so we can see
	return 0;
}

