#include "Entity.h"



Entity::Entity()
{
	health = 40;
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	if (health <= 0) {
		return false;
	}
	return true;
}

void Entity::takeDamage(int damage) {
	health -= damage;
}

int Entity::attack() {
	return 15;
}

void Entity::setInitHealth(int initHealth) {
	health = initHealth;
	maxHealth = initHealth;
}
