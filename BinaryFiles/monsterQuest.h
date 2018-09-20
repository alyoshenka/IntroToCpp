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

void addMonster(int ID);

void removeMonster(int ID);

void viewMonster(int ID);

void browseMonsters();