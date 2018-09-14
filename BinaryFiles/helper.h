#pragma once
#include <string>

using std::string;

struct saveData {
	string playerName;
	int deathCount;
	int deepestFloor;
	bool hasBeatenGame;
	double timePlayed; //seconds
};

bool writeHelloWorld(string filePath);

bool saveDataToList(string filePath, saveData saveDataArray[], int arrSize);

void readSaveDataFromFile(string filePath);
