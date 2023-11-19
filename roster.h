#pragma once

#include "student.h"

class Roster {
public:
  const static int ROSTER_SIZE = 5;
  Student *classRosterArray[ROSTER_SIZE] = {nullptr, nullptr, nullptr, nullptr,
                                            nullptr};

  void parseStudent(std::string studentData);

  void add(std::string studentID, std::string firstName, std::string lastName,
           std::string emailAddress, int age, int daysInCourse1,
           int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

  void remove(std::string studentID);

  void printAll() const;

  void printAverageDaysInCourse(std::string studentID) const;

  void printInvalidEmails() const;

  void printByDegreeProgram(DegreeProgram degreeProgram) const;

  Roster();
  ~Roster();
};
