#pragma once
#include <string>
using std::string;

class Person {
public:
	string getName();
	int getNumber();
	void changeName(string newName);
	void changeNumber(int newNumber);

private:
	string name;
	int phoneNumber;
};

