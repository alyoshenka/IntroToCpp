#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "helper.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::ios_base;


// Digital Printer
void digitalPrinter() {

	string fileName;
	fstream file;

	char check = 'a';

	cout << "Would you like to look at a file?" << endl;

	cin >> check;

	while (check == 'y') {

		cout << "What is the relative file path to look at? (y or n)" << endl;
		cin >> fileName;

		file.open(fileName, ios_base::in | ios_base::_Nocreate);

		while (file.fail()) {
			cout << "File not found." << endl;
			cout << "What is the relative file path to look at?" << endl;
			cin >> fileName;
			file.open(fileName, ios_base::in | ios_base::_Nocreate);
		}

		string buffer;
		while (std::getline(file, buffer)) {
			cout << buffer << endl;
		}

		cout << "Would you like to look at another file? (y or n)" << endl;

		cin >> check;

	}
	cout << "Goodbye." << endl;
	file.flush();
	file.close();
}

// My Information
void myInformation() {

	fstream file;
	string fileName;
	string data = "";

	cout << "Where would you like to save your information?" <<
		" (.txt pls)" << endl;
	cin >> fileName;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	file.open(fileName, ios_base::out);

	if (file.fail()) {
		cout << "There was a problem, goodbye" << endl;
		return;
	}

	cout << "What is your name?" << endl;
	cin >> data;
	file << data << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "How old are you?" << endl;
	cin >> data;
	file << data << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "What is your favorite color?" << endl;
	cin >> data;
	file << data << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Thanks! Check your file for your results." << endl;
	file.flush();
	file.close();

}

// Text Corruption
void textCorruption() {
	fstream file;
	string fileName;

	cout << "File name: ";
	cin >> fileName;

	file.open(fileName, ios_base::in);

	if (file.fail()) {
		cout << "Error" << endl;
		return;
	}

	// print file char by char, randomly switching for blank character
	char c;
	int i = 0;

	srand(time(NULL));
	int blockNum = rand() % 15;

	cin >> std::noskipws;
	while (! file.eof()) {
		file.get(c);
		if (i == blockNum) {
			cout << (char)219;
			int blockNum = rand() % 15;
			i = 0;
		}
		else {
			cout << c;
		}
		i++;
	}
	file.close();
}

// Comma Separated Values
void commaToArray() {

	string arr[50];
	string val = "";
	char c = 'a';

	fstream file;
	string fileName;

	cout << "File name: ";
	cin >> fileName;
	file.open(fileName, ios_base::in);

	if (file.fail()) {
		cout << "Error" << endl;
		return;
	}

	int i = 0;
	while(i < 50 && !file.eof()){
		file.get(c);
		if (c == 44){
			arr[i] = val;
			val = "";
			i++;
		}
		else {
			val += c;
		}
	}

	// print array
	for (int idx = 0; idx < i; idx++) {
		cout << arr[idx] << endl;
	}

	file.close();
}

// Load Entity Data
void printEntity() {

	string fileName;
	fstream file;
	string data;

	cout << "File name: ";
	cin >> fileName;
	file.open(fileName, ios_base::in);
	if (file.fail()) {
		cout << "Error" << endl;
			return; 
	}

	int i = 0;

	while (std::getline(file, data)) {
		// if empty line
		if (data[0] == ' ') {
			continue;
		}
		// if entity name
		if (data[0] == '@') {
			i = 0;
		}
		switch (i) {
		case 1:
			cout << "Player: ";
			break;
		case 2:
			cout << "Hitpoints: ";
			break;
		case 3: 
			cout << "Armor: ";
			break;
		case 4:
			cout << "Strength: ";
			break;
		case 5:
			cout << "Defense: ";
			break;
		case 6:
			cout << "Agility: ";
			break;
		case 7:
			cout << "Luck: ";
			break;
		default:
			cout << endl;
		}
		cout << data << endl;
		i++;
	}

	file.close();
}

// Caeser's Messenger
void beCaesar() {
	int choice = 0;
	cout << "Load or save? (1, 2, other to exit)" << endl;
	cin >> choice;

	while (choice == 1 || choice == 2) {
		if (choice == 1) {
			loadMessage();
		}
		if (choice == 2) {
			saveMessage();
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Load or save? (1, 2, other to exit)" << endl;
		cin >> choice;
	}
}

// Load Message
void loadMessage() {
	fstream file;
	string fileName;
	char key = ' ';
	int offset = 0;
	char c = ' ';

	cout << "File path: ";
	cin >> fileName;

	// file validation
	file.open(fileName, ios_base::in);
	if (file.fail()) {
		cout << "You suck." << endl;
		return;
	}

	// key
	cout << "Input your key: ";
	cin >> key;
	// key to int offset
	// uppercase
	if (key >= 65 && key <= 90) {
		offset = key - 65;
		while (offset > 25) {
			offset -= 26;
		}
	}
	// lowercase
	else if (key >= 97 && key <= 122) {
		offset = key - 97;
		while (offset > 25) {
			offset -= 26;
		}
	}
	else {
		cout << "I dont't think so." << endl;
		return;
	}

	// print file
	while (!file.eof()) {
		file.get(c);
		// if letter
		if (c >= 65 && c <= 90 || c >= 97 && c <= 122) {
			cout << (char)(c - offset);
		}
		else {
			cout << c;
		}
	}
	cout << endl;
}

// Save Message
void saveMessage() {
	fstream file;
	string fileName;
	string message = "";
	char key = ' ';
	int offset = 0;

	cout << "Warning: This will delete all data from previous files" << endl;
	cout << "File path: ";
	cin >> fileName;

	// file validation
	file.open(fileName, ios_base::out);
	if (file.fail()) {
		cout << "You suck." << endl;
		return;
	}

	cout << "Write your message: (ENTER to submit)" << endl;
	cin >> message;

	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	cout << "Assign your key: (letter)" << endl;
	cin >> key;

	// input validation
	while (key < 65 && key > 90 || key < 97 && key > 122) {
		cout << "Bad input." << endl;
		cout << "Assign your key: (letter)" << endl;
		cin >> key;
	}
	
	// determine offset
	if (key >= 65 && key <= 90) {
		offset = key - 65;
		while (offset > 25) {
		offset -= 26;
		}
	}
	// lowercase
	else if (key >= 97 && key <= 122) {
		offset = key - 97;
		while (offset > 25) {
		offset -= 26;
		}
	}

	// offset by key
	for (int i = 0; i < message.size(); i++) {
		message[i] += offset;
	}

	file << message << endl;

	file.flush();
	file.close();
}