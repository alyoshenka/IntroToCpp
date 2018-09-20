#pragma once
#include <string>

using std::string;

struct saveData {
	char playerName[50] = "";
	int deathCount;
	int deepestFloor;
	bool hasBeatenGame;
	double timePlayed; //seconds
};


bool writeHelloWorld(string filePath);

bool saveDataToList(string filePath, saveData saveDataArray[], int arrSize);

void readSaveDataFromFile(string filePath);

void monsterQuest();

int chooseAction();

void addMonster();

void viewMonster();

void browseMonsters();
