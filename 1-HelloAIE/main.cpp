#include <iostream>
int main() {
	// print hello message
	std::cout << "Hello AIE" << std::endl; 

	//songs
	std::cout << "" << std::endl; // new line
	std::cout << "Favorite Tracks:" << std::endl;
	std::cout << "Swing Life Away" << std::endl;
	std::cout << "Holiday" << std::endl;
	std::cout << "The Lonely Ballerina" << std::endl;

	//numbers 1
	std::cout << "" << std::endl; // new line
	int i;
	for (i = 0; i <= 5; i++) {
		std::cout << i << std::endl;
	}

	//numbers 2
	std::cout << "" << std::endl; // new line
	for (i = 5; i >= 0; i--) {
		std::cout << i << std::endl;
	}

	// open excercises
	std::cout << "" << std::endl; // new line
	// #1
	std::cout << "Howdy AIE" << std::endl;
	std::cout << "It's a fine day today as any!" << std::endl; // semicolon
	std::cout << "I really wish I had some potatoes..." << std::endl;

	// #2
	std::cout << "Four score and seven years ago" << std::endl;
	std::cout << "our fathers brought forth on this continent," << std::endl;
	std::cout << "a new nation," << std::endl;
	std::cout << "conceived in Libery, and dedicated to the proposition" << std::endl;
	std::cout << "that all men are created equal." << std::endl;

	std::cout << "Now we are engaged in a great civil war," << std::endl;
	std::cout << "testing whether that nation, or any nation" << std::endl; // quotation marks 
	std::cout << "so conceived and so dedicated, can long endure." << std::endl;

	// pause to read output
	system("pause");
	return 0;
}