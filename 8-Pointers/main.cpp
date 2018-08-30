#include <iostream>

// arrays = pointers (basically)
int getFirstNum(int *arr) {

	// pointer references start of array
	// so this returns the first value
	return arr[0];
	// *(arr+4) = 5 = arr[5]
}

// Print an Array of Floats
void printFloats(float *arr, int s) {
	for (int i = 0; i < s; i++) {
		std::cout << arr[i] << std::endl;
	}
}

// Sum of an Integer Array
int arraySum(int *arr, int s) {
	int sum = 0;
	for (int i = 0; i < s; i++) {
		sum += arr[i];
	}
	return sum;
}

// Initialize Boolean Array
void initBoolArray(bool *arr, int s, bool defaultVal) {
	for (int i = 0; i < s; i++) {
		arr[i] = defaultVal;
	}
}

// Get Integer Subarray
void getIntSubarray(int *arr, int *newArr, int s, int startIdx, int endIdx) {
	int idx = 0;
	for (int i = startIdx; i <= endIdx; i++) {
		newArr[idx] = arr[i];
		idx++;
	}
}

// Get Pointer to Element
char* getPntrToElement(char *arr, int s, char c, bool isCaseSensitive) {
	for (int i = 0; i < s; i++) {
		if (isCaseSensitive) {
			if (arr[i] == c) {
				return &arr[i];
			}
		}
		else {
			if (arr[i] == c || arr[i] == c-32) {
				return &arr[i];
			}
		}
	}
	// if not in arr
	return nullptr;
}

// Swapping Pointers
void swapPointers(int *&ptr1, int *&ptr2) {
	// ptr1 = *&ptr1...sort of
	int *temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}
/*
OR
(int** a, int** b)
	int* temp = *b
	*b = *a
	*a = temp
*/

// Going Without Subscript Operator
int sumWithoutSubscript(int *arr, int s) {
	int sum = 0;
	for (int i = 0; i < s; i++) {
		sum += *arr;
		arr++; // *arr also works
	}
	return sum;
}

int main() {

	int nums[] = { 1, 2, 3, 4, 5, 6 };
	int coffeeCup = 0;
	int* pointer = &coffeeCup;

	// variable
	std::cout << coffeeCup << std::endl;
	// reference memory address (pointer)
	std::cout << pointer << std::endl;
	// dereference pointer -> get value
	std::cout << *pointer << std::endl;

	// set coffeeCup to 3
	coffeeCup = 3;
	std::cout << coffeeCup << std::endl;
	std::cout << pointer << std::endl;
	std::cout << *pointer << std::endl;

	// set pointer value to 7
	*pointer = 7;
	std::cout << coffeeCup << std::endl;
	std::cout << pointer << std::endl;
	std::cout << *pointer << std::endl;

	int val = getFirstNum(nums);
	std::cout << val << std::endl;

	int gummyBearCount = 5;
	val = getFirstNum(&gummyBearCount);
	std::cout << (val) << std::endl;

	// Closed
	float floatNums[] = { 0.1f, 1.3f, 2.7f, 3.4f };
	printFloats(floatNums, 4);

	int sum = arraySum(nums, 6);
	std::cout << sum << std::endl;

	bool bools[4] = {};
	initBoolArray(bools, 4, true);
	for (int i = 0; i < 4; i++) {
		std::cout << bools[i] << std::endl;
	}
	

	// Open
	// Get Int Subarray
	int newArr[6] = {};
	getIntSubarray(nums, newArr, 6, 2, 4);
	for (int i = 0; i < 6; i++) {
		// std::cout << newArr[i] << std::endl;
	}

	// Get Pointer to Element
	char letters[5] = { 'g', 'E', 'f', 'l', 'O' };
	char* pntr = getPntrToElement(letters, 5, 'o', false);
	// if(pntr != nullptr)
	if (pntr) {
		// std::cout << *pntr << std::endl;
	}
	else {
		// std::cout << "Null Pointer" << std::endl;
	}
	
	int val1 = 2;
	int val2 = 4;
	int *a = &val1;
	int *b = &val2;
	//std::cout << *a << std::endl;
	//std::cout << *b << std::endl;
	swapPointers(a, b);

	std::cout << "vals" << std::endl;
	std::cout << val1 << std::endl;
	std::cout << val2 << std::endl;

	std::cout << "ptrs" << std::endl;
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	
	// Challenge
	int sumWithout = 0;
	sumWithout = sumWithoutSubscript(nums, 6);
	std::cout << sumWithout << std::endl;

	system("pause");
	return 0;
}