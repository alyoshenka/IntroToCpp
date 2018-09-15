#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::fstream;
using std::ios;
using std::ios_base;
using std::ofstream;
using std::ifstream;

#include "helper.h"

// write "Hello World" to file
bool writeHelloWorld(string filePath) {

	fstream file;

	// open file, appends if existing, creates if not
	file.open(filePath.c_str(), ios::out | ios::binary);

	// make sure file is ok
	if (file.fail()) {
		cerr << "Error" << endl;
		return false;
	}

	// else
	// reset error flags (such as EOF)
	file.clear();

	// move cursor to end of file for writing
	file.seekg(0, ios_base::end);

	// write to text file
	file << "Hello World\n";

	// flush outpus buffer
	file.flush();
	// close file
	file.close();
}

// save saveData to list
bool saveDataToList(string filePath, saveData saveDataArray[], int arrSize) {

	// open file in append mode
	ofstream fout(filePath.c_str(), ios::app | ios::binary);

	// verify file
	if (fout.fail()) {
		cerr << "Error" << endl;
		return false;
	}

	// fill in 
	for (int i = 0; i < arrSize; i++) {
		// write each struct value in array to the file
		fout.write((char*)&saveDataArray[i], sizeof(saveData));
	}
	fout.flush();
	fout.close();
}

// load saveData from disk
void readSaveDataFromFile(string filePath) {

	saveData mySaveData;
	ifstream fin;
	fin.open(filePath, ios::in | ios::binary);

	// verify file
	if (fin.fail()) {
		cerr << "Error" << endl;
		return;
	}

	// really read the stuff
	// while not EOF && next char != EOF
	while (! fin.eof() && fin.peek() != EOF) {
		// pass in saveData object
		fin.read((char*)&mySaveData, sizeof(saveData));
		// print it out
		cout << "Name: " << mySaveData.playerName << endl;
		cout << "Deaths: " << mySaveData.deathCount << endl;
		cout << "Deepest floor reached: " << mySaveData.deepestFloor << endl;
		if (mySaveData.hasBeatenGame) {
			cout << "They have beaten the game!" << endl;
		}
		else {
			cout << "They have not beaten the game." << endl;
		}
		cout << "Time played (s): " << mySaveData.timePlayed << endl;
		cout << endl;
	}
	fin.close();	
}

// MonsterQuest welcome
void monsterQuest() {

	// welcome
	cout << "Welcome to Monster Quest!" << endl;

	int choice = 0;
	choice = chooseAction();

	// while not exiting
	while (choice != 5) {
		// go to other options
		switch (choice) {
		case 1:
			addMonster();
			break;
		case 2:
			// remove
			break;
		case 3:
			viewMonster();
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
	}
	return;
}

// choose main menu action
// BETTER WHILE CONDITION
int chooseAction() {
	string choice = "";
	cout << "What would you like to do?" << endl;
	cout << "1) Add a monster by ID" << endl;
	cout << "2) Remove a monster by ID" << endl;
	cout << "3) View a monster by ID" << endl;
	cout << "4) Browse monsters" << endl;
	cout << "5) Exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	// validation
	// while not int or 1 - 5
	// THERE IS A BETTER WAY TO DO THIS I KNOW BUT ITS FRIDAY AFTERNOON
	// I'M TIRED I WANT TO GO HOME
	while (choice != "1" && choice != "2" && choice != "3" 
		&& choice != "4" && choice != "5") {

		cout << "I'm sorry, I don't understand what you mean." << endl;
		cout << "What would you like to do?" << endl;
		cout << "1) Add a monster by ID" << endl;
		cout << "2) Remove a monster by ID" << endl;
		cout << "3) View a monster by ID" << endl;
		cout << "4) Browse monsters" << endl;
		cout << "5) Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
	return stoi(choice);
}

// prints data from a given Monster
void printMonster(Monster myMonster) {
	cout << "Name: " << myMonster.name << endl;
	cout << "ID Number: " << myMonster.idNumber << endl;
	cout << "Species: " << myMonster.species << endl;
	cout << "Favorite Food: " << myMonster.favoriteFood << endl;
	cout << "Age: " << myMonster.age << endl;
}

// REDO THIS FUNCTION WHEN I UNDERSTAND HOW TO MAKE IT BETTER
// add a monster by ID
void addMonster() {

	Monster newMonster{};

	char check = 'a';

	// species validation
	while (check != 'y') {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Rules:" << endl;
		cout << "All lowercase" << endl;
		cout << "JUST species name, no file extenstion" << endl;
		cout << "What is the species of the monster you would like to add?" << endl;
		cout << "New species: ";
		cin.getline(newMonster.species, 50);
		cout << "Are you sure that " << newMonster.species << " is correct?" << endl;
		cout << "y for yes: ";
		cin >> check;
	}
	// name
	check = 'a';
	while (check != 'y') {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "What is the name of the monster you would like to add?" << endl;
		cout << "Name: ";
		cin.getline(newMonster.name, 50);
		cout << "Are you sure that " << newMonster.name << " is correct?" << endl;
		cout << "y for yes: ";
		cin >> check;
	}
	// favorite food
	check = 'a';	
	while (check != 'y') {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "What is " << newMonster.name << "'s favorite food?" << endl;
		cout << "Favorite food: ";
		cin.getline(newMonster.favoriteFood, 50);
		cout << "Are you sure that " << newMonster.favoriteFood << " is correct?" << endl;
		cout << "y for yes: ";
		cin >> check;
	}
	// age
	check = 'a';	
	while (check != 'y') {
		// CHECK IF INT
		int age;
		cout << "How old is " << newMonster.name << "?" << endl;
		cout << "Age: ";
		cin >> age;;
		cout << "Are you sure that " << newMonster.age << " is correct?" << endl;
		cout << "y for yes: ";
		cin >> check;
		newMonster.age = age;
	}

	
	// add to Monsters.txt
	fstream file;
	file.open("Monsters.txt", ios_base::app);

	// verify file
	if (file.fail()) {
		cerr << "Error" << endl;
		return;
	}
	file << newMonster.species << endl;

	file.flush();
	file.close();
	
	// count monsters
	file.open("Monsters.txt", ios_base::app);

	// verify file
	if (file.fail()) {
		cerr << "Error" << endl;
		return;
	}

	// ID = number of monsters + 1 (itself)
	string random;
	newMonster.idNumber = 0;
	while (std::getline(file, random)) {
		newMonster.idNumber++;
	}
	
	file.flush();
	file.close();

	printMonster(newMonster);

	// WHAT IF DUPLICATE???
	string fileName = newMonster.species;
	fileName += ".dat";
	ofstream fout;
	fout.open(fileName.c_str(), ios::out | ios::binary);

	// verify file
	if (fout.fail()) {
		cerr << "Error" << endl;
		return;
	}

	fout.write((char*)&newMonster, sizeof(Monster));

	fout.flush();
	fout.close();
	cout << "Yay! you have added a new monster!" << endl;
}

// NOT DONE YET
// removes monster by given ID
// rearranges files
void removeMonster() {

	// 1 - delete from monster list
	// 2 - delete monster.dat

	char check = 'a';
	int ID = 0;

	// input validation
	while (check != 'y') {
		cout << "What is the id number of the monster you would like to remove?" << endl;
		cout << "ID: ";
		cin >> ID;
		cout << "Are you sure " << ID << " is corrct?" << endl;
		cout << "( 'y' for yes )";
		cin >> check;
	}

	// iterate through main file, placing monster names into string
	// take away monster of given ID AND index 
		// are these different???
	// refill main file
	// delete monster.dat
	// NO

	// delete from monster list
	string monsters[10];
	fstream file;
	file.open("Monsters.txt", ios_base::in);
	string monsterName;
	// number of monsters listed
	int i = 0; 
	// populate with monster names
	while (getline(file, monsterName)) {
		monsters[i] = monsterName;
		i++;
	}
	// delete monster with ID number
	for (int idx = 0; idx < i; idx++) {
		// if
		// this might not work
		if (idx + 1 == ID) {
			monsters[idx] = "";
		}
	}
	// add remaining monsters back into file
	

	cout << "It is done." << endl;
}

// OVERLOAD THIS FUNCTION TO TAKE AN INT
// view a monster by ID
void viewMonster() {

	cout << "What is the ID of the monster you would like to view?" << endl;
	int ID = 0;
	cout << "ID: ";
	cin >> ID;

	// search through Monsters.txt
	// use the iteration number = id number for file name
	// to view monster from

	fstream file;
	file.open("Monsters.txt", ios_base::in);

	// verify file
	if (file.fail()) {
		cerr << "Error" << endl;
		return;
	}

	string monsterName = "";
	int i = 0;
	while (getline(file, monsterName)) {
		i++;
		if (i == ID) {
			break;
		}
	}
	// at this point, monsterName = name of monster - .dat

	file.clear();
	file.close();

	// if empty
	if (monsterName == "") {
		cout << "Sorry, no monsters here :(" << endl;
		return;
	}

	// open file using monsterName
	string fileName = monsterName + ".dat";
	ifstream fin;
	fin.open(fileName.c_str(), ios::in | ios::binary);

	// verify file
	if (fin.fail()) {
		cerr << "Error" << endl;
		return;
	}

	Monster myMonster;
	// pass Monster data in
	fin.read((char*)&myMonster, sizeof(Monster));

	fin.clear();
	fin.close();

	// print out data
	printMonster(myMonster);
}

// CHANGE TO BETTER IMPLEMENTATION
// browse all the monsters
void browseMonsters() {
	fstream file;
	file.open("Monsters.txt", ios_base::in);
	int ID = 1;
	string monsterName;
	while (getline(file, monsterName)) {
		cout << ID << " - " << monsterName << endl;
		ID++;
	}
	file.clear();
	file.close();
}
