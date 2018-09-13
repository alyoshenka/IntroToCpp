#include "Zergling.h"



Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 10;
}

void Zergling::takeDamage(int damage)
{
	currentHealth -= damage;
	if (currentHealth < 0)
		currentHealth = 0;
}
