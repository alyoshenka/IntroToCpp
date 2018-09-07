#include <iostream>
#include "helper.h"


int main() {

	// Closed
	string s1 = "Thisisastring";
	everyOther(s1);

	bestowTitle();

	// Open
	string s2 = "This has four 's' characters";
	cout << characterFrequency(s2, 's') << endl;

	string s3 = "If I think I can, I will. If I think I can't, I won't.";
	cout << instanceCounting(s3, "can") << endl;
	cout << instanceCounting(s3, "I") << endl;

	// Hangman
	hangman();

	system("pause");
	return 0;
}