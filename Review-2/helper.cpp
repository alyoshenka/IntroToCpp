#include <iostream>
#include "helper.h"

// opens address book program
void openAddressBook() {
	cout << "Welcome to your address book" << endl;

	Person addressBook[50];

	string choice = "";
	choice = takeInput();

	// while they don't want to exit
	while (choice != "x") {
		// switch doesn't work with strings :(
		if (choice == "a") {
			// add
		}
		else if (choice == "rm -name") {
			// rm by name
		}
		else if (choice == "rm -number") {
			// rm by number
		}
		else if (choice == "p") {
			// print
		}
		else {
			// error
			cout << "Something went wrong" << endl;
		}

	}

	// exit
	cout << "Goodbye" << endl;
	return;
}

// takes the input for what to do
string takeInput() {

	string choice = "";
	printOptions();
	string acceptableValues[] = {"a", "r -name", "r -number", "p", "x"};

	cin >> choice;
	// while choice not in acceptableValues
	while ( ! contains(acceptableValues, choice, 5)) {
		// clear cin
		cin.clear();
		cin.ignore(100, '\n');

		// get new input
		cout << "I don't understand what you said" << endl;
		printOptions();
		cin >> choice;
	}

	return choice;
}

// prints the options for what to do
void printOptions() {
	cout << "What would you like to do?" << endl;
	cout << "a - Add a contact" << endl;
	cout << "r -name - Remove a contact by name" << endl;
	cout << "r -number - Remove a contact by phone number" << endl;
	cout << "p - Print your entiire address book" << endl;
	cout << "x - Exit your address book" << endl;
}

// returns whether given string array contains given string
bool contains(string arr[], string s, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == s) {
			return true;
		}
	}
	// else
	return false;
}

// adds Person to address book
void add(Person addressBook[], Person p) {

}
