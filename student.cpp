#include "student.h"
//#include <cmath>

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECIDED;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}
Student::~Student() {
}

string Student::getStudentID() { return this-> studentID; }
string Student::getFirstName() { return this-> firstName; }
string Student::getLastName() { return this-> lastName; }
string Student::getEmail() { return this-> emailAddress; }
int  Student::getAge() {return this-> age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this-> degreeProgram; }
void Student::setStudentID(string studentID) {  this->studentID = studentID; }
void Student::setFirstName(string firstName) {  this->firstName = firstName; }
void Student::setLastName(string lastName) {  this->lastName = lastName; }
void Student::setEmail(string emailAddress) {  this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysInCourseArray; i++) { this->daysInCourse[i] = daysInCourse[i]; }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader() {
	cout << "Displaying: StudentID|Student Name|Email|Age|DaysInCourse(3)|DegreeProgram";
	cout << "\n" << endl;
}

void Student::print() {
		cout << setw(10);
		cout << this->getStudentID()<< '\t';
		cout << setw(5);
		cout << this->getFirstName() <<'\t';
		cout << setw(10);
		cout << this->getLastName() <<'\t';
		cout << setw(20);
		cout << this->getEmail() <<'\t';
		cout << setw(15);
		cout << this->getAge() <<'\t';
		cout << setw(5);
		cout << this->getDaysInCourse()[0] <<',';
		cout << this->getDaysInCourse()[1] <<',';
		cout << this->getDaysInCourse()[2] <<'\t'<<' ';
		cout << setw(5);		
	    cout << degreeProgramList[this->getDegreeProgram()] <<'\n';
		
		
	}
	
