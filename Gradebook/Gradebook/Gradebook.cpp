// David Powell project 2

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iomanip>

//using std::cout;
//using std::endl;
//using std::string;
using namespace std;
using namespace System;

//prototypes
void displayAll();
void assignNames();
void assignClassYear();
void assignMajor();
void assignTestScores();
void sortAll();
void findMeans();
void findMedians();
void findModes();
void findStdDevs();
void sortByStdDev();
void saveToFile();

//structure
struct Student {
	string studentName;
	string classYear;
	string major;
	int testScores[10];
	float mean;
	int median;
	float mode;
	float stdDev;

	//struct prototypes
	void sort();
	void calcMean();
	void calcMedian();
	void calcMode();
	void calcStdDev();

};

//make 20 students in array
Student students[20];

//struct functions
//sort the test scores
void Student::sort() {
	int temp;
	for (int i = 0; i < 9; i++){
		for (int j = i + 1; j < 10; j++) {
			if (testScores[i] > testScores[j]) {
				temp = testScores[i];
				testScores[i] = testScores[j];
				testScores[j] = temp;
			}
		}
	}
}

//calculate the mean for each student
void Student::calcMean() {
	float sum = 0;
	
	for (int i = 0; i < 10; i++){
		sum += testScores[i];
	}

	float findMean = sum / 10;
	mean = findMean;
}

//calculate the median for each student
void Student::calcMedian() {
	int calcMedian = (testScores[4] + testScores[5]) / 2;
	median = calcMedian;
}

//calculate the mode for each student
void Student::calcMode() {
	int number = testScores[0];
	int calcMode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i < 10; i++){
		if (testScores[i] == number){
			count++;
		}
		else{
			if (count > countMode){
				countMode = count;
				calcMode = number;
			}
			count = 1;
			number = testScores[i];
		}
	}

	if (countMode == 1){
		float sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += testScores[i];
		}
		float findMean = sum / 10;
		mode = findMean;
	}
	else{
		mode = calcMode;
	}
}

//calculate the standard deviation for each student
void Student::calcStdDev() {
	//subtract the mean from each grade
	int testCopy[10];
	for (int i = 0; i < 10; i++){
		testCopy[i] = (testScores[i] - mean);
	}

	//square the differences and add them up
	float sum = 0.0;
	for (int i = 0; i < 10; i++){
		sum += testCopy[i] * testCopy[i];
	}

	//divide the sum by 10 this is the variance
	float variance = sum / 10;

	//take the square root of the variance to get stdDev
	float cStdDev = sqrt(variance);
	stdDev = cStdDev;
}


int main(){
	assignNames();
	assignClassYear();
	assignMajor();
	assignTestScores();
	sortAll();
	findMeans();
	findMedians();
	findModes();
	findStdDevs();
	sortByStdDev();
	saveToFile();

	displayAll();

	cout << "\n\nHit any key...";
	_getch();
	return 0;
}

//functions
//display all students and their fields
void displayAll() {
	//set decimals
	cout << setprecision(3);

	//set the columns
	cout << left << setw(10) << "NAME" << setw(15) << "CLASS" << setw(20) << "MAJOR" << setw(45) << "TEST SCORES"
		 << setw(10) << "MEAN" << setw(10) << "MEDIAN" << setw(10) << "MODE" << setw(10) << "STD DEV" << endl;

	//put test scores from array into a string for setw
	for (int i = 0; i < 20; i++) {
		string scores = "";
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				scores = scores +  "[" + to_string(students[i].testScores[j]);
			}
			else if (j == 9) {
				scores = scores + ", " + to_string(students[i].testScores[j]) + "]";
			}
			else {
				scores = scores + ", " + to_string(students[i].testScores[j]);
			}
		}

		//display data
		cout << setw(10) << students[i].studentName << setw(15) << students[i].classYear << setw(20) << students[i].major
			 << setw(45) << scores << setw(10) << students[i].mean << setw(10) << students[i].median << setw(10)
			 << students[i].mode << setw(10) << students[i].stdDev << endl;
	}
}

// set the names of all students
void assignNames() {
	students[0].studentName = "Alpha";
	students[1].studentName = "Bravo";
	students[2].studentName = "Charlie";
	students[3].studentName = "Delta";
	students[4].studentName = "Echo";
	students[5].studentName = "Foxtrot";
	students[6].studentName = "Golf";
	students[7].studentName = "Hotel";
	students[8].studentName = "India";
	students[9].studentName = "Juliett";
	students[10].studentName = "Kilo";
	students[11].studentName = "Lima";
	students[12].studentName = "Mike";
	students[13].studentName = "November";
	students[14].studentName = "Oscar";
	students[15].studentName = "Papa";
	students[16].studentName = "Quebec";
	students[17].studentName = "Romeo";
	students[18].studentName = "Sierra";
	students[19].studentName = "Tango";
}

// set the class year of all students
void assignClassYear() {
	students[0].classYear = "Freshman";
	students[1].classYear = "Junior";
	students[2].classYear = "Sophomore";
	students[3].classYear = "Senior";
	students[4].classYear = "Freshman";
	students[5].classYear = "Sophomore";
	students[6].classYear = "Junior";
	students[7].classYear = "Sophomore";
	students[8].classYear = "Freshman";
	students[9].classYear = "Freshman";
	students[10].classYear = "Senior";
	students[11].classYear = "Freshman";
	students[12].classYear = "Freshman";
	students[13].classYear = "Senior";
	students[14].classYear = "Junior";
	students[15].classYear = "Freshman";
	students[16].classYear = "Sophomore";
	students[17].classYear = "Freshman";
	students[18].classYear = "Junior";
	students[19].classYear = "Freshman";
}

// set the majors for all students
void assignMajor() {
	students[0].major = "Liberal Arts";
	students[1].major = "Liberal Arts";
	students[2].major = "Liberal Arts";
	students[3].major = "Liberal Arts";
	students[4].major = "Liberal Arts";
	students[5].major = "General Science";
	students[6].major = "General Science";
	students[7].major = "General Science";
	students[8].major = "General Science";
	students[9].major = "General Science";
	students[10].major = "General Science";
	students[11].major = "General Science";
	students[12].major = "General Science";
	students[13].major = "General Science";
	students[14].major = "General Science";
	students[15].major = "Liberal Arts";
	students[16].major = "Liberal Arts";
	students[17].major = "Liberal Arts";
	students[18].major = "Liberal Arts";
	students[19].major = "Liberal Arts";
}

//set the random test scores for all students
void assignTestScores() {
	int num;
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 10; j++) {
			num = rand() % 101;
			students[i].testScores[j] = num;
		}
	}
}

//sort each set of test scores
void sortAll() {
	for (int i = 0; i < 20; i++) {
		students[i].sort();
	}
}

//find the mean for each student
void findMeans() {
	for (int i = 0; i < 20; i++){
		students[i].calcMean();
	}
}

//find the median for each student
void findMedians() {
	for (int i = 0; i < 20; i++) {
		students[i].calcMedian();
	}
}

//find the modes for each student
void findModes() {
	for (int i = 0; i < 20; i++) {
		students[i].calcMode();
	}
}

//find the starndard deviations for each student
void findStdDevs() {
	for (int i = 0; i < 20; i++) {
		students[i].calcStdDev();
	}
}

//sort students by stdDev
void sortByStdDev() {
	Student temp;
	for (int i = 0; i < 19; i++) {
		for (int j = i + 1; j < 20; j++) {
			if (students[i].stdDev > students[j].stdDev) {
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

//save list to file
void saveToFile() {
	cout << "Saving students list to file..." << endl;
	ofstream myfile;
	myfile.open("ListOfStudents.txt");
	



	//set the columns
	myfile << left << setw(10) << "NAME" << setw(15) << "CLASS" << setw(20) << "MAJOR" << setw(45) << "TEST SCORES"
		<< setw(10) << "MEAN" << setw(10) << "MEDIAN" << setw(10) << "MODE" << setw(10) << "STD DEV" << endl;

	//put test scores from array into a string for setw
	for (int i = 0; i < 20; i++) {
		string scores = "";
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				scores = scores + "[" + to_string(students[i].testScores[j]);
			}
			else if (j == 9) {
				scores = scores + ", " + to_string(students[i].testScores[j]) + "]";
			}
			else {
				scores = scores + ", " + to_string(students[i].testScores[j]);
			}
		}

		//display data
		myfile << setw(10) << students[i].studentName << setw(15) << students[i].classYear << setw(20) << students[i].major
			<< setw(45) << scores << setw(10) << students[i].mean << setw(10) << students[i].median << setw(10)
			<< students[i].mode << setw(10) << students[i].stdDev << endl;
		}


	myfile.close();
	cout << "Save complete." << endl;
}