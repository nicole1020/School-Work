#include <iostream>
#include <string>
#include "roster.h"
#include <vector>

using namespace std;

void Roster::parse(string classRosterArray) {

	

	int rhs = classRosterArray.find(",");
	string studentID = classRosterArray.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	string firstName = classRosterArray.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	string lastName = classRosterArray.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	string emailAddress = classRosterArray.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	int age = stoi(classRosterArray.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	int daysInCourse1 = stoi(classRosterArray.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	int daysInCourse2 = stoi(classRosterArray.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	int daysInCourse3 = stoi(classRosterArray.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = classRosterArray.find(",", lhs);
	string degreeProgramList = classRosterArray.substr(lhs, rhs - lhs);
	DegreeProgram degreeProgram = UNDECIDED;
	if (degreeProgramList =="SECURITY") degreeProgram = SECURITY;
	else if (degreeProgramList == "NETWORK") degreeProgram = NETWORK;
	else if (degreeProgramList == "SOFTWARE") degreeProgram = SOFTWARE;
		
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++indexed] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

void Roster::printAll() {

	Student::printHeader();

	for (int i = 0; i <= indexed; i++) {
		classRosterArray[i]->print();
		}
}

void Roster::printByStudentID(string studentID) {
	Student::printHeader();
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printByFirstName(string firstName) {
	Student::printHeader();
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getFirstName() == firstName) classRosterArray[i]->print();
	}
	cout << endl;

}

void Roster::printByLastName(string lastName){
	Student::printHeader();
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getLastName() == lastName) classRosterArray[i]->print();
	}
	cout << endl;

}
void Roster::printByEmailAddress(string emailAddress){
	Student::printHeader();
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getEmail() == emailAddress) classRosterArray[i]->print();
	}
	cout << endl;

}
void Roster::printByAge(int age){
	Student::printHeader();
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getAge() == age) classRosterArray[i]->print();
	}
	cout << endl;

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	Student::printHeader();
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
		}
	cout << endl;
}
void Roster::printAverageDaysInCourses(string studentID) {
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << studentID << "  spent an average of "<<' ';
			cout << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3.0 <<"  days."<<endl;
		}
	}
}

void Roster::printInvalidEmails() {

	for (int i = 0; i <= Roster::indexed; i++) {
		string emailAddress = (classRosterArray[i]->getEmail());
		if ((emailAddress.find('.') == string::npos)) {
			cout << "Student ID " << classRosterArray[i]->getStudentID() << " doesnt have an '.':" << emailAddress << endl;
		}
			
		else if(( emailAddress.find('@') == string::npos)) {

			cout << "Student ID " << classRosterArray[i]->getStudentID() << " doesnt have an '@': " << emailAddress << endl;
		}
		else if (emailAddress.find(' ') != string::npos) {

			cout << "Student ID " << classRosterArray[i]->getStudentID() << " has space(s): " << emailAddress << endl;
		}
	}
}
void Roster::removeStudentByStudentID(string studentID) {
	bool success = false;
	for (int i = 0; i <= indexed; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true;
			if (i < numStudents - 1) {
				Student* placehold = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = placehold;
			}
			indexed--;
		}
	}
	if (success) {
		cout << studentID << " Student removed from database." << endl << endl;
		this->printAll();
	}
	else cout << studentID << " Error-student was not found." << endl << endl;

}


Roster::~Roster(){
	cout << "destructor" << endl << endl;
	for (int i = 0; i < numStudents; i++) {
		cout << "using destructor on student info" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
