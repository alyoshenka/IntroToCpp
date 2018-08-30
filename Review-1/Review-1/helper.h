#pragma once
#include <iostream>
using namespace std;

struct highScoreData
{
	int highScore;      // player's score at end of the game
	int timeToComplete; // recorded in seconds
};

void multipleChoice();

void printFives(int min, int max);

void candles(int arr[], int s);

void rotateArray(int arr[], int s, int val);

int highestScore(highScoreData scores[], int s);

float aveTime(highScoreData scores[], int s);

void topX(highScoreData scores[], int s, highScoreData highestScores[], int x);

int scoreDif(highScoreData scores[], int n);