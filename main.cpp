#include <iostream>

#include "roster.h"

int main() {
  std::cout << "Scripting and Programming - Applications - C867\n";
  std::cout << "Programming language: C++\n";
  std::cout << "Student ID: 011651581\n";
  std::cout << "Name: Lewis Parnell\n\n";

  const std::string studentData[5] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Lewis,Parnell,lparne8@wgu.edu,27,11,22,33,SOFTWARE"};

  Roster *classRoster = new Roster();

  for (const std::string &data : studentData) {
    classRoster->parseStudent(data);
  }

  std::cout << "Printing all students:\n";
  classRoster->printAll();

  std::cout << "Printing invalid emails:\n";
  classRoster->printInvalidEmails();

  std::cout << "Printing average days in course for each student:\n";
  for (const auto &student : classRoster->classRosterArray) {
    classRoster->printAverageDaysInCourse(student->getStudentID());
  }

  std::cout << "\nPrinting students in the Software degree program:\n";
  classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

  std::cout << "Removing student A3.\n\n";
  classRoster->remove("A3");

  std::cout << "Printing all students:\n";
  classRoster->printAll();

  std::cout << "Removing student A3 again, error expected.\n";
  classRoster->remove("A3");

  delete classRoster;

  return 0;
}
