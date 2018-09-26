#include <iostream>
#include <string>
#include <fstream>

#include "helper.h"
#include "monsterQuest.h"

using std::string;
using std::fstream;
using std::ios_base;
using std::cout;
using std::endl;




int main() {

	// Closed
	cout << "Hello World" << endl;
	writeHelloWorld("helloWorld.bin");
	cout << "Done\n" << endl;

	cout << "Save and read data in binary" << endl;
	saveData alexi = {"Alexi", 0, 100, true, 5000};
	saveData amanda = {"Amanda", 7, 45, false, 400};
	saveData ray = {"Ray", 2000, 2, false, 60000000};

	saveData firstThing[] = { alexi };
	saveData secondThing[] = { amanda, ray };


	saveDataToList("mySaveData.bin", firstThing, 1);
	readSaveDataFromFile("mySaveData.bin");

	saveDataToList("mySaveData.bin", secondThing, 2);
	readSaveDataFromFile("mySaveData.bin");
	cout << "Done\n" << endl;

	// Open
	cout << "Monster Creature Quest" << endl;
	monsterQuest();

	system("pause");
	/*cout << "Weird sys pause thing" << endl;
	char b;
	std::cin >> b;*/

	return 0;
}