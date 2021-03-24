#include <iostream>
#include <string>

#include "roster.h"
#include "student.h"

using namespace std;

int main() {
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_Lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY" ,
        "001336361,Nicole,Mau,nmau@wgu.edu,35,40,30,7,SOFTWARE"
    
    };

    cout << "C867 Performance Assessment JYM1, C++, 001336361, Nicole Mau" << endl;
    cout << endl;

    const int numStudents = 5;
    Roster classRoster;


    for (int i = 0; i < numStudents ; i++) classRoster.parse(studentData[i]);
    cout << "Student roster: " << endl;
    classRoster.printAll();
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Student roster by degree program: " << degreeProgramList[i] << endl;
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }

    cout << endl;
    cout << "Students with invalid email addresses:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    //classRoster->printInvalidEmails();

    cout << "Displaying average days to complete the last 3 courses: " << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourses(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

  
    cout << "Students in the Software Degree Program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing Student with ID A3:" << endl;
    classRoster.removeStudentByStudentID("A3");
    cout << endl;

    classRoster.printAll();
    classRoster.removeStudentByStudentID("A3");


system(" pause > 0 ");
return 0;
}
 