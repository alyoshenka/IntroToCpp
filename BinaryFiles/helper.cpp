#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cerr;
using std::fstream;
using std::ios;
using std::ios_base;
using std::ofstream;
using std::ifstream;

#include "helper.h"

// write "Hello World" to file
bool writeHelloWorld(string filePath) {

	fstream file;

	// open file, appends if existing, creates if not
	file.open(filePath.c_str(), ios::out | ios::binary);

	// make sure file is ok
	if (file.fail()) {
		cerr << "Error" << endl;
		return false;
	}

	// else
	// reset error flags (such as EOF)
	file.clear();

	// move cursor to end of file for writing
	file.seekg(0, ios_base::end);

	// write to text file
	file << "Hello World\n";

	// flush outpus buffer
	file.flush();
	// close file
	file.close();
}

// save saveData to list
bool saveDataToList(string filePath, saveData saveDataArray[], int arrSize) {

	// open file in append mode
	ofstream fout(filePath.c_str(), ios::app | ios::binary);

	// verify file
	if (fout.fail()) {
		cerr << "Error" << endl;
		return false;
	}

	// fill in 
	for (int i = 0; i < arrSize; i++) {
		// write each struct value in array to the file
		fout.write((char*)&saveDataArray[i], sizeof(saveData));
	}
	fout.flush();
	fout.close();
}

// load saveData from disk
void readSaveDataFromFile(string filePath) {

	saveData mySaveData;
	ifstream fin(filePath, ios::in | ios::binary);

	// verify file
	if (fin.fail()) {
		cerr << "Error" << endl;
		return;
	}

	// really read the stuff
	// while not EOF && next char != EOF
	while (! fin.eof() && fin.peek() != EOF) {
		// pass in saveData object
		fin.read((char*)&mySaveData, sizeof(saveData));
		// print it out
		cout << "Name: " << mySaveData.playerName << endl;
		cout << "Deaths: " << mySaveData.deathCount << endl;
		cout << "Deepest floor reached: " << mySaveData.deepestFloor << endl;
		if (mySaveData.hasBeatenGame) {
			cout << "They have beaten the game!" << endl;
		}
		else {
			cout << "They have not beaten the game." << endl;
		}
		cout << "Time played (s): " << mySaveData.timePlayed << endl;
		cout << endl;
	}
	fin.close();	
}
