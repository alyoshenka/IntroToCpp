#include <iostream>
#include "zombie.h"
using namespace std;

// This function simulates and attack between a player
// and a zombie.
void attack(character p, character z) {

	// while one not dead
	while (p.hitP > 0 && z.hitP > 0) {

		// Player's turn
		cout << "Player hits Zombie for " << p.attackP <<
			" points. Zombie defends with " << z.defP <<
			" points." << endl;
		z.hitP = z.hitP - p.attackP + z.defP;
		cout << "Player: " << p.hitP << endl;
		cout << "Zombie: " << z.hitP << endl;

		// Zombie's turn
		cout << "Zombie hits Player for " << z.attackP <<
			" points. Zombie defends with " << p.defP <<
			" points." << endl;
		p.hitP = p.hitP - z.attackP + p.defP;
		cout << "Player: " << p.hitP << endl;
		cout << "Zombie: " << z.hitP << endl;
	}

	// if zombie dead
	if (z.hitP <= 0) {
		cout << "Player wins." << endl;
	}
	else {
		cout << "Player wins." << endl;
	}
}

