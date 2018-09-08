#include "Person.h"

string Person::getName() {
	return name;
}

int Person::getNumber() {
	return phoneNumber;
}

void Person::changeName(string newName) {
	name = newName;
}

void Person::changeNumber(int newNumber) {
	phoneNumber = newNumber;
}



