#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

void everyOther(string s);

void bestowTitle();

int characterFrequency(string s, char c);

int instanceCounting(string s, string sub);

void hangman();

string chooseWord();

void printBoard(string guess, string word);

char takeGuess();

bool guessIsValid(string s, char c);

string updateGuessString(string guessString, char c, string word);

void printWrongGuesses(string s);