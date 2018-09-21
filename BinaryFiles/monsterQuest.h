#pragma once

using std::string;

struct Monster {
	string species;
	string name;
	string favoriteFood;
	int age;
	int idNumber;
};

void monsterQuest();

int chooseAction();

void printMonster(Monster myMonster);

bool addMonster(int ID);

bool removeMonster(int ID);

void viewMonster(int ID);

void browseMonsters();

int monsterCount();

int highestIDNumber();