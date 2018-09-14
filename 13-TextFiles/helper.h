#pragma once

struct Entity {
	string name;
	float hitpoints;
	float armor;
	int strength;
	int defense;
	int agility;
	int luck;
};

void digitalPrinter();

void myInformation();

void textCorruption();

void commaToArray();

void printEntity();

int countEntitys();

Entity * loadEntityData(Entity * entityArr[]);

void beCaesar();

void loadMessage();

void saveMessage();
