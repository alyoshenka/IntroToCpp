#pragma once
#include <string>
#include "Person.h"
using std::string;
using std::cout;
using std::endl;
using std::cin;

// opens address book program
void openAddressBook();

// takes the input for what to do
string takeInput();

// returns whether given string array contains given string
bool contains(string arr[], string s, int length);

// prints the options for what to do
void printOptions();

// adds Person to address book
void add(Person addressBook[], Person p);