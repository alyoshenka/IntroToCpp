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

#include "helper.h"

using std::cout;
using std::endl;

//Is there a Marine alive
bool marineAlive(Marine * squadArr, int size)
{
	for (int i = 0; i < size; i++) {
		if (squadArr[i].isAlive()) {
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (int i = 0; i < arrSize; i++) {
		if (swarmArr[i].isAlive()) {
			return true;
		}
	}
	return false;
}

void marineVsZergs()
{
	int squadSize = 10;
	int swarmSize = 20;
	int livingMarines = 10;
	int marineIdx = 0;
	int zergIdx = 0;
	Marine squad[10];
	Zergling swarm[20];
	
	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!\n" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, 10) && zerglingAlive(swarm, 20)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, 10)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				int damage = squad[i].attack();
				swarm[zergIdx].takeDamage(damage);
				if (!swarm[zergIdx].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "\nThe zergling target dies\n" << endl;
					// go on to next Zergling
					zergIdx++;
				}				
			}
		}
		cout << "Now it is the Zergling's turn!\n" << endl;
		if (zerglingAlive(swarm, 20)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < squadSize; i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
				squad[marineIdx].takeDamage(swarm[i].attack());
				if (squad[marineIdx].isAlive())
				{
					cout << "The zergling's attack fails to kill the marine" << endl;
				}
				else{
					cout << "\nThe marine succumbs to his wounds." << endl;
					marineIdx++;
					livingMarines--;
					cout << "There are " << livingMarines << " marines left.\n" << endl;
				}				
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, 10))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}
}


