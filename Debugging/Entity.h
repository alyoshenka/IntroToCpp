#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);
	bool isAlive();
	void setInitHealth(int initHealth);

private:
	int health;
	int maxHealth;
};

