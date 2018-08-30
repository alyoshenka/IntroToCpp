#include "helper.h"

/*
Create a function that quizzes the user on three
different multiple choice questions for which each
correct answer is worth one point. Choices should
be presented as options A, B, C, and D.

After the user has finished answering all of the
questions, present them with their final score. If
their score is less than perfect, print a message
encouraging them to retry the quiz at a later point
in time.
*/
// Multiple Choice Quiz
void multipleChoice() {

	int score = 0;
	char answer = 'e';

	// Q1
	cout << "Multiple Choice Quiz" << endl;
	cout << "What is the capital of Washington?" << endl;
	cout << "A. Bellevue" << endl;
	cout << "B. Olympia" << endl;
	cout << "C. Seattle" << endl;
	cout << "D. Yakima" << endl;
	cout << "Answer: ";
	cin >> answer;
	if (answer == 'B') {
		score++;
		cout << "Correct" << endl;
	}
	else {
		cout << "Incorrect" << endl;
	}
cout << "Score: " << score << endl;

// Q2
cout << "Which of the following nations" <<
" has the largest population as of 2018?" << endl;
cout << "A. North Korea" << endl;
cout << "B. Luxemborg" << endl;
cout << "C. Denmark" << endl;
cout << "D. Syria" << endl;
cout << "Answer: ";
cin >> answer;
if (answer == 'A') {
	score++;
	cout << "Correct" << endl;
}
else {
	cout << "Incorrect" << endl;
}
cout << "Score: " << score << endl;

// Q3
cout << "Which of the following locations" <<
" does not have an AIE campus?" << endl;
cout << "A. Canberra, Australia" << endl;
cout << "B. Lafayette, Louisana" << endl;
cout << "C. Brisbane, Australia" << endl;
cout << "D. Adelaide, Australia" << endl;
cout << "Answer: ";
cin >> answer;
if (answer == 'C') {
	score++;
	cout << "Correct" << endl;
}
else {
	cout << "Incorrect" << endl;
}
cout << "Score: " << score << endl;

cout << "Final Score: " << score << endl;
if (score < 3) {
	cout << "Try again some other time :(" << endl;
}
else {
	cout << "Nice job! 100%" << endl;
}
cout << endl;
}

/*
Create a function that prints multiples of five
given a multiple to start and end on.
*/
// Multiples of Five
void printFives(int min, int max) {
	for (int i = min; i <= max + 1; i++) {
		cout << 5 * i << endl;
	}
}

/*
In this problem, you are asked to create a
function that will determine the number of
candles that will be blown out. In order for
a candle to be blown out, it must be the same
height or taller than the previous candles.
If the candle is taller, all subsequent candles
much be the same height or taller than that
candle or else they will not be blown out.
*/
// Birthday Cake Candles
void candles(int arr[], int s) {
	for (int i = 0; i < s; i++) {
		if (i == 0) {
			cout << "Candle " << i + 1 <<
				": Blown" << endl;
			// go to next iteration
			continue;
		}
		if (arr[i] >= arr[i - 1]) {
			cout << "Candle " << i + 1 <<
				": Blown" << endl;
		}
		else {
			cout << "Candle " << i + 1 <<
				": Lit" << endl;
		}
	}
}

/*
Create a function that accepts an integer
array whose elements will be rotated about by
given number of indices. Values that are rotated
beyond the bounds of the array should be wrapped
around to the other side of the array.
*/
// Array Rotation
void rotateArray(int arr[], int s, int val) {
	// rotate once
	int last = arr[s - 1];
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < s - 1; i++) {
		temp1 = arr[i];
		temp2 = arr[i + 1];
		arr[i + i] = temp1;
		temp1 = temp2;
	}
	arr[0] = last;
}

// High Score Data

// Given an array of high scores, 
// return the index containing the highest score
int highestScore(highScoreData scores[], int s) {
	int max = INT_MIN;
	for (int i = 0; i < s; i++) {
		if (scores[i].highScore > max) {
			max = scores[i].highScore;
		}
	}
	return max;
}

// Given an array of high scores, return 
// the average time to complete the game
float aveTime(highScoreData scores[], int s) {
	int total = 0;
	float ave = 0.0f;
	for (int i = 0; i < s; i++) {
		total += scores[i].timeToComplete;
	}
	ave = total * 1.0 / s;
	return ave;
}

/*
Given an array of high scores and another array 
of empty high scores, populate the second array 
with the top X number of high score entries

You can assume that the empty array will be large 
enough to hold X entries
*/
void topX(highScoreData scores[], int s, highScoreData highestScores[], int x) {
	// sort
	int swap = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s - 1; j++) {
			if (scores[j].highScore > scores[j + 1].highScore) {
				swap = scores[j].highScore;
				scores[j].highScore = scores[j+1].highScore;
				scores[j+1].highScore = swap;
			}
		}
	}

	// populate
	for (int j = 0; j < x; j++) {
		highestScores[j].highScore = scores[j].highScore;
	}
}

/*
Given an array of high scores, return the difference between 
the score in first place and the score in N th place

You can assume that the array you're searching will be large enough 
to hold at least N entries
*/
int scoreDif(highScoreData scores[], int n){
	int first = scores[0].highScore;
	int nth = scores[n - 1].highScore; // because arrays start at 0
	return nth - first;
}