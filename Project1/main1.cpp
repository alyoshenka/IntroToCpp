#include <iostream>
#include <array>

// initializes array of given size to 2
void initializeToTwo(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 2;
	}
}

// prints numbers in array
void printNumbers(int nums[], int size) {
	std::cout << "printNumbers" << std::endl;
	// for(int val : nums[])
	for (int i = 0; i < size; i++) {
		std::cout << nums[i] << std::endl;
	}
}

// adds the values in an array
int sumNumbers(int nums[], int size) {
	std::cout << "sumNumbers" << std::endl;
	int sum = 0;
	for (int i = 0; i < size; i++) {
sum += nums[i];
	}
	return sum;
}

// returns the smallest value in an array
int smallestVal(int nums[], int size) {
	std::cout << "smallestVal" << std::endl;
	int min = INT_MAX;
	for (int i = 0; i < size; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// returns the largest value in an array
int largestVal(int nums[], int size) {
	std::cout << "largestVal" << std::endl;
	int max = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// returns the index of a given value in an array
// if not found, returns -1
int findIndex(int nums[], int size, int val, int start) {
	std::cout << "findIndex" << std::endl;
	for (int i = start; i < size; i++) {
		if (nums[i] == val) {
			return i;
		}
	}
	// else
	return -1;
}

// returns the number of times a given value appears in an array
int countElement(int nums[], int size, int val, int start) {
	std::cout << "countElement" << std::endl;
	int sum = 0;
	for (int i = start; i < size; i++) {
		if (nums[i] == val) {
			sum++;
		}
	}
	if (sum >= 0) {
		return sum;
	}
	// else
	return -1;
}

// returns the number of times a given value appears in an array
int countTimes(int nums[], int size, int val, int start) {
	std::cout << "countTimes" << std::endl;
	int cnt = 0;
	for (int i = start; i < size; i++) {
		if (nums[i] == val) {
			cnt++;
		}
	}
	return cnt;
}

// tests if all values in array are unique
bool allUnique(int nums[], int size) {
	std::cout << "allUnique" << std::endl;
	bool allU = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (nums[i] == nums[j]) {
				allU = false;
			}
		}
	}
	return allU;
}

// reverses the order of values in an array
void reverse(int nums[], int size) {
	std::cout << "reverse" << std::endl;
	int swap = 0;
	int j = size - 1;
	for (int i = 0; i < size / 2; i++) {
		swap = nums[i];
		nums[i] = nums[j];
		nums[j] = swap;
		j--;
	}
}

// sorts values in array in ascending order
void sortAsc(int nums[], int size) {
	std::cout << "sortAsc" << std::endl;
	int swap = 0;
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size - 1; j++) {
			if (nums[j] > nums[j+1]) {
				swap = nums[j];
				nums[j] = nums[j+1];
				nums[j + 1] = swap;
			}
		}
	}
}

// sorts values in array in descending order
void sortDes(int nums[], int size) {
	std::cout << "sortDes" << std::endl;
	int swap = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (nums[j] < nums[j + 1]) {
				swap = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = swap;
			}
		}
	}
}

int main(){
	// Test
	int arr[] = { 1, 2, 3, 3, 5};
	int arr2[] = { 5, 7, 1, 7, 0 };
	
	// Closed
	printNumbers(arr, 5);

	std::cout << sumNumbers(arr, 5) << std::endl;

	std::cout << smallestVal(arr, 5) << std::endl;

	std::cout << largestVal(arr, 5) << std::endl;

	//Open
	std::cout << findIndex(arr, 5, 1, 0) << std::endl;

	std::cout << countElement(arr, 5, 1, 0) << std::endl;

	std::cout << countTimes(arr, 5, 1, 0) << std::endl;

	if (allUnique(arr, 5)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	reverse(arr, 5);
	printNumbers(arr, 5);
	// reverse back
	reverse(arr, 5);
	printNumbers(arr, 5);

	printNumbers(arr2, 5);
	sortAsc(arr2, 5);
	printNumbers(arr2, 5);

	sortDes(arr2, 5);
	printNumbers(arr2, 5);

	// Challenge

	system("pause");
	return 0;
}