#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack(); // what is a virtual int??
	virtual void takeDamage(int damage);
	virtual int health(); // virtual for the same reason as attack()
	// but I have no idea what that reason is
	bool isAlive();
	void setInitHealth(int health);
	void setAttack(int attack);

private:
	int currentHealth;
	int maxHealth;
	int attackPoints;
};

