#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

// appends one c-string to the end of another c-string
void appendCString(char origCString[], char newCString[], int origLength, int newLength);

// inserts the contents of a c-string at an arbitrary location in another c-string
void insertCString(char origCString[], char newCString[], int origLength, int idx);

// returns the number of words in the string.
int wordCount(string s);

// prints a string with line breaks every 80 characters
void hardBreak(string s);
