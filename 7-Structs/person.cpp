#include <iostream>
#include "person.h"

void printPerson(person target) {
	std::cout << "Age: " << target.age << std::endl;
	std::cout << "Cash: " << target.cash << std::endl;
	std::cout << "Points: " << target.points << std::endl;
}