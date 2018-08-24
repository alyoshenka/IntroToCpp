#pragma once

struct student {
	// student id number
	int id;
	// course number
	int course;
	// last exam score
	int score;
	// major test scores
	float majorScores[4];
};

void printStudent(student s);

float aveScore(student s[]);

float medScore(student s[]);

int studentsInCourse(student s[], int courseNum);

void sortAsc(int nums[], int size);

float largestDif(student s[]);

int lowestScoreIdx(student s[]);

float aveGrade(student s[]);