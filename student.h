#pragma once

#include <iostream>
#include <string>

#include "degree.h"

class Student {
private:
  std::string studentID;
  std::string firstName;
  std::string lastName;
  std::string emailAddress;
  int age;
  int daysInCourse[3];
  DegreeProgram degreeProgram;

  void printField(std::string fieldName, std::string fieldValue) const {
    std::cout << fieldName << ": " << fieldValue << "\t";
  };

public:
  std::string getStudentID() const;
  void setStudentID(std::string studentID);

  std::string getFirstName() const;
  void setFirstName(std::string firstName);

  std::string getLastName() const;
  void setLastName(std::string lastName);

  std::string getEmailAddress() const;
  void setEmailAddress(std::string emailAddress);

  int getAge() const;
  void setAge(int age);

  const int *getDaysInCourse() const;
  void setDaysInCourse(int daysInCourse[]);

  DegreeProgram getDegreeProgram() const;
  void setDegreeProgram(DegreeProgram degreeProgram);

  void print(bool includeStudentID, bool includeFirstName, bool includeLastName,
             bool includeEmailAddress, bool includeAge,
             bool includeDaysInCourse, bool includeDegreeProgram) const;

  Student(std::string studentID, std::string firstName, std::string lastName,
          std::string emailAddress, int age, int daysInCourse[],
          DegreeProgram degreeProgram);

  ~Student();
};