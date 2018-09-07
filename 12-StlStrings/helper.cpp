#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterate over a std::string object and print out 
// every out character in the string.
void everyOther(string s) {
	cout << "Every other char in string:" << endl;
	for (int i = 0; i < s.length(); i += 2) {
		cout << s[i];
	}
	cout << endl;
}

// Prompt the user for their name and store it in 
// a std::string object. Then print the name back 
// to them with an additional title appended to the end.
void bestowTitle() {
	string name = "s";
	cout << "Bestow Title:" << endl;
	cout << "What is your name?" << endl;
	std::getline(cin, name);
	name += ", the Great";
	cout << name << endl;
}

// Create a function that will count the number of 
// times a given character appears in a string. The 
// function should return the number of occurances.
int characterFrequency(string s, char c) {
	cout << "Character Frequency:" << endl;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) {
			count++;
		}
	}
	return count;
}

// Create a function that counts the number of times 
// a given string appears in another string. The 
// function should return the number of occurances.
int instanceCounting(string s, string sub) {
	cout << "Instance Counting:" << endl;
	int count = 0;
	// for (int i = 0; i < s.length() - sub.length(); i += sub.length)
	for (int i = s.find(sub, 0); i != string::npos; i = s.find(sub, i)) {
		count++;
		i++;
	}
	return count;
}

// main hangman function
void hangman() {

	int strikes = 0;
	bool winner = false;

	string word = "blah";
	char guess = '0';
	string wrongGuesseString = "";

	cout << "Let's Play Hangman!" << endl;
	word = chooseWord();

	// empty string to start
	string guessString = "";

	// populate guessString to word length
	for (int i = 0; i < word.length(); i++) {
		guessString += "0";
	}
	cout << "I have chosen a word." << endl;

	while (winner = false || strikes < 5) {
		printBoard(guessString, word);
		printWrongGuesses(wrongGuesseString);
		guess = takeGuess();

		// if guess is in word
		if (guessIsValid(word, guess)) {

			// puts guess into guessString
			guessString = updateGuessString(guessString, guess, word);

			// print updated board and continue
			printBoard(guessString, word);

			// check for win
				// guessString == word
			if (word == guessString) {
				winner = true;
				break;
			}
		}
		else {
			// wrong guess = strike
			cout << "Wrong, try again." << endl;
			wrongGuesseString += guess;
			strikes++;
		}
	}

	// if they won
	if (winner) {
		cout << "Yay you won!" << endl;
	}
	// if not
	else {
		cout << "You were hanged RIP" << endl;
		cout << "The word was '" << word << "'" << endl;
	}
}

// returns a random word from list
string chooseWord() {

	srand(time(NULL));

	int difficulty = -1;
	cout << "Choose a diffuculty:" << endl;
	cout << "1 - Easy" << endl;
	cout << "2 - Medium" << endl;
	cout << "3 - Hard" << endl;
	cout << "4 - Extreme" << endl;
	cout << "Your choice: ";
	cin >> difficulty;
	// input validation
	while (difficulty < 1 || difficulty > 4) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Bad input" << endl;
		cout << "Choose a diffuculty:" << endl;
		cout << "1 - Easy" << endl;
		cout << "2 - Medium" << endl;
		cout << "3 - Hard" << endl;
		cout << "4 - Extreme" << endl;
		cout << "Your choice: ";
		cin >> difficulty;
	}

	// easy ( <= 6 )
	string e1 = "mouse";
	string e2 = "table";
	string e3 = "apple";
	string e4 = "banana";
	string e5 = "chrome";
	string e6 = "orange";
	string e7 = "puzzle";
	string e8 = "people";
	string e9 = "puppy";

	// medium ( <= 8 )
	string m1 = "computer";
	string m2 = "sandwich";
	string m3 = "grapefruit";
	string m4 = "hangman";
	string m5 = "chicken";
	string m6 = "blizzard";
	string m7 = "academy";
	string m8 = "bathroom";
	string m9 = "calendar";

	// hard ( <= 10 )
	string h1 = "snowstorm";
	string h2 = "chairman";
	string h3 = "blackjack";
	string h4 = "alchemist";
	string h5 = "blasphemy";
	string h6 = "basketball";
	string h7 = "chocolate";
	string h8 = "beautiful";
	string h9 = "consonant";

	// extreme ( BIIIG )
	string extremeWords[] = { "thalassophobia", "ambidexterous", 
		"supercalifragilisticexpialidocious", "organization", "bourgeois", 
		"dichotomy", "euphemism", "facetious", "idiosyncratic" };

	string easyWords[] = { e1, e2, e3, e4, e5, e6, e7, e8, e9 };
	string mediumWords[] = { m1, m2, m3, m4, m5, m6, m7, m8, m9 };
	string hardWords[] = { h1, h2, h3, h4, h5, h6, h7, h8, h9 };
	// string extremeWords[] = { ex1, ex2, ex3, ex4, ex5, ex6, ex7, ex8, ex9 };

	// random number 0 - 8
	int idx = rand() % 9; 

	string word = "blah";

	switch (difficulty) {
	case 1:
		word = easyWords[idx];
		break;
	case 2:
		word = mediumWords[idx];
		break;
	case 3:
		word = hardWords[idx];
		break;
	case 4:
		word = extremeWords[idx];
		break;
	default:
		word = easyWords[idx];
		break;
	}
	return word;
}

// prints out the spaces
void printBoard(string guess, string word) {
	// spacer
	cout << endl;
	for (int i = 0; i < word.length(); i++) {
		// if matching
		if (guess[i] == word[i]) {
			// print letter
			cout << guess[i] << " ";
		}
		// if not
		else {
			// print space
			cout << "_ ";
		}
		
	}
	cout << endl;
	cout << endl;
}

// takes input for a letter guess
char takeGuess() {
	char guess = '0';
	cout << "Guess a letter: ";
	cin >> guess;
	// while not a letter
	while (guess < 97 || guess > 122 ) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Bad input" << endl;
		cout << "Hint: try typing a lowercase letter" << endl;
		cout << "Guess a letter: ";
		cin >> guess;		
	}
	return guess;
}

// returns whether guess is in word
bool guessIsValid(string s, char c) {
	// if char in string
	if (s.find(c) != string::npos) {
		return true;
	}
	return false;
}

// updates guess string
string updateGuessString(string guessString, char c, string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == c) {
			guessString[i] = c;
		}
	}
	return guessString;
}

// prints the string of wrong guesses
void printWrongGuesses(string s) {
	cout << "Wrong Guesses: ";
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}