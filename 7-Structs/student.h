#pragma once

struct student {
	// student id number
	int id;
	// course number
	int course;
	// last exam score
	int score;
	// major test scores
	// int majorScores[4];
};

void printStudent(student s);

float aveScore(student s[]);

float medScore(student s[]);

int studentsInCourse(student s[], int courseNum);

void sortAsc(int nums[], int size);