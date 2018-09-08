#include "assignmentHelper.h"

// Write a function that appends one c - string to the 
// end of another.You can assume that the c - string 
// that will contain the final result will have enough space.

// appends one c-string to the end of another c-string
void appendCString(char origCString[], char newCString[], int origLength, int newLength) {
	cout << "Append C-String" << endl;
	int idx = 0;
	for (int i = origLength - newLength; i < origLength; i++) {
		origCString[i] = newCString[idx];
		idx++;
	}
	cout << endl;
}

// inserts the contents of a c-string at an arbitrary location in another c-string
void insertCString(char origCString[], char newCString[], int origLength, int idx) {

	// placeholder for half of string after insertion
	char *secondHalf = new char[origLength];
	for (int i = idx; i < origLength; i++) {
		secondHalf[i - idx] = origCString[idx];
		idx++;
	}

	// test
	for (int i = 0; i < origLength; i++) {
		cout << secondHalf[i];
	}
	cout << endl;

	// put newCString into origCString
	for (int i = 0; i < origLength; i++) {
		origCString[idx] = newCString[i];
		idx++;
	}

	// add the second half back on to the end
	for (int i = 0; i < origLength; i++) {
		origCString[idx] = secondHalf[i];
		idx++;
	}

	// test
	for (int i = 0; i < origLength; i++) {
		cout << origCString[i];
	}
	cout << endl;

	// clean up
	delete[] secondHalf;
}

// returns the number of words in the string.
int wordCount(string s) {
	int count = 0;
	bool bigSpace = true;
	for (int i = 1; i < s.length(); i++) {
		// if space
		if (s[i] == 32 && ! bigSpace) {
			count++;
			bigSpace = true;
		} 
		// if not space
		if (s[i] != 32) {
			bigSpace = false;
		}
	}
	// if not in a space
	if (! bigSpace) {
		// add end word
		count++;
	}
	return count;
}


// Write a function that reformats or rewraps a string 
// to text to be no more than a given number of characters 
// per line. If the text is in the middle of a word at the 
// limit, the entire word is dropped onto the next line.

// prints a string with line breaks every 80 characters
void hardBreak(string s) {

	// NEEDS TO TEST FOR WORD

	int breakPoint = 40;
	for (int i = 0; i < s.length(); i++) {		
		// if at breakpoint
		if (i % breakPoint == 0 && i != 0) {
			// system("pause");
			// if space
			if (s[i] == 32) {
				// go to new line
				cout << endl;
			}
			// if in word
			else {
				// backtrack to space
				// then go to new line
				int backtrack = 0;
				while (s[i] != 32 && i > 0) {
					i--;
					/*cout << "I: " << i << endl;
					cout << "Char: " << s[i] << endl;
					cout << "Char: " << (int)s[i] << endl;*/
				}
				// new line
				cout << endl;	
				continue;
			}
			
		}
		cout << s[i];
	}
	cout << endl;
}