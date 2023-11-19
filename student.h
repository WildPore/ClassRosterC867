#pragma once

#include "degree.h"
#include <string>

class Student {
private:
  // D1.
  std::string studentID;
  std::string firstName;
  std::string lastName;
  std::string emailAddress;
  int age;
  int daysInCourse[3];
  DegreeProgram degreeProgram;

public:
  // D2.
  // Inline functions for getters and setters.
  std::string getStudentID() const { return studentID; }
  void setStudentID(std::string studentID) { this->studentID = studentID; };

  std::string getFirstName() const { return firstName; }
  void setFirstName(std::string firstName) { this->firstName = firstName; };

  std::string getLastName() const { return lastName; }
  void setLastName(std::string lastName) { this->lastName = lastName; };

  std::string getEmailAddress() const { return emailAddress; }
  void setEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
  };

  int getAge() const { return age; }
  void setAge(int age) { this->age = age; };

  const int *getDaysInCourse() const { return daysInCourse; }
  void setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; i++) {
      this->daysInCourse[i] = daysInCourse[i];
    }
  };

  DegreeProgram getDegreeProgram() const { return degreeProgram; }
  void setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
  };

  // Print function.
  void print(bool includeStudentID, bool includeFirstName, bool includeLastName,
             bool includeEmailAddress, bool includeAge,
             bool includeDaysInCourse, bool includeDegreeProgram) const;

  // Constructor.
  Student(std::string studentID, std::string firstName, std::string lastName,
          std::string emailAddress, int age, int daysInCourse[],
          DegreeProgram degreeProgram);
};