// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"
#include <time.h> // for random numbers

using std::cout;
using std::endl;

// change to entityAlive()

// declare functions now, define later
bool marineAlive(Marine * squadArr, size_t arrSize);

bool zerglingAlive(Zergling * swarmArr, size_t arrSize);

void entityDied(Entity * entityArr, size_t arrSize);

void initializeEntity(Entity * entityArr, size_t arrSize);

int main()
{
	Marine squad[10];
	Zergling swarm[20];
	
	// declare squad sizes for marines and zergs
	int marineSquadSize = 10;
	int zergSquadSize = 20;

	// initialize teams
	// initializeEntity(squad, marineSquadSize);
	// initializeEntity(swarm, zergSquadSize);

	for (int i = 0; i < 10; i++) {
		cout << "MA: " << squad[i].attack() << endl;
	}

	// squadSize???
	// make separate function for squadsize
	// set random team initializer function??
	// function to sort teams if a member dies


	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl; // no <<

	// modify teamAlive() to accept team array and array size

	// Attack each other until only one team is left alive
	// change to && because both teams nees to be alive
	while (marineSquadSize > 0 && zergSquadSize > 0) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, 10)) // if there's at least one marine alive
		{

			// look at logic in squadSize
			// these for loops should not be here
			// the original loops iterate through the entire team array (I think)
			// nevermind

			for (size_t i = 0; i < marineSquadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				int damage = squad[i].attack();
				swarm[0].takeDamage(damage);
				if (!swarm[0].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "The zergling target dies" << endl;
					// sort zerg array
					entityDied(swarm, 20);
					zergSquadSize--;
				}
			}
		}
		if (zerglingAlive(swarm, 20)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < zergSquadSize; i++) // loop through zerglings
			{

				// make array index accession the same as previous if statement 
				// because why do the same job two different ways??

				cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
				// squad.begin()->takeDamage(i->attack()); // this line is different
				int damage = swarm[i].attack();
				squad[0].takeDamage(damage);
				if (!squad[0].isAlive())
				{
					// sort marine array
					entityDied(squad, 10);
					marineSquadSize--;
				}
				else
					cout << "The marine succumbs to his wounds." << endl;
					cout << "There are " << marineSquadSize << " marines left." << endl;
					
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";

	// add else/if for the zergs winning, make else tuie case
	if (marineSquadSize >= 0)
	{
		cout << "The Marines win." << endl;
	}
	else if(zergSquadSize <= 0){
		cout << "The Zerg win." << endl;
	}
	else {
		cout << "Tie." << endl;
	}

	system("pause");
	return 0;
}

// make function work as intended

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	// iterate through squad
	for (int i = 0; i < arrSize; i++) {
		// if squadArr has living member
		if (squadArr[i].health > 0) {
			return true;
		}
	}
	return false;
}

// make function work as intended

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	// iterate through squad
	for (int i = 0; i < arrSize; i++) {
		// if squadArr has living member
		if (swarmArr[i].health > 0) {
			return true;
		}
	}
	return false;
}

// if team member dies, move player to end and shift other players forward
// rotate everything to the left once
void entityDied(Entity * entityArr, size_t arrSize) {
	// set temp
	Entity placeholder = entityArr[0];

	// move all left one
	for (int i = 1; i < arrSize - 1; i++) {
		entityArr[i] = entityArr[i + 1];
	}
	entityArr[arrSize - 1] = placeholder;
}

// function to initialize Entity arrays
void initializeEntity(Entity * entityArr, size_t arrSize) {

	// default values

	int maxHealth = 10;
	int attack = 10;

	int healthVal = 10;
	int attackVal = 10;

	// cout << "Def maxH: " << maxHealth << endl;
	// cout << "Def attack: " << attack << endl;

	// range between min and max val
	int range = 5;

	// initialize random number seed
	srand(time(NULL));

	// change values based on class
	// if marine
	if (typeid(entityArr) == typeid(Marine)) {
		maxHealth = 20;
		attack = 10;
		cout << "Marine:" << endl;
	}
	// if zerg
	if (typeid(entityArr) == typeid(Zergling)) {
		maxHealth = 12;
		attack = 7;
		cout << "Zerg:" << endl;
	}

	for (int i = 0; i < arrSize; i++) {

		// Marine 
		// health 15 - 20
		// attack 5 - 10
		// Zerg
		// health 7 - 12
		// attack 2 - 7

		// randNum = rand() % difference+1 + min_val
		healthVal = rand() % (maxHealth - range + 1) + (maxHealth - range);
		attackVal = rand() % (attack - range + 1) + (attack - range);

		entityArr[i].setInitHealth(healthVal);
		entityArr[i].setInitAttack(attackVal);

		// tests that random numbers are being generated correctly
		// cout << "Health: " << healthVal << endl;
		// cout << "Attack: " << attackVal << endl;
	}
}
