#include <iostream>
#include <cstring>
#include <string>

// returns the length of a given string
// null-terminating character not included
int stringLength(char str[]) {
	int length = 0;
	int i = 0;
	while (str[i] > 0) {
		i++;
		length++;
	}
	return length;
}

// prompts the user for their favorite color and provides
// some feedback on their decision making
void favoriteColor() {
	// prompt for input
	char color[50];
	std::cout << "What is your favorite color: ";
	std::cin >> color;

	char red[50] = "red";
	char orange[50] = "orange";
	char red2[50] = "Red";
	char orange2[50] = "Orange";
	if (strcmp(red, color) == 0 || strcmp(red2, color) == 0) {
		std::cout << "Red ? Like the color of roses ?" << std::endl;
	}
	else if (strcmp(orange, color) == 0 || strcmp(orange2, color) == 0) {
		std::cout << "Orange is also a fruit." << std::endl;
	}
	else {
		std::cout << color << "? I've never heard of that color before." << std::endl;
	}
}

// capitalizes all of the letters in the given string
void toUpper() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char str[50];
	std::cout << "Input a string to be made uppercase: ( < 50 characters)" << std::endl;
	// keeps the spaces
	std::cin.getline(str,50);
	for (int i = 0; i < 50; i++) {
		if (str[i] < 0) {
			break;
		}
		if (str[i] >= 97 && str[i] <= 122) {
			std::cout << (char)(str[i] - 32);
		}
		else {
			std::cout << str[i];
		}
	}
	std::cout << std::endl;
}

// accepts an input string and outputs the same string without whitespace characters
void removeWhitespace() {
	char str[50];
	std::cout << "Input a string: ( < 50 characters)" << std::endl;
	// keeps the spaces
	std::cin.getline(str, 50);
	for (int i = 0; i < 50; i++) {
		// stops it from breaking
		if ((int)str[i] < 0 || (int)str[i] > 255) {
			break;
		}
		// if whitespace character
		// "Non-zero value if the character is a whitespace character, zero otherwise"
		if ((isspace(str[i])) == 0) {
			// print
			std::cout << str[i];
		}
	}
	std::cout << std::endl;
}

// overwrites the contents of one c-string with a sub-string from another c-string
void substring(char str[], int startIdx, char substring[], int subStartIdx, int subLength) {
	for (int i = startIdx; i < subLength; i++) {
		str[startIdx] = substring[subStartIdx];
		startIdx++;
		subStartIdx++;
	}
	for (int i = 0; i < strlen(str); i++) {
		std::cout << str[i];
	}
	std::cout << std::endl;
}

// evaluates whether or not a string is a palindrome
// ignores case	
bool isPalindrome(char str[]) {
	bool pal = true;
	int len = stringLength(str);
	// make all lowercase to negate case
	for (int i = 0; i < len; i++) {
		str[i] = tolower(str[i]);
	}
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) {
			pal = false;
		}
	}
	return pal;
}

// reverses the contents of a string
void stringReversal(char str[]) {
	char temp = 'a';
	int len = strlen(str);
	for (int i = 0; i < (len / 2); i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	for (int i = 0; i < len; i++) {
		std::cout << str[i];
	}
	std::cout << std::endl;
}

// removes any leading or trailing spaces in a string
void stringTrimming(char str[]) {
	int i = 0;
	// leading whitespace
	// while whitespace
	while (isspace(str[i]) != 0) {
		// do nothing
		i++;
	}
	while (isspace(str[i]) == 0) {
		// pring
		std::cout << str[i];
		i++;
	}
	std::cout << std::endl;
}

// shift cipher that rearranges a c-string
void shiftCipher(char str[], int val) {
	int len = strlen(str);
	bool nonLetters = false;
	for (int i = 0; i < len; i++) {
		int asciiVal = str[i];
		asciiVal += val;
		//  NOTE shifting by very large values will throw this off
		// capital
		if (str[i] >= 65 && str[i] <= 90) {
			// if out of capital bounds
			while (asciiVal > 90) {
				asciiVal = 65 + asciiVal - 90;
			}
		}
		// lowercase
		else if (str[i] >= 97 && str[i] <= 122) {
			while (asciiVal > 122) {
				asciiVal = 97 + asciiVal - 122;
			}
		}
		// numbers
		else if (str[i] >= 48 && str[i] <= 57) {
			while (asciiVal > 57) {
				asciiVal = 48 + asciiVal - 57;
			}
		}
		// non letters and non numbers
		else {
			nonLetters = true;
		}
		str[i] = asciiVal;
	}
	if (nonLetters) {
		std::cout << "Some characters were not letters. They have been shifted by "
			<< val << " values of the ASCII chart." << std::endl;
	}
	std::cout << "Shifted cipher:" << std::endl;
	for (int i = 0; i < len; i++) {
		std::cout << str[i];
	}
	std::cout << std::endl;
}

// main application function
int main() {

	// Closed

	// Greeting
	// (doesn't work if length > 49)
	std::cout << "Greeting" << std::endl;
	
	char name[50] = {};
	std::cout << "What is your name?" << std::endl;
	std::cin >> name;
	std::cout << "Hello ";
	for (int i = 0; i < 50; i++) {
		if (name[i] == '\0') {
			break;
		}
		std::cout << name[i];
	}
	std::cout << std::endl;

	// Favorite Color
	std::cout << "Favorite Color" << std::endl;
	favoriteColor();
	
	// to Upper
	std::cout << "To Uppercase" << std::endl;
	toUpper();

	// Remove Whitespace
	std::cout << "Remove Whitespace" << std::endl;
	removeWhitespace();

	// Open

	// Substring
	char bigString[] = "This is a really big string ;)";
	char lilString[] = "Lil string XP";
	substring(bigString, 3, lilString, 0, 13);


	// Palindrome Test
	std::cout << "Palindrome Test" << std::endl;
	char pal1[] = "thisisnotapalindrome";
	char pal2[] = "racecar";
	char pal3[] = "Racecar";
	std::cout << "Pal1: " << isPalindrome(pal1) << std::endl;
	std::cout << "Pal2: " << isPalindrome(pal2) << std::endl;
	std::cout << "Pal3: " << isPalindrome(pal3) << std::endl;

	// String Length
	std::cout << "String Length" << std::endl;
	char longString[] = "This is a really long string.";
	std::cout << "String length: " << stringLength(longString) 
		<< std::endl;

	// String reversal
	std::cout << "String Reversal" << std::endl;
	char str1[] = "sdrawrofstiwon";
	stringReversal(str1);

	// String Trimming
	std::cout << "String Trimming" << std::endl;
	char trimString[] = "  hi my name is ";
	stringTrimming(trimString);

	//Challenge

	// Shift Cipher
	std::cout << "Shift Cipher" << std::endl;
	char str2[] = "01234567";
	char str3[] = "abcdefgh";
	shiftCipher(str3, 20);
	shiftCipher(str2, 5);

	system("pause");
	return 0;
}