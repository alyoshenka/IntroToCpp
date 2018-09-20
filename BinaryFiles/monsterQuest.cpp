#include <iostream>
#include <string>

#include "monsterQuest.h"

using std::endl;
using std::cout;
using std::cin;
using std::cerr;

// This function displays a welcome message and maintains 
// the game loop
void monsterQuest() {
	int choice = -1;
	cout << "\nWelcome to Monster Quest!" << endl;
	choice = chooseAction();
	// while not exiting
	while (choice != 5) {
		// go to other options
		switch (choice) {
		case 1:
			addMonster(001);
			break;
		case 2:
			// remove
			break;
		case 3:
			// viewMonster();
			break;
		case 4:
			// browseMonsters();
			break;
		default:
			// how tf
			cerr << "Error" << endl;
			return;
		}
		choice = chooseAction();
	}
	// exit
	cout << "Goodbye." << endl;
}

// function gets input from the user about
// what they would like to do
int chooseAction() {
	int choice = 0;
	cout << "\nWhat would you like to do?" << endl;
	cout << "1) Add a monster by ID" << endl;
	cout << "2) Remove a monster by ID" << endl;
	cout << "3) View a monster by ID" << endl;
	cout << "4) Browse monsters" << endl;
	cout << "5) Exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	// input validation
	while (cin.fail()|| choice < 1 || choice > 5) {
		// right place??
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nPlease enter a valid integer." << endl;
		cout << "What would you like to do?" << endl;
		cout << "1) Add a monster by ID" << endl;
		cout << "2) Remove a monster by ID" << endl;
		cout << "3) View a monster by ID" << endl;
		cout << "4) Browse monsters" << endl;
		cout << "5) Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
	return choice;
}

// This function prints data from a given Monster
void printMonster(Monster myMonster) {
	cout << "Name: " << myMonster.name << endl;
	cout << "ID Number: " << myMonster.idNumber << endl;
	cout << "Species: " << myMonster.species << endl;
	cout << "Favorite Food: " << myMonster.favoriteFood << endl;
	cout << "Age: " << myMonster.age << endl;
}

// This function adds a Monster by ID
void addMonster(int ID) {
	// input val
	char check = 'a';
	Monster newMonster{};
	string newMonsterSpecies;
	string newMonsterName;
	string newMonsterFavoriteFood;
	int newMonsterAge;
	cout << "Adding new Monster with ID " << ID << ":" << endl;
	// create Monster
	do {
		// clear cin
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// take all the details
		cout << "Give me some details for this Monster" << endl;
		cout << "What species is your Monster?" << endl;
		cout << "Species: ";
		getline(cin, newMonsterSpecies);
		cout << "What is the Monster's name?" << endl;
		cout << "Name: ";
		getline(cin, newMonsterName);
		cout << "What is " << newMonsterName << "'s favorite food?" << endl;
		cout << "Favorite food: ";
		getline(cin, newMonsterFavoriteFood);
		cout << "How old is " << newMonsterName << "?" << endl;
		cout << "Age: ";
		cin >> newMonsterAge;
		while (cin.fail() | newMonsterAge < 0) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid age." << endl;
			cout << "How old is " << newMonsterName << "?" << endl;
			cout << "Age: ";
			cin >> newMonsterAge;
		}
		// put it all into a monster
		newMonster.species = newMonsterSpecies;
		newMonster.name = newMonsterName;
		newMonster.favoriteFood = newMonsterFavoriteFood;
		newMonster.age = newMonsterAge;
		// check
		cout << "Is this correct:" << endl;
		printMonster(newMonster);
		cout << "'y' for yes: ";
		cin >> check;
	} while (check != 'y');
	// add to file

}

// This function removes a Monster by ID
void removeMonster(int ID) {

}

// This function displays a Monster by ID
void viewMonster(int ID) {

}

// This function displays all Monsters in the bestiary directory
void browseMonsters() {

}