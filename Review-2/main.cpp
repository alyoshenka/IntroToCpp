#include <iostream>
#include "assignmentHelper.h"

// To Do
// test for word in hardBreak()

int main() {

	// C-String Append
	char origString[32] = "lil string";
	char appendMe[22] = " (append string here)";
	/*appendCString(origString, appendMe, 32, 22);
	for (int i = 0; i < 32; i++) {
		cout << origString[i];
	}
	cout << endl;*/

	// C-String Insertion
	// insertCString(origString, appendMe, 32, 4);

	// Word Count
	string s1 = "This is a few words.";
	string s2 = "I want to go to the CGDC next year.";
	string s3 = " Let's test the function.";
	string s4 = "Let's test     the function.";
	string s5 = "Let's test the function     ";
	string s6 = " ";

	/*cout << "5 = " << wordCount(s1) << endl;
	cout << "9 = " << wordCount(s2) << endl;
	cout << "4 = " << wordCount(s3) << endl;
	cout << "4 = " << wordCount(s4) << endl;
	cout << "4 = " << wordCount(s5) << endl;
	cout << "0 = " << wordCount(s6) << endl;*/

	// Hard Break @ 80 char
	string reallyLong = "";
	for (int i = 1; i <= 160; i++) {
		reallyLong += std::to_string(0);
	}
	// hardBreak(reallyLong);
	
	// FUN FACT adjacent string literals are concatenated by the compiler

	string reallyLongPt2 = "Mr. and Mrs. Dursley, of number four, Privet"
		" Drive, were proud to say that they were perfectly normal, thank"
		" you very much. They were the last people you'd expect to be"
		" involved in anything strange or mysterious, because they just"
		" didn't hold with such nonsense."
		" Mr.Dursley was the director of a firm called Grunnings, which made"
		" drills. He was a big, beefy man with hardly any neck, although he did"
		" have a very large mustache.Mrs.Dursley was thin and blonde and had"
		" nearly twice the usual amount of neck, which came in very useful as she"
		" spent so much of her time craning over garden fences, spying on the"
		" neighbors. The Dursleys had a small son called Dudley and in their"
		" opinion there was no finer boy anywhere.";		
	// hardBreak(reallyLongPt2);

	// Address Book


	system("pause");
	return 0;
}