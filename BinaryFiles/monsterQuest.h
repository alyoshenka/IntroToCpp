#pragma once

using std::string;

struct Monster {
	char species[50];
	char name[50];
	char favoriteFood[50];
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

bool inBestiary(string monsterSpecies);