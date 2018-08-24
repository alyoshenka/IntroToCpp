#include <iostream>
#include "student.h"

// size of array
// Yes, this should not be hard coded I know
int size = 6;

// prints student info
void printStudent(student s) {
	std::cout << "ID: " << s.id << std::endl;
	std::cout << "Course: " << s.course << std::endl;
	std::cout << "Last Score: " << s.score << std::endl;
}

// returns average score
float aveScore(student s[]) {
	int count = 0;
	float total = 0.0f;
	for (int i = 0; i < size; i++) {
		count++;
		total += s[i].score;
	}
	return total / count;
}

// sorts in ascending order
void sortAsc(int nums[], int size) {
	std::cout << "sortAsc" << std::endl;
	int swap = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				swap = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = swap;
			}
		}
	}
}

// returns the median score
// sorts array first
float medScore(student s[]) {

	// sort array first
	// sortAsc(s.score, size);
	int swap = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (s[j].score > s[j + 1].score) {
				swap = s[j].score;
				s[j].score = s[j + 1].score;
				s[j + 1].score = swap;
			}
		}
	}

	float val = 0.0f;
	if (size % 2 == 0) {
		int idx = size / 2;
		val = (s[idx].score + s[idx - 1].score) / 2;
	}
	else {
		val = s[(size - 1) / 2].score;
	}
	return val;
}

// returns number of students in given course
int studentsInCourse(student s[], int courseNum) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (s[i].course == courseNum) {
			count++;
		}
	}
	return count;
}

// returns  largest difference in grades across 
// all students and tests
// Takes the difference between the highest and 
// lowest scores of each individual student and 
// returns the highest
float largestDif(student s[]) {
	// 4 scores
	int scores = 4;
	// max student score
	float max = 0;
	// min student score
	float min = 0;
	// max difference among students
	float maxDif = 0;
	// for all students
	for (int i = 0; i < size; i++) {
		// for all scores
		for (int j = 0; j < 4; j++) {
			if (s[i].majorScores[j] < min) {
				min = s[i].majorScores[j];
			}
		}
	}
}

// returns index of the test with the lowest score
int lowestScoreIdx(student s[]) {
	return 0;
}

// returns average grade across all students,
// weighting final exams to 40% of the final score
float aveGrade(student s[]) {
	return 0;
}

