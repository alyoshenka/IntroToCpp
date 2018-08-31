#include <iostream>
#include <stdlib.h>
#include <time.h>

// To DO
// clean up and comment

// Populate array with val
void initArr(int * arr, int s, int val) {
	for (int i = 0; i < s; i++) {
		arr[i] = val;
	}
}

// Print Array
void printArr(int arr[], int s) {
	for (int i = 0; i < s; i++) {
		std::cout << arr[i] << std::endl;
	}
}

// Return Zero Array
int* zeroArray(size_t s) { // int s
	int* arr = new int[s];
	for (int i = 0; i < s; i++) {
		arr[i] = 0;
	}
	return arr;
}

// Duplicate That Array
int *duplicateArray(int *origArr, int s) {
	int * arr = new int[s];
	for (int i = 0; i < s; i++) {
		arr[i] = origArr[i];
	}
	return arr;
}

// I Love Numbers
void faveNums() {
	int num = 0;
	std::cout << "How many numbers would you like to put in?" 
		<< std::endl;
	int s = 0;
	std::cin >> s;
	int * arr = new int[s];
	for(int i = 0; i < s; i++){
		std::cout << "Number " << i + 1 << ": ";
		std::cin >> num;
		arr[i] = num;
	}
	std::cout << "Your numbers are: " << std::endl;
	printArr(arr, s);
	delete[] arr; // do here????
}

// Player Randomizer Generator

struct Item {
	int idNum;
	int gold;
};

struct Player {
	int attackPoints;
	int defensePoints;
	int experiencePoints;
	Item inventory[10]; // max 10 items
};


Player * randomPlayers(int count) {
	// initialize random seed
	srand(time(NULL));

	Player* arr = new Player[count];

	for (int i = 0; i < count; i++) {
		int attackPoints = rand() % 11 + 15; // 15 - 25
		int defensePoints = rand() % 20 + 11; // 15 - 30
		int experiencePoints = rand() % 51 + 50; // 50 - 100
		arr[i].attackPoints = attackPoints;
		arr[i].defensePoints = defensePoints;
		arr[i].experiencePoints = experiencePoints;
		for (int j = 0; j < 10; j++) {
			arr[i].inventory[j].idNum = -1;
		}
	}
	return arr;
}

void printPlayers(Player * arr, int s) {
	for (int i = 0; i < s; i++) {
		std::cout << "Player " << i + 1 << std::endl;
		std::cout << "Attack Points: " << arr[i].attackPoints << std::endl;
		std::cout << "Defense Points: " << arr[i].defensePoints << std::endl;
		std::cout << "Experience Points: " << arr[i].experiencePoints << std::endl;
		// Inventory
		for(int j = 0; j < 10; j++) {
			if (arr[i].inventory[j].idNum > -1) {
				std::cout << "ID: " << arr[i].inventory[j].idNum <<
					" Gold: " << arr[i].inventory[j].gold << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

bool addItem(Player * recipient, Item gift) {
	int itemCount = 0;
	for (int i = 0; i < 10; i++) {
		if (recipient->inventory[i].idNum > -1) {
			itemCount++;
		}
	}
	if (itemCount >= 10) {
		std::cout << "They already have 10 items. Sorry bud." << std::endl;
		return false;
	}
	else {
		// find idx to place item
		int idx = 0;
		for (int i = 0; i < 10; i++) {
			if (recipient->inventory[i].idNum > -1) {
				idx = i;
			}
		}
		recipient->inventory[idx] = gift;
	}
	return true;
}

bool hasItem(Player *holder, int itemID) {
	int i = 0;
	while (holder->inventory[i].idNum != itemID) {
		i++;
		if (i >= 10) {
			return false;
		}
	}
	return true;
}

int totalVal(Player * holder) {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		if (holder->inventory[i].idNum > -1) {
			sum += holder->inventory[i].gold;
		}
	}
	return sum;
}

// FINISH
void numbers() {
	int length = 1;
	int num = -1;
	int * numbers = new int[1];
	std::cout << "Give me a number! (0 to stop)" << std::endl;
	std::cin >> num;
	while (num != 0) {
		int * temp = duplicateArray(numbers, length);
		temp[length - 1] = num;
		* numbers = * temp;	
		std::cout << "Num: " << &numbers << std::endl;
		std::cout << "Temp: " << &temp << std::endl;
		length++;
		std::cout << "Give me a number! (0 to stop)" << std::endl;
		std::cin >> num;

		delete[] temp;
	}
	std::cout << "You gave me:" << std::endl;
	printArr(numbers, length);
}

int main() {

	// single object on heap
	int * age = new int(0);

	// single array on heap
	int * ages = new int[10];

	// pass heap instantiated object to function
	initArr(ages, 10, *age);

	// Closed
	/*
	int * arr1 = zeroArray(5);
	printArr(arr1, 5);

	int nums[] = { 1, 2, 3, 4 };
	int *arr2 = duplicateArray(nums, 4);
	printArr(arr2, 4);
	

	// Open
	faveNums();

	Player * arr3 = randomPlayers(5);
	printPlayers(arr3, 5);
	Item present = { 1, 10 };
	addItem(&arr3[1], present);
	printPlayers(arr3, 5);
	std::cout << hasItem(&arr3[1], 1) << std::endl;
	int money = totalVal(&arr3[1]);
	int money2 = totalVal(&arr3[0]);
	std::cout << money << std::endl;
	std::cout << money2 << std::endl;
	*/

	// Challenge
	numbers();

	// Delete everything
	delete age;
	delete[] ages;
	// delete[] arr1;
	// delete[] arr2;
	// delete[] arr3;

	system("pause");
	return 0;
}