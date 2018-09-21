#include <iostream>
#include <string>
#include <fstream>
#define NOMINMAX
#include <windows.h>

#include "monsterQuest.h"

using std::endl;
using std::cout;
using std::cin;
using std::cerr;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::ios_base;
// using std::basic_string;

// ADD VALIDATION: !> 15 MONSTERS
// BUT ID > 15 IS OK

// This function displays a welcome message and maintains 
// the game loop
void monsterQuest() {
	int choice = -1;
	cout << "\nWelcome to Monster Quest!" << endl;
	choice = chooseAction();
	int ID = -1;
	int getID = 0;
	// int monsterCount = 0; // this doesn't work
	// while not exiting
	while (choice != 5) {
		ID = highestIDNumber();
		ID++;
		// go to other options
		switch (choice) {
		case 1:
			// if too many Monseters
			/*if (monsterCount >= 15) {
				cout << "Sorry, there is only room for 15 monsters int your bestiary!" << endl;
				break;
			}*/
			if (addMonster(ID)) {
				cout << "Monster added successfully!" << endl;
			}
			else {
				cout << "Sorry, there was an error adding your Monster." << endl;
			}
			break;
		case 2:
			if (ID <= 1) {
				cout << "There are no Monsters to remove!" << endl;
				break;
			}
			// INPUT VALIDATION
			getID = 0;
			cout << "What is the ID Number of the Monster you would like to delete?" << endl;
			cin >> getID;
			if (removeMonster(getID)) {
				cout << "Monster removed successfully!" << endl;
			}
			else {
				cout << "Sorry, there was an error removing your Monster" << endl;
			}
			// remove
			// monsterCount--;
			break;
		case 3:
			if (ID <= 1) {
				cout << "There are no Monsters to view!" << endl;
				break;
			}
			// INPUT VALIDATION
			getID = 0;
			cout << "What is the ID Number of the Monster you would like to view?" << endl;
			cin >> getID;
			viewMonster(ID);
			break;
		case 4:
			browseMonsters();
			break;
		default:
			// how tf
			cerr << "Error" << endl;
			return;
		}
		choice = chooseAction();
		ID++;
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

// This function adds a Monster by ID and returns whether
// it was added successfully
bool addMonster(int ID) {
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
		newMonster.idNumber = ID;
		// check
		cout << "Is this correct:" << endl;
		printMonster(newMonster);
		cout << "'y' for yes: ";
		cin >> check;
	} while (check != 'y');

	// add to file
	
	// open binary file in write mode
	string filePath = "bestiary/" + newMonster.species + ".bin";
	ofstream fout(filePath, ios::out | ios::binary);
	// verify file
	if (fout.fail()) {
		cerr << "Error" << endl;
		return false;
	}
	// write monster to file
	fout.write((char*)&newMonster, sizeof(Monster));
	// save and close
	fout.flush();
	fout.close();
	// open text file in append mode
	filePath = "bestiary/Monsters.txt";
	fstream file;
	file.open(filePath, ios_base::app);

	// verify file
	if (file.fail()) {
		cerr << "Error" << endl;
		return false;
	}
	// put in to file
	string total = newMonster.species + " " + std::to_string(ID);
	file << total << endl;

	// save and close
	file.flush();
	file.close();
	return true;
}

// This function removes a Monster by ID and returns whether
// it was removed successfully
bool removeMonster(int ID) {
	// add monsternames from txt file to array
	// open each individual file, check id
	// if match -> delete monster file and
	// delete from array
	// reprint txt file
	cout << "Removing Monster with ID " << ID << ":" << endl;
	string monsterSpeciesArray[15];
	string monsterSpecies;
	fstream file;
	// open text file
	file.open("bestiary/Monsters.txt", ios_base::in);
	// verify file
	if (file.fail()) {
		cout << "Error" << endl;
		return false;
	}
	// iterate through files
	int i = 0;
	while (std::getline(file, monsterSpecies)) {
		monsterSpeciesArray[i] = monsterSpecies;
		/*for (int i = 0; i < monsterSpecies.length(); i++) {
			if (monsterSpecies[i] == ' ') {
				monsterSpecies = monsterSpecies.substr(0, i - 1);
			}
		}*/
		i++;
	}
	// close
	file.close();

	// open each Monster file and examine ID
	ifstream fin;
	string filePath;
	Monster currentMonster;
	currentMonster.idNumber = 0;
	for(int j = 0; j < i; j++) {
		// get species name - ID number
		monsterSpecies = monsterSpeciesArray[j];
		for (int k = 0; k < monsterSpecies.length(); k++) {
			if (monsterSpecies[k] == ' ') {
				monsterSpecies = monsterSpecies.substr(0, k);
			}
		}
		filePath = "bestiary/" + monsterSpecies + ".bin";
		// open file
		fin.open(filePath, ios::in | ios::binary);
		// verify file
		if (fin.fail()) {
			cerr << "Error" << endl;
			return false;
		}
		// read Monster data
		fin.read((char*)&currentMonster, sizeof(Monster));
		// check ID
		if (currentMonster.idNumber == ID) {
			currentMonster.species = monsterSpecies;
			// break out of loop
			break;
		}
		// else continue
		fin.close();
	}
	// if Monster wasn't found
	if (currentMonster.idNumber == 0) {
		return false;
	}
	// delete Monster file
	string fileToDelete = "bestiary/" + currentMonster.species + ".bin";
	std::remove(fileToDelete.c_str());
	// verify file was deleted

	// DO I NEED THIS

	// delete Monster from array
	for (int j = 0; j < i; j++) {
		// if match
		// if it begins with the species
		if (monsterSpeciesArray[j].rfind(currentMonster.species) == 0) {
			// remove
			monsterSpeciesArray[j] = "0";
			break;
		}
	}
	// rewrite Monsters.txt
	// open in write mode
	file.open("bestiary/Monsters.txt", ios_base::out);
	// verify file
	if (file.fail()) {
		cout << "Error" << endl;
		return false;
	}
	// write contents of array back into file
	for (int j = 0; j < i; j++) {
		// if valid Monster name
		if (monsterSpecies != "0") {
			file << monsterSpeciesArray[j] << endl;
		}
	}
	// save and close
	file.flush();
	file.close();
	return true;
}

// This function displays a Monster by ID
void viewMonster(int ID) {
	// open main file
	// pass all monster species into array
	cout << "Viewing Monster with ID " << ID << ":" << endl;
	string monsterSpeciesArray[15];
	string monsterSpecies;
	fstream file;
	// open text file
	file.open("bestiary/Monsters.txt", ios_base::in);
	// verify file
	if (file.fail()) {
		cout << "Error" << endl;
		return;
	}
	// iterate through files
	int i = 0;
	while (std::getline(file, monsterSpecies)) {
		monsterSpeciesArray[i] = monsterSpecies;
		/*for (int i = 0; i < monsterSpecies.length(); i++) {
		if (monsterSpecies[i] == ' ') {
		monsterSpecies = monsterSpecies.substr(0, i - 1);
		}
		}*/
		i++;
	}
	// close
	file.close();

	// search through all monsters
	// if ids match printMonster()
	// open each Monster file and examine ID
	ifstream fin;
	string filePath;
	Monster currentMonster;
	currentMonster.idNumber = 0;
	for (int j = 0; j < i; j++) {
		// get species name - ID number
		monsterSpecies = monsterSpeciesArray[j];
		for (int k = 0; k < monsterSpecies.length(); k++) {
			if (monsterSpecies[k] == ' ') {
				monsterSpecies = monsterSpecies.substr(0, k);
			}
		}
		filePath = "bestiary/" + monsterSpecies + ".bin";
		// open file
		fin.open(filePath, ios::in | ios::binary);
		// verify file
		if (fin.fail()) {
			cerr << "Error" << endl;
			return;
		}
		// read Monster data
		fin.read((char*)&currentMonster, sizeof(Monster));
		// check ID
		if (currentMonster.idNumber == ID) {
			// break out of loop
			break;
		}
		// else continue
		fin.close();

		// print monster
		printMonster(currentMonster);
	}
}

// This function displays all Monsters in the bestiary directory
void browseMonsters() {
	string line;
	string monsterSpecies;
	string monsterID;
	fstream file;

	// open file
	file.open("bestiary/Monsters.txt", ios_base::out);
	// verify file
	if (file.fail()) {
		cerr << "Error" << endl;
		return;
	}

	// iterate through
	while (std::getline(file, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') {
				monsterSpecies = line.substr(0, i);
				monsterID = line.substr(i);
				break;
			}
		}
		cout << monsterID << endl;
		cout << monsterSpecies << endl;
		cout << endl;
	}

	// close file
	file.flush();
	file.close();
}

// This function returns the number of Monsters in the bestiary
int monsterCount() {
	fstream file;
	int monsterCount = 0;
	string data;
	// open text file
	file.open("bestiary/Monsters.txt", ios_base::in);
	// verify file
	if (file.fail()) {
		cout << "Error" << endl;
		return false;
	}
	// iterate through files
	int i = 0;
	while (std::getline(file, data)) {
		monsterCount++;
	}
	// close
	file.close();
	return monsterCount;
}

// This function returns the highest ID number of 
// the Monsters in the bestiary
int highestIDNumber() {

	string highestIDString = "";
	int highestID = 0;
	fstream file;
	string line;

	// create directory
	CreateDirectory("bestiary", NULL);

	// create file
	file.open("bestiary/Monsters.txt", ios_base::app);
	file.flush();
	file.close();

	// open file
	file.open("bestiary/Monsters.txt", ios_base::in);

	// verify file
	if (file.fail()) {
		cerr << "Error" << endl;
		return -1;
	}

	// iterate through file
	while (std::getline(file, line)) {
		// iterate through string
		for (int i = 0; i < line.length(); i++) {
			// when it hits a space
			if (line[i] == ' ') {
				// get everything after
				highestIDString = line.substr(i + 1);
				if(stoi(highestIDString) > highestID)
				highestID = stoi(highestIDString);
			}
		}
	}
	return highestID;
}