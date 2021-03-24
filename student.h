#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student {
public:
	const static int daysInCourseArray = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArray];
	DegreeProgram degreeProgram;

public:
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
		~Student();

		string getStudentID();
		void setStudentID (string studentID);
	
		string getFirstName();
		void setFirstName(string firstName);
		
		string getLastName();
		void setLastName (string lastName);
		
		string getEmail();
		void setEmail (string emailAddress);
		
		int getAge();
		void setAge(int age);
		
		int* getDaysInCourse();
		void setDaysInCourse (int daysInCourse[]);
		
		DegreeProgram getDegreeProgram();
		void setDegreeProgram (DegreeProgram degreeProgram);
		
		static void printHeader();
		void print();

	
};