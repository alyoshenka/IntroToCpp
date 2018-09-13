#include "Marine.h"

Marine::Marine()
{
	setInitHealth(50); 
	setAttack(10);
}


Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

