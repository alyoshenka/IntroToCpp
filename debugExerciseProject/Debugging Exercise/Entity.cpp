#include "Entity.h"



Entity::Entity()
{
	maxHealth = 50;
	currentHealth = maxHealth;
	attackPoints = 10;
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	return currentHealth = 0;
}

// add attack function
// return attack points
 int Entity::attack() {
	 return attackPoints;
}

 // define function
 void Entity::takeDamage(int damage) {
	 currentHealth -= damage;
	 if (currentHealth < 0)
		 currentHealth = 0;
 }

 int Entity::health() {
	 return currentHealth;
 }

