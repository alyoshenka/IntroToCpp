#include <iostream>
#include "piggyBank.h"

int main() {

	piggyBank p1 = {1, 2, 3, 4, 5, 6, 7};

	std::cout << calcPiggybankTotal(p1) << std::endl;

	system("pause");
	return 0;
}