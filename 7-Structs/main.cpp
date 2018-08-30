#include <iostream>
#include "person.h"
#include "piggyBank.h"
#include "student.h"
#include "vector2D.h"
#include "zombie.h"

int main() {

	// Practice
	person paul = {};
	person jon = { 15, 1000, 20 };

	printPerson(jon);
	printPerson(paul);

	// Closed
	piggyBank p1 = { 1, 2, 3, 4, 5, 6, 7 };
	std::cout << calcPiggybankTotal(p1) << std::endl;

	// Open
	student s1 = { 12006, 1, 45, {0.0f, 50.0f, 80.0f, 67.0f } };
	student s2 = { 12007, 2, 29, {50.0f, 78.0f, 19.0f, 90.0f } };
	student s3 = { 12008, 2, 32, {99.0f, 67.0f, 34.0f, 78.0f } };
	student s4 = { 12009, 1, 40, {80.0f, 60.0f, 50.0f, 20.0f } };
	student s5 = { 12010, 2, 47, {23.0f, 95.0f, 93.0f, 75.0f } };
	student s6 = { 12011, 2, 28, {64.0f, 38.0f, 76.0f, 50.0f } };

	// Print Student
	std::cout << "Student" << std::endl;
	printStudent(s1);

	// Student Analytics
	student students[] = { s1, s2, s3, s4, s5, s6 };
	std::cout << "Ave score: " << aveScore(students) << std::endl;
	std::cout << "Med score: " << medScore(students) << std::endl;
	std::cout << "Students in 2: " << studentsInCourse(students, 2)
		<< std::endl;

	// Vector 2D
	vector2 v1 = { 2, 5 };
	vector2 v2 = { 3, 8 };

	std::cout << "VecSum: " << vecSum(v1, v2).x << ", " <<
		vecSum(v1, v2).y << std::endl;
	std::cout << "VecDif: " << vecDif(v1, v2).x << ", " <<
		vecDif(v1, v2).y << std::endl;
	std::cout << "VecDist: " << vecDist(v1, v2) << std::endl;

	// Player V. Zombie
	character person = { 100, 20, 5 };
	character zomb = { 80, 7, 10 };
	attack(person, zomb);

	// Challenge

	// Struct of Arrays



	system("pause");
	return 0;
}