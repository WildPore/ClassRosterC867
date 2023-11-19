#include "student.h"

#include <iostream>

// Constructor
Student::Student(std::string studentID, std::string firstName,
                 std::string lastName, std::string emailAddress, int age,
                 int daysInCourse[], DegreeProgram degreeProgram) {
  setStudentID(studentID);
  setFirstName(firstName);
  setLastName(lastName);
  setEmailAddress(emailAddress);
  setAge(age);
  setDaysInCourse(daysInCourse);
  setDegreeProgram(degreeProgram);
}

void Student::print(bool includeStudentID, bool includeFirstName,
                    bool includeLastName, bool includeEmailAddress,
                    bool includeAge, bool includeDaysInCourse,
                    bool includeDegreeProgram) const {
  if (includeStudentID) {
    std::cout << getStudentID() << "\t";
  }

  if (includeFirstName) {
    std::cout << "First Name: " << getFirstName() << "\t";
  }

  if (includeLastName) {
    std::cout << "Last Name: " << getLastName() << "\t";
  }

  if (includeEmailAddress) {
    std::cout << "Email Address: " << getEmailAddress() << "\t";
  }

  if (includeAge) {
    std::cout << "Age: " << getAge() << "\t";
  }

  if (includeDaysInCourse) {
    const int *daysInCourse = getDaysInCourse();
    std::cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1]
              << ", " << daysInCourse[2] << "}\t";
  }

  if (includeDegreeProgram) {
    // Switch statement to print out the degree program,
    // if no degree program is found, print out "Unknown".

    std::cout << "Degree Program: ";
    switch (getDegreeProgram()) {
    case DegreeProgram::SECURITY:
      std::cout << "Security";
      break;

    case DegreeProgram::NETWORK:
      std::cout << "Network";
      break;

    case DegreeProgram::SOFTWARE:
      std::cout << "Software";
      break;

    default:
      std::cout << "Unknown";
      break;
    }

    std::cout << "\t";
  }

  std::cout << std::endl;
}