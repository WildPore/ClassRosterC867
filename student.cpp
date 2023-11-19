#include "student.h"

#include <iostream>

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

Student::~Student() {}

std::string Student::getStudentID() const { return studentID; }
void Student::setStudentID(std::string studentID) {
  this->studentID = studentID;
}

std::string Student::getFirstName() const { return firstName; }
void Student::setFirstName(std::string firstName) {
  this->firstName = firstName;
}

std::string Student::getLastName() const { return lastName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }

std::string Student::getEmailAddress() const { return emailAddress; }
void Student::setEmailAddress(std::string emailAddress) {
  this->emailAddress = emailAddress;
}

int Student::getAge() const { return age; }
void Student::setAge(int age) { this->age = age; }

const int *Student::getDaysInCourse() const { return daysInCourse; }
void Student::setDaysInCourse(int daysInCourse[]) {
  this->daysInCourse[0] = daysInCourse[0];
  this->daysInCourse[1] = daysInCourse[1];
  this->daysInCourse[2] = daysInCourse[2];
}

DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
  this->degreeProgram = degreeProgram;
}

void Student::print(bool includeStudentID, bool includeFirstName,
                    bool includeLastName, bool includeEmailAddress,
                    bool includeAge, bool includeDaysInCourse,
                    bool includeDegreeProgram) const {
  if (includeStudentID) {
    printField("Student ID", getStudentID());
  }

  if (includeFirstName) {
    printField("First Name", getFirstName());
  }

  if (includeLastName) {
    printField("Last Name", getLastName());
  }

  if (includeEmailAddress) {
    printField("Email Address", getEmailAddress());
  }

  if (includeAge) {
    printField("Age", std::to_string(getAge()));
  }

  if (includeDaysInCourse) {
    const int *days = getDaysInCourse();

    printField("daysInCourse", "{" + std::to_string(days[0]) + ", " +
                                   std::to_string(days[1]) + ", " +
                                   std::to_string(days[2]) + "}");
  }

  if (includeDegreeProgram) {
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

  std::cout << "\n";
}
