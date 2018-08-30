#include "helper.h"



int main() {

	// multipleChoice();

	// printFives(2, 6);

	int arr[] = { 3, 3, 2, 4, 3, 5 };
	// candles(arr, 6);

	int arr2[] = { 32, 25, 76, 69, 11, 88 };
	rotateArray(arr2, 6, 3);
	for (int i = 0; i < 6; i++) {
		cout << arr2[i] << endl;
	}

	highScoreData data[] = {
		{0, 1},
		{8, 10},
		{60, 9},
		{3, 6},
		{20, 0}
	};
	int val = highestScore(data, 5);
	// cout << "Highest: " << val << endl;

	float ave = aveTime(data, 5);
	// cout << "Average Time: " << ave << endl;

	int dif = scoreDif(data, 4);
	// cout << "Score difference: " << dif << endl;

	system("pause");
	return 0;
}