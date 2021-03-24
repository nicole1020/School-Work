#pragma once
#include "student.h"
using namespace std;
class Roster {
public:
    int indexed = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents]; 
    void parse(string data);
    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void printAll();
    void printByStudentID(string studentID);
    void printByFirstName(string firstName);
    void printByLastName(string lastName);
    void printByEmailAddress(string emailAddress);
    void printByAge(int age);
    void printAverageDaysInCourses(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    void removeStudentByStudentID(string studentID);
    ~Roster();

};