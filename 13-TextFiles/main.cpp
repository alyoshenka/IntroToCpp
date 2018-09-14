#include <iostream>
#include <fstream>
#include <string>
#include "helper.h"

int main() {


	std::fstream file;

	// open a file relative to the working directory of the project
	file.open("test.txt", std::ios::out);

	// verify that the file is open
	if (file.fail())
	{
		std::cout << "File not found." << std::endl;
		return -1;
	}

	std::string buffer;
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		// print the line after it is buffered
		std::cout << buffer << std::endl;
	}

	// reset error flags (such as EOF)
	file.clear();

	// move the cursor to the end of the file for writing
	file.seekp(0, std::ios_base::end);

	// write a message to the text file
	file << "Howdy Text!";

	file.flush();   // flush the output buffer, making sure all outputs are sent
	file.close();   // close and release the file


	// Closed
	// digitalPrinter();
	// myInformation();

	// Open
	// textCorruption();
	// commaToArray();
	// printEntity(); FINISH
	int entityCount = countEntitys();
	Entity * arr = new Entity[ entityCount ];
	loadEntityData(arr);
	

	// print Entity array
	for (int i = 0; i < 5; i++) {
		std::cout << "Name: " << arr[i].name << std::endl;
		std::cout << "Hitpoints: " << arr[i].name << std::endl;
		std::cout << "Armor: " << arr[i].name << std::endl;
		std::cout << "Strength: " << arr[i].name << std::endl;
		std::cout << "Defense: " << arr[i].name << std::endl;
		std::cout << "Agility: " << arr[i].name << std::endl;
		std::cout << "Luck: " << arr[i].name << std::endl;
		std::cout << std::endl;
	}

	// Challenge
	// beCaesar();

	delete[] arr;

	system("pause");
	return 0;
}