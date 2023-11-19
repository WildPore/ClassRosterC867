#include "roster.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "degree.h"

Roster::Roster() {}

void Roster::parseStudent(std::string studentData) {
  std::vector<std::string> studentDataVector;
  std::stringstream ss(studentData);

  while (ss.good()) {
    std::string substr;
    getline(ss, substr, ',');
    studentDataVector.push_back(substr);
  }

  DegreeProgram degreeProgram;
  if (studentDataVector[8] == "SOFTWARE") {
    degreeProgram = DegreeProgram::SOFTWARE;
  } else if (studentDataVector[8] == "NETWORK") {
    degreeProgram = DegreeProgram::NETWORK;
  } else if (studentDataVector[8] == "SECURITY") {
    degreeProgram = DegreeProgram::SECURITY;
  } else {
    degreeProgram = DegreeProgram::UNKNOWN;
  }

  add(studentDataVector[0], studentDataVector[1], studentDataVector[2],
      studentDataVector[3], std::stoi(studentDataVector[4]),
      std::stoi(studentDataVector[5]), std::stoi(studentDataVector[6]),
      std::stoi(studentDataVector[7]), degreeProgram);
}

void Roster::add(std::string studentID, std::string firstName,
                 std::string lastName, std::string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram) {
  int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};

  for (int i = 0; i < ROSTER_SIZE; i++) {
    if (classRosterArray[i] == nullptr) {
      classRosterArray[i] =
          new Student(studentID, firstName, lastName, emailAddress, age,
                      daysInCourse, degreeProgram);
      break;
    }
  }
}

void Roster::remove(std::string studentID) {
  bool found = false;
  for (int i = 0; i < ROSTER_SIZE; i++) {
    if (classRosterArray[i] != nullptr &&
        classRosterArray[i]->getStudentID() == studentID) {
      delete classRosterArray[i];
      classRosterArray[i] = nullptr;
      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Error: " << studentID << " not found." << std::endl;
  }
}

void Roster::printAll() const {
  for (int i = 0; i < ROSTER_SIZE; i++) {
    if (classRosterArray[i] != nullptr) {
      classRosterArray[i]->print(true, true, true, false, true, true, true);
    }
  }

  std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
  bool found = false;
  for (int i = 0; i < ROSTER_SIZE; i++) {
    if (classRosterArray[i] != nullptr &&
        classRosterArray[i]->getStudentID() == studentID) {
      const int *daysInCourse = classRosterArray[i]->getDaysInCourse();
      std::cout << "Student ID: " << studentID << " - "
                << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3
                << " average days in course." << std::endl;
      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Error: Student ID not found." << std::endl;
  }

  std::cout << std::endl;
}

void Roster::printInvalidEmails() const {
  for (int i = 0; i < ROSTER_SIZE; i++) {
    if (classRosterArray[i] != nullptr) {
      std::string emailAddress = classRosterArray[i]->getEmailAddress();
      if (emailAddress.find('@') == std::string::npos ||
          emailAddress.find('.') == std::string::npos ||
          emailAddress.find(' ') != std::string::npos) {
        std::cout << emailAddress << std::endl;
      }
    }
  }

  std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
  for (int i = 0; i < ROSTER_SIZE; i++) {
    if (classRosterArray[i] != nullptr &&
        classRosterArray[i]->getDegreeProgram() == degreeProgram) {
      classRosterArray[i]->print(true, true, true, false, true, true, true);
    }
  }

  std::cout << std::endl;
}

Roster::~Roster() {
  for (int i = 0; i < ROSTER_SIZE; i++) {
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
  }
}