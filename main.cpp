#include <iostream>

#include "roster.h"

int main() {
  std::cout << "Scripting and Programming - Applications - C867\n";
  std::cout << "Programming language: C++\n";
  std::cout << "Student ID: 011651581\n";
  std::cout << "Name: Lewis Parnell\n" << std::endl;

  const std::string studentData[5] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Lewis,Parnell,lparne8@wgu.edu,27,11,22,33,SOFTWARE"};

  Roster *classRoster = new Roster();

  for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
    classRoster->parseStudent(studentData[i]);
  }

  classRoster->printAll();
  classRoster->printInvalidEmails();

  for (int i = 0; i < classRoster->ROSTER_SIZE; i++) {
    Student *student = classRoster->classRosterArray[i];
    classRoster->printAverageDaysInCourse(student->getStudentID());
  }

  classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
  classRoster->remove("A3");
  classRoster->printAll();
  classRoster->remove("A3");

  // The destructor would automatically be called on program termination.
  // For the sake of this assignment, I'm calling it explicitly.
  delete classRoster;

  return 0;
}
